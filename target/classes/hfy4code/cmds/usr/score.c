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
                if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } else
                return notify_fail("��ֻ���Բ쿴�Լ���״̬��\n"); 
        my = ob->query_entire_dbase(); 
//      line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
 
        line = sprintf( "\n %s\n\n", ob->short(1) );
   line += sprintf(HIR"��"HIY"����������������������"+HIG"������������"HIY"��������������������������"HIR"��\n"NOR);                       
        line += sprintf("\n ������%s"HIG"%s"NOR""HIR"%s"NOR"���%s%s��%s����\n",
                ob->query("unit"),
           (ob->query("national")? ob->query("national") : "������"),
                chinese_number(ob->query("age")), 
                ob->query("gender"),
                ob->query("race"),
                CHINESE_D->chinese_date((int)ob->query("birthday")));
       
   
                if (mapp(my["organization"]))
                {
                        if (my["organization"]["privs"] == 0)
                        {
                                line += sprintf(HIW" ����֯���ơ�%s "HIB"����֯�쵼��%s"NOR,my["organization"]["org_name"],my["organization"]["leader_name"]);
                                if (!my["organization"]["org_title"] || my["organization"]["org_title"] == "��Ա")
                                {
                                        line += " ����ְλ��\n";
                                }else
                                        line += sprintf("��ְ λ��%s\n",my["organization"]["org_title"]);
                        }
                        else
                        {
                                 line += sprintf(HIW" ����֯���ơ�%s "HIB"���Ǹ���֯��%s����"NOR,my["organization"]["org_name"],my["organization"]["privs"]==-1?"":"ǰ��");
                                 if (my["organization"]["org_title"])
                                 { 
                                         line += sprintf("���ų�%s��\n",my["organization"]["org_title"]);
                                 }else
                                         line += "\n";
                        }       
                        
                }else
                        line += " ������֯��ʿ��\n";
                 if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line = sprintf("%s ����ҵ��ʦ��%s\n",
                                line, my["family"]["master_name"] );
        }
        if ( my["marry"] || my["divorced"]) {
                if (my["marry"]) {
                   line +=(ob->query("gender") == "Ů��" ? HIM" ���ɷ�"NOR:HIM" �����ӡ�"NOR)
                                + my["marry_name"]+ "(" + my["marry"] +")��\n";
                        
                }
                else
                        line += HIB" ������״����"NOR + (ob->query("gender") == "Ů��" ? "�Ѿ�":"����")
                                +WHT "�����һ�����"NOR+ chinese_number(my["divorced"]) +" \n";
        }
        else
                line += " ����Ŀǰ��δ���䡿\n";
                 line += sprintf(HIR" ������ɱ¾��"HIC"%s"NOR"�������ɱ¾��"RED"%s"NOR"����������"WHT"%s"NOR"��\n",
                chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]),chinese_number(my["KILLED"]));
                  if (me->query("pkname") !=  0 )
	{
  line += sprintf(WHT" �����������%s(%s)�����ϡ�\n"NOR, ob->query("pkname"),ob->query("pkid"));
     
}  
  
   line += sprintf(HIW"\n ����ʦ��¼��	%d" HIY "\t\t�����д�%d" NOR, ob->query("betrayer"),ob->query("deposit"));     
   line += sprintf(HIC"\n �������ס�	%d" HIM "\t\t������ʹ����%d" NOR,ob->query("gongxian"),ob->query("bigtasks"));
   line += sprintf(HIR"\n ��ץ�����ˡ�	%d" HIG "\t\t����ɱ�����%d" NOR,ob->query("xxxiang"),ob->query("kdadao"));
   line += sprintf(HIY"\n ����ս�콾��	%d" CYN "\t\t��һ��ʹ����%d\n" NOR,sizeof(ob->query("m_killer")),ob->query("TASK"));        
//   line += sprintf(HIR"\n��"HIY"����������������������"+HIM"���������ԡ�"HIY"��������������������������"HIR"��\n"NOR);
                line += sprintf(
                      "\n ������("CYN"int"NOR")��%s\t\t������("CYN"con"NOR")��%s\n"
                        " ������("MAG"spi"NOR")��%s\t\t������("MAG"per"NOR")��%s\n"
                        " ������("CYN"cor"NOR")��%s\t\t������("CYN"str"NOR")��%s\n"
                        " ������("MAG"dur"NOR")��%s\t\t������("MAG"fle"NOR")��%s\n"
                        " ���ٶ�("CYN"agi"NOR")��%s\t\t������("CYN"tol"NOR")��%s\n"
                        " ������("MAG"kar"NOR")��%s\t\t������("MAG"cps"NOR")��%s\n", 

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
       
    line += sprintf(HIY"\n ����ǰ����ֵ��	%d " HIG"\t����������ϵ����%d\n" NOR, COMBAT_D->skill_power(ob, SKILL_USAGE_ATTACK),ob->query("resistance/gin") );
    line += sprintf(HIY" ����ǰ�м�ֵ�� %d " HIG"\t����Ѫ����ϵ����%d\n" NOR, COMBAT_D->skill_power(ob, SKILL_USAGE_PARRY),ob->query("resistance/kee") ); 
    line += sprintf(HIY" ����ǰ����ֵ�� %d " HIG"\t���������ϵ����%d\n" NOR, COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE),ob->query("resistance/sen") );   
        attack_points = COMBAT_D->skill_power(ob, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, SKILL_USAGE_PARRY);
        dodge_points = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE); 
        
        line += sprintf(HIR"\n ���������� %d " HIG "\t\t���������� %d\n" NOR,
                attack_points + 1, 
                (dodge_points/2 + (weapon? parry_points: (parry_points/2))) + 1);
        line +=sprintf(HIR" ��ɱ������ %d	" HIG "\t\t���������� %d\n" NOR,
             ob->query_temp("apply/damage"),ob->query_temp("apply/armor"));     
        line += sprintf(HIB"\n ��������Ʒ��" HIR "%d\t" NOR, ob->query("created_item") );
        line += sprintf("�����췿�䡿" HIR "%d\t" NOR, ob->query("created_room") );         
   line += sprintf(HIM"�� �� �� �㡿 %d\n" NOR, ob->query("gift_points") - 
                                                       ob->query("used_gift_points"));
 
   	line +=sprintf(HIR"\n��"HIY"����������������"+HIY"�����������˿��ղ�칫�ҡ�"HIY"������������������"HIR"��\n"NOR); 
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
ָ���ʽ : score
            
���ָ�������ʾ��Ļ������ϣ� 
 ��ͨ���� С��(Xiaofei) 
 ����һλ�ɹ���ʮ����������࣬�����������ʮһ����ʱ��������
 ���ܹ�ɱ������ˣ������ң���ɱ����Ρ�
 �㵽ĿǰΪֹ�ܹ���������ʹ���� 
 ���ǣ� 10 / 10         ���ʣ� 10 / 10
 ���ԣ� 10 / 10         ������ 10 / 10
 ������ 10 / 10         ������ 20 / 20
 ������  5 /  5         ���ԣ� 20 / 20
 �ٶȣ�  5 /  5         ������ 10 / 10
 ������ 10 / 10         ������ 10 / 10 
 ������Ʒ�� 0           ���췿�䣺 0 
 �������� 3             �������� 3
 ɱ������ 0             �������� 1 
 �� �� �㣺 5  
see also : hp
HELP
    );
    return 1;
}
