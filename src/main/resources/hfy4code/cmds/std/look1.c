 // look.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//              - 07/03/2001 by Daniel Q. Yu.
//
// Last modification:
//              - 10/17/2001 by neon
// 
#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <armor.h>
#include <weapon.h>
inherit F_CLEAN_UP; 
int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_corpse(object me, object obj);
int look_room_item(object me, string arg);
string getfigure(object me);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
        BLU "����һ��" NOR,
        BLU "��������" NOR,
        BLU "����ҳ�" NOR,
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "����ͨͨ" NOR,
        HIB "ƽƽ����" NOR,
        HIB "ƽ������" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
   HIB "����С��" NOR,
        HIB "����С��" NOR,
        HIB "�������" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
        CYN "���д��" NOR,
        CYN "���д��" NOR,
        CYN "��Ȼ��ͨ" NOR,
        CYN "�������" NOR,
        CYN "�޿�ƥ��" NOR,
        CYN "����Ⱥ��" NOR,
        CYN "����似" NOR,
        CYN "�����뻯" NOR,
        CYN "����Ⱥ��" NOR,
        HIC "�Ƿ��켫" NOR,
        HIC "��������" NOR,
        HIC "һ����ʦ" NOR,
        HIC "�񹦸���" NOR,
        HIC "������˫" NOR,
        HIC "��������" NOR,
        HIC "������" NOR,
        HIC "��ز�¶" NOR,
        HIR "��ɲ�" NOR
});  
string *female_weight_desc = ({
        MAG "�����е���������" NOR,
        BLU "�Ե���������" NOR,
        CYN "��̬��ӯ" NOR,
        CYN "�������" NOR,
    HIG "�����񻣬��������" NOR,
        HIG "���ǡ���ô�" NOR,
        NOR "���ֲ���" NOR,
        YEL "��̬΢��" NOR,
        YEL "��ķ���" NOR,
        WHT "�Ŀ�����" NOR,
        HIR "�ƺ��ü�����" NOR
});
string *male_strength_desc = ({
        BLU "������������" NOR,
        HIB "�������޸���֮��" NOR,
   CYN "����΢������" NOR,
        CYN "���˾�����������" NOR,
        HIG "���ս�Ӣ��" NOR,
        NOR "���Ĳ��ֲ���" NOR,
        YEL "�ж����������" NOR,
        YEL "����뺷" NOR,
        WHT "�Ŀ�����" NOR,
        HIR "�ƺ��ü�����" NOR
});  
string *heavy_level_desc= ({
        "����",
        "����",
        "����",
        "����",
        "����",
        "����"  
}); 
void create() { seteuid(getuid()); } 
// main function of this command.
int main(object me, string arg) {
        object obj;
        int result; 
        if(!arg) {
                result = look_room(me, environment(me));
        } else if((obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if(obj->is_character()) {
                        if(obj->is_corpse()) result = look_corpse(me, obj);
                        else result = look_living(me, obj);
                        
                } else {
                        result = look_item(me, obj);
                }
        } else {
                result = look_room_item(me, arg);
        }
        
        return result;
} 
// give out room description.
int look_room(object me, object env) {
   int i;
        object *inv;
        mapping exits;
        string roomdesc, str, *dirs; 
        if(!env) {
                write("������ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n");
                return 1;
        } 
        // room descriptions.
        str = sprintf( "%s - %s\n    %s%s",
                        env->query("short"),
                        wizardp(me)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
                                        env->query("coor/y"),env->query("coor/z")): "",
                        env->long(),
                        env->query("outdoors")? NATURE_D->outdoor_room_description() : "" ); 
        // exits.
        if(mapp(exits = env->query("exits"))) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++) {
                        if((int)env->query_door(dirs[i], "status") & DOOR_CLOSED ) {
                                dirs[i] = 0;
                        }
                }
                dirs -= ({ 0 });
                if(sizeof(dirs)==0) {
                        str += "    ����û���κ����Եĳ�·��\n";
                } else if(sizeof(dirs)==1) {
                        str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
                } else {
                        str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + 
                                        " �� " + BOLD + "%s" + NOR + "��\n",
                                        implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
                }
        } else {
                str += "    ����û���κ����Եĳ�·��\n";
        }
        
        // all things in the room.
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
           if(inv[i]==me || inv[i]->query("no_shown") || !me->visible(inv[i])) {
                        continue;
                }
                str += "  " + inv[i]->short() + "\n";
        } 
        write(str);
        return 1;
} 
// give out item description.
int look_item(object me, object obj) {
        mixed *inv;
        string objdesc, prep; 
        write(obj->long());
        inv = all_inventory(obj);
        if(!obj->is_closed() && sizeof(inv)) {
                switch((string)obj->query("prep")) {
                        case "on":
                                prep = "��";
                                break;
                        case "under":
                                prep = "��";
                                break;
                        case "behind":
                                prep = "��";
                                break;
                        case "inside":
                                prep = "��";
                                break;
                        default:
                                prep = "��";
                                break;
                        }
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("%s���У�\n  %s\n", prep,
                        implode(inv, "\n  ") ), me);
        }
        return 1;
} 
// get personality of the person.
string getper(object me, object obj) {
   int per;
        int spi; 
        int weight, score;
        string str; 
        per = obj->query_per();
        spi = me->query_spi();
        score = (int) obj->query("score");
        
        // ���Բ���˿��Ĳ�׼
        if(spi>35) {
                weight = 0;
        } else {
                weight = (int)(35 - spi)/4 ;
        } 
        if(random(10)>6) {
                per = per - weight;
        } else {
                per = per + weight ;
        }
        //ding->query_default_object(), "/obj/specials/ding/ding")== -1) 
        if((string)obj->query("gender") == "����") {
                if (per >= 35) {
                        str = "��ò����,������һ��\n";
                } else if(per >= 30) { 
                        str = "������棬�������ٷ硣\n";
                } else if(per >= 25) { 
                        str = "Ӣ��������ò���˰���\n";
                } else if(per >= 20) {
                        str = "�����������������\n";
                } else if(per >= 15) {
                        str = "��ٶ�����\n";
                } else if(per >= 10) {
                        str = "������ʵ���޷���ά��\n";
                        //str = "��ͷ���ԣ��ܻ�������ӡ�\n";
                } else {
                        str = "��òƽƽ��\n";
                }
        } else if((string)obj->query("gender") == "Ů��") {
                if(per >= 45) {
                        str = HIG"�����Ѿ������ñ�ī���ݣ����֮�����˲��ɻ�ʧ��ᣡ\n"NOR;
           } else if(per >= 40) {
                        str = score > 1000 ? 
                                 "��ۼ���أ������˼����ӣ�\n" 
                                :"���޾��ף���Ŀ�������������ߵ���\n" ;
                } else if(per >= 33) {
                        str = score > 1000 ?  
                                 "�����绨�������鲻�Խ�����������\n"
                                :"���Ľ��ޣ���������ɢ����������ջ�\n";
                } else if(per >= 29) {
                        str = "�г�������֮�ݣ������߻�֮ò��\n";
                } else if(per >= 24) { 
                        str = score > 1000 ?  
                                 "�������ˣ�һ�һЦ�䣬����������Ȼ�Ķ���\n"
                                :"�������ʣ�һ˫�۾��ܻṴ�ˡ�\n";
                } else if(per >= 18) {
                        str = "�������֣��������ˡ�\n"; 
                } else if(per >= 14) {
                        str = "����ɰ�������ϲ�ˡ�\n"; 
                } else if(per >= 10) {
                        str = "��òƽƽ�������ù�ȥ��\n";
                } else {
                        str = "����ò��...�������ɡ�\n";
                }
        } else {
                if (per >= 35) {
                        str = "�ǳ�Ư���ɰ���\n";
                } else if(per >= 30) { 
                        str = "����������Ŀ��\n";
                } else if(per >= 26) {
                        str = "����ͦ����ġ�\n";
                } else if(per >= 15) {
                        str = "������ͷ���Եġ�\n";
                } else {
                        str = "��ģ����,ͦ���˵ġ�\n";
                }
        }
        
        return str;
} 
// use skill_power function to calculate the diff between 2 players.
string gettof(object me, object ob) {
        int melevel, oblevel;
//      melevel = COMBAT_D->skill_power(me, SKILL_USAGE_ATTACK) +
//                      COMBAT_D->skill_power(me, SKILL_USAGE_PARRY) + 
//                      COMBAT_D->skill_power(me, SKILL_USAGE_DODGE);
        
        oblevel = COMBAT_D->skill_power(ob, SKILL_USAGE_ATTACK) +
                        COMBAT_D->skill_power(ob, SKILL_USAGE_PARRY) + 
                        COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE); 
        return  tough_level(oblevel);
} 
// give out character description.
int look_living(object me, object obj) {
        string str, limb_status, pro;
        mixed *inv;
        mapping my_fam, fam,my_org,org; 
        if(me!=obj) {
                message("vision", me->name() + "�������㿴����֪����Щʲ�����⡣\n", obj);
        }
        
        str = obj->long();
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender")); 
        // get age and nationality.
        if((string)obj->query("race")=="����" && intp(obj->query("age"))) {
                if(userp(obj)) {
                        str +=  sprintf("%s��������%s�����%s�ˡ�\n", pro, 
                                        chinese_number(obj->query("age") / 10 * 10), obj->query("national"));
                } else {
                        str += sprintf("%s������Լ%s���ꡣ\n", pro, 
                                        chinese_number(obj->query("age") / 10 * 10));
                }
        }
        
        if(!obj->is_corpse()) {
                // Get personality.
                str += pro + getper(me,obj);
                // Get body figure look .. heeheehee
                if ( (string) obj->query_default_object()== "/adm/daemons/race/human.c") 
                        str += pro + getfigure(obj) +"��";
                
           // Get relative skill level and damage level
                str += "�书����������" + gettof(me,obj) + "��";
                str += "�����ƺ�" + getdam(me,obj) + "��\n";
        }
        
        // If we both has family, check if we have any relations.
        if(obj!=me && mapp(org = obj->query("organization"))
                        && mapp(my_org = me->query("organization"))
                        && org["org_name"] == my_org["org_name"] ) {
                if(org["generation"]==my_org["generation"]){
                	if( org["org_level"] < my_org["org_level"]) {
                		str += pro + "����ͬһ���֣��������˾��\n";
                	} else if ( org["org_level"] > my_org["org_level"] ) {
                		str += pro + "����ͬһ���֣������������\n";
                	} else  str += pro + "����ͬһ���֣�����ְ��һ����\n";
                } else if( org["generation"] < my_org["generation"] ) {
                	if(my_org["leader_name"] == obj->query("name")){
                		str += pro + "��������֯�����졣\n";
                	} else {
                                if( (string)obj->query("gender") == "����" )
                                   {str += pro + "����Ĵ�硣\n";}
                                 else {str += pro + "����Ĵ�㡣\n";}
                	}
                } else{
                	if( (string)obj->query("gender") == "����" )
                	   {str += pro + "������ֵܡ�\n";}
                	else {str += pro + "�����С�á�\n";}
                }
        }
                     	
        if(obj!=me && mapp(fam = obj->query("family")) 
                        && mapp(my_fam = me->query("family")) 
                        && fam["family_name"] == my_fam["family_name"] ) {
                if(fam["generation"]==my_fam["generation"]) {
                        if((string)obj->query("gender") == "����") {
                                str += sprintf( pro + "�����%s%s��\n",
                                                my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                                my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        } else {
                                str += sprintf( pro + "�����%s%s��\n",
                                                my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                                my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        }
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if(my_fam["master_id"] == obj->query("id")) {
                                str += pro + "�����ʦ����\n";
                        } else if(my_fam["generation"] - fam["generation"] > 1) {
                                str += pro + "�����ͬ�ų�����\n";
                        } else if(fam["enter_time"] < my_fam["enter_time"]) {
                                str += pro + "�����ʦ����\n";
                        } else {
                                str += pro + "�����ʦ�塣\n";
                        }
                } else {
                        if(fam["generation"] - my_fam["generation"] > 1) {
                                str += pro + "�����ͬ������\n";
                        } else if(fam["master_id"] == me->query("id")) {
                                str += pro + "����ĵ��ӡ�\n";
                        } else {
                                str += pro + "�����ʦֶ��\n";
                        }
                }
        } 
        // current kee status.
   if(obj->query("max_kee")) {
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 
                                / (int)obj->query("max_kee")) + "\n";
        }
        
        // inventory message.
        if(obj->query("race") == "����") {
                str += pro + (obj->is_naked() ? "�������塣\n" : "");
        }
        inv = all_inventory(obj);
        if(sizeof(inv)) {
                inv = map_array(inv, "inventory_look", this_object(), (obj == me || obj->is_corpse()) ? 0 : 1 );
                inv -= ({ 0 });
                if(sizeof(inv)) {
                        str += sprintf("%s\n", implode(inv, "\n  "));
                }
        }
        
        // send out message
        message("vision", str + "\n", me); 
        // reaction from look at other person.
        if(obj!=me  && living(obj) 
                        && random((int)obj->query("bellicosity")/10) > (int)me->query_per()) {
                write(obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
        } 
        return 1;
} 
// give out corpse description.
int look_corpse(object me, object obj) {
        string str, limb_status, pro;
        mixed *inv;
        mapping my_fam, fam; 
        if(me!=obj) {
                message("vision", me->name() + "�������㿴����֪����Щʲ�����⡣\n", obj);
        }
        
        str = obj->long();
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender")); 
        // Give the corpse looking.
   str +=  sprintf("%s����ò��... ���Ѿ����ˣ�����ʲô�ÿ��ģ�\n", pro);  
        inv = all_inventory(obj);
        if(sizeof(inv)) {
                inv = map_array(inv, "inventory_look", this_object(), (obj == me || obj->is_corpse()) ? 0 : 1 );
                inv -= ({ 0 });
                if(sizeof(inv)) {
                        str += sprintf("�������У�\n");
                        str += sprintf("%s\n", implode(inv, "\n  "));
                }
        }
        else str += sprintf("������ʲô��û�С�"); 
        // send out message
        message("vision", str + "\n", me);
        return 1;
}  
// inventory messages.
string inventory_look(object obj, int flag) {
        string str, desc;
        object me, left, right; 
        str = obj->short();
        if(obj->query("equipped")) {
                if(!desc = obj->query("armor_worn")) {
                        if(!desc=obj->query("weapon_wielded")) {
                                desc = "��";
                        } else {
                                me = environment(obj);
                                left = me->query_temp("left_hand");
                                right = me->query_temp("right_hand");
                                if(obj == left && obj == right) {
                                        desc = "˫��" + desc + "��";
                                } else if(obj == right) {
                                        desc = "����" + desc + "��";
                                } else {
                                        desc = "����" + desc + "��";
                                }
                        }
                }
                str = desc + str;
        } else if(!flag) {
                str = (environment(obj)->is_character() && !environment(obj)->is_corpse() ? 
                           "����" : "  ") + str;
        } else {
                return 0;
        }
        
        return str;
} 
int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits; 
        if( !objectp(env = environment(me)) )
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲ��Ҳû�С�\n"); 
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                        
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("��Ҫ��ʲ�᣿\n");
} 
// return power level.
string tough_level(int power) {
        int lvl;
        
        if(power <= 1) {
                lvl = 0;
        } else { 
                lvl = pow(power, 0.25);
   }
        if(lvl >= sizeof(tough_level_desc)) {
                lvl = sizeof(tough_level_desc)-1;
        } else if(lvl < 0) {
                lvl = 0;
        } 
        return tough_level_desc[lvl];
} 
string getdam(object me, object obj) {  
        int str, level, max_str, max_level;
        
        max_str = 100;
        max_level = sizeof(heavy_level_desc) - 1;
        
        str = obj->query_str();
        level = str * max_level / max_str;
        level = level > max_level ? max_level : level; 
        
        return heavy_level_desc[level];
} 
string getfigure(object me) {   
        int str, ruler, level, exp, agi;
        exp =(int) me->query("combat_exp");
        str = me->query("str");
        agi = me->query("agi");
        if (me->query("gender")=="Ů��") {
            str = str>50 ? 25 + str/2 : str;
            str = str >25 ? str*10/(agi+1) + 20 : str;
            ruler = sizeof(female_weight_desc)-1;
            level = str >120 ? ruler : ( str/5 - str*str/1440) ;
            level = level > ruler ? ruler : level; 
            return female_weight_desc[level];
        }
        else {
            str = str>60 ? 30 + str/3 : str;
            str = str >30 ? str*10/(agi+1) + 20 : str;
            ruler = sizeof(male_strength_desc)-1;
            level = str >120 ? ruler : ( str/6 - str*str/1440) ;
            level = level > ruler ? ruler : level; 
            return male_strength_desc[level];
   }
}  
int help (object me) {
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
        return 1;
}   
