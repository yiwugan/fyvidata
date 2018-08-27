 // score.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// combatd.c
// 
// Last modification:
//              - 06/27/2001 by Daniel Q. Yu.
// Last modification:
//              - 02/25/2002 by neon 
#include <ansi.h>
#include <combat.h> 
inherit F_CLEAN_UP; 
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color); 
void create() { seteuid(ROOT_UID); } 
int main(object me, string arg)
{
        object ob;
        mapping my;
        string line, str, skill_type, parry_type;
        object weapon;
        int attack_points, dodge_points, parry_points; 
        seteuid(getuid(me)); 
        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的状态？\n");
        } else
                return notify_fail("你只可以察看自己的状态。\n"); 
        my = ob->query_entire_dbase(); 
//      line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
 
        line = sprintf( "\n %s\n\n", ob->short(1) );
   line += sprintf(HIR"≡"HIY"───────────"+HIG"【江湖履历】"HIY"─────────────"HIR"≡\n"NOR);                       
        line += sprintf("\n 【你是%s"HIG"%s"NOR""HIR"%s"NOR"岁的%s%s，%s生】\n",
                ob->query("unit"),
           (ob->query("national")? ob->query("national") : "本地生"),
                chinese_number(ob->query("age")), 
                ob->query("gender"),
                ob->query("race"),
                CHINESE_D->chinese_date((int)ob->query("birthday")));
       
   
                if (mapp(my["organization"]))
                {
                        if (my["organization"]["privs"] == 0)
                        {
                                line += sprintf(HIW" 【组织名称】%s "HIB"【组织领导】%s"NOR,my["organization"]["org_name"],my["organization"]["leader_name"]);
                                if (!my["organization"]["org_title"] || my["organization"]["org_title"] == "成员")
                                {
                                        line += " 【无职位】\n";
                                }else
                                        line += sprintf("【职 位】%s\n",my["organization"]["org_title"]);
                        }
                        else
                        {
                                 line += sprintf(HIW" 【组织名称】%s "HIB"你是该组织的%s首领"NOR,my["organization"]["org_name"],my["organization"]["privs"]==-1?"":"前任");
                                 if (my["organization"]["org_title"])
                                 { 
                                         line += sprintf("，号称%s。\n",my["organization"]["org_title"]);
                                 }else
                                         line += "\n";
                        }       
                        
                }else
                        line += " 【无组织人士】\n";
                 if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line = sprintf("%s 【授业恩师】%s\n",
                                line, my["family"]["master_name"] );
        }
        if ( my["marry"] || my["divorced"]) {
                if (my["marry"]) {
                   line +=(ob->query("gender") == "女性" ? HIM" 【丈夫】"NOR:HIM" 【妻子】"NOR)
                                + my["marry_name"]+ "(" + my["marry"] +")。\n";
                        
                }
                else
                        line += HIB" 【婚姻状况】"NOR + (ob->query("gender") == "女性" ? "寡居":"鳏居")
                                +WHT "【不幸婚姻】"NOR+ chinese_number(my["divorced"]) +" \n";
        }
        else
                line += " 【你目前尚未婚配】\n";
                 line += sprintf(HIR" 【江湖杀戮】"HIC"%s"NOR"，【玩家杀戮】"RED"%s"NOR"，【殒命】"WHT"%s"NOR"。\n",
                chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]),chinese_number(my["KILLED"]));
                  if (me->query("pkname") !=  0 )
	{
  line += sprintf(WHT" 【你最后死于%s(%s)的手上】\n"NOR, ob->query("pkname"),ob->query("pkid"));
     
}  
  
   line += sprintf(HIW"\n 【判师纪录】	%d" HIY "\t\t【银行存款】%d" NOR, ob->query("betrayer"),ob->query("deposit"));     
   line += sprintf(HIC"\n 【大理贡献】	%d" HIM "\t\t【特殊使命】%d" NOR,ob->query("gongxian"),ob->query("bigtasks"));
   line += sprintf(HIR"\n 【抓捕恶人】	%d" HIG "\t\t【捕杀大盗】%d" NOR,ob->query("xxxiang"),ob->query("kdadao"));
   line += sprintf(HIY"\n 【挑战天骄】	%d" CYN "\t\t【一般使命】%d\n" NOR,sizeof(ob->query("m_killer")),ob->query("TASK"));        
//   line += sprintf(HIR"\n≡"HIY"───────────"+HIM"【个人属性】"HIY"─────────────"HIR"≡\n"NOR);
                line += sprintf(
                      "\n 【才智("CYN"int"NOR")】%s\t\t【体质("CYN"con"NOR")】%s\n"
                        " 【灵性("MAG"spi"NOR")】%s\t\t【魅力("MAG"per"NOR")】%s\n"
                        " 【勇气("CYN"cor"NOR")】%s\t\t【力量("CYN"str"NOR")】%s\n"
                        " 【耐力("MAG"dur"NOR")】%s\t\t【韧性("MAG"fle"NOR")】%s\n"
                        " 【速度("CYN"agi"NOR")】%s\t\t【气量("CYN"tol"NOR")】%s\n"
                        " 【运气("MAG"kar"NOR")】%s\t\t【定力("MAG"cps"NOR")】%s\n", 

                        display_attr(my["int"], ob->query_int()),
                        display_attr(my["con"], ob->query_con()),
                        display_attr(my["spi"], ob->query_spi()),
                        display_attr(my["per"], ob->query_per()),
                        display_attr(my["cor"], ob->query_cor()),
                        display_attr(my["str"], ob->query_str()),
                        display_attr(my["dur"], ob->query_dur()),
                        display_attr(my["fle"], ob->query_fle()),
                        display_attr(my["agi"], ob->query_agi()),
                        display_attr(my["tol"], ob->query_tol()),
                        display_attr(my["kar"], ob->query_kar()),
                        display_attr(my["cps"], ob->query_cps()));
       
    line += sprintf(HIY"\n 【当前攻击值】	%d " HIG"\t【精力防御系数】%d\n" NOR, COMBAT_D->skill_power(ob, SKILL_USAGE_ATTACK),ob->query("resistance/gin") );
    line += sprintf(HIY" 【当前招架值】 %d " HIG"\t【气血防御系数】%d\n" NOR, COMBAT_D->skill_power(ob, SKILL_USAGE_PARRY),ob->query("resistance/kee") ); 
    line += sprintf(HIY" 【当前闪躲值】 %d " HIG"\t【心神防御系数】%d\n" NOR, COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE),ob->query("resistance/sen") );   
        attack_points = COMBAT_D->skill_power(ob, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, SKILL_USAGE_PARRY);
        dodge_points = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE); 
        
        line += sprintf(HIR"\n 【攻击力】 %d " HIG "\t\t【防御力】 %d\n" NOR,
                attack_points + 1, 
                (dodge_points/2 + (weapon? parry_points: (parry_points/2))) + 1);
        line +=sprintf(HIR" 【杀伤力】 %d	" HIG "\t\t【保护力】 %d\n" NOR,
             ob->query_temp("apply/damage"),ob->query_temp("apply/armor"));     
        line += sprintf(HIB"\n 【自造物品】" HIR "%d\t" NOR, ob->query("created_item") );
        line += sprintf("【自造房间】" HIR "%d\t" NOR, ob->query("created_room") );         
   line += sprintf(HIM"【 参 数 点】 %d\n" NOR, ob->query("gift_points") - 
                                                       ob->query("used_gift_points"));
 
   	line +=sprintf(HIR"\n≡"HIY"━━━━━━━━"+HIY"【风云天下人口普查办公室】"HIY"━━━━━━━━━"HIR"≡\n"NOR); 
        write(line);
        return 1;
} 
string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%3d /%3d" NOR, value,gift );
        else if( value < gift ) return sprintf( HIR "%3d /%3d" NOR, value,gift );
        else return sprintf("%3d /%3d", value,gift);
} 
string status_color(int current, int max)
{
        int percent; 
        if( max ) percent = current * 100 / max;
        else percent = 100; 
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
} 
int help(object me)
{
        write(@HELP
指令格式 : score
            
这个指令可以显示你的基本资料： 
 普通百姓 小飞(Xiaofei) 
 你是一位蒙古族十岁的男性人类，甲申年八月三十一日午时三刻生。
 你总共杀了零个人，零个玩家，被杀了零次。
 你到目前为止总共完成了零个使命。 
 才智： 10 / 10         体质： 10 / 10
 灵性： 10 / 10         魅力： 10 / 10
 勇气： 10 / 10         力量： 20 / 20
 耐力：  5 /  5         韧性： 20 / 20
 速度：  5 /  5         气量： 10 / 10
 运气： 10 / 10         定力： 10 / 10 
 自造物品： 0           自造房间： 0 
 攻击力： 3             防御力： 3
 杀伤力： 0             保护力： 1 
 参 数 点： 5  
see also : hp
HELP
    );
    return 1;
}
