 // who.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//              - 07/13/2001 by Daniel Q. Yu.
//
#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
inherit F_CLEAN_UP; 
int sort_user(object,object);
int help(); 
private void create() { 
        seteuid(getuid()); 
} 
mixed main(object me, string arg, int remote) {
        string name, str, rule, *option;
        object *list, *ob, ob1;
        int i, opt_long,opt_number, numPlayer;
        
        if(remote && sizeof(arg)<2) arg="";
        ob = filter_array(children(USER_OB),(: userp :));
        ob = filter_array(ob, (: environment($1) :));
        ob = filter_array(ob, (: $2->visible($1) :), me);
        numPlayer = sizeof(ob);
        str = HIY"\n����� ��"+ MUD_NAME+"��"HIW"Ŀǰ";
        rule = "";
        if(arg) {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- ) {
                        switch(option[i]) {
                                case "-h": 
                                        return help();
                                case "-l": 
                                        opt_long = 1;
                                        break;
/*                                case "-w": 
                                   rule += "��ʦ";
                                        ob = filter_array(ob, (: wizardp($1) || wizhood($1) == "(immortal)" :));
                                        break;*/
                                case "-p": 
                                        if(me->query("family/family_name")) {
                                                rule += me->query("family/family_name");
                                        } else {
                                                rule += "��ͨ����";
                                        }
                                        ob = filter_array(ob, (: $1->query("family/family_name") == $2->query("family/family_name") :), me);
                                        break;
                                case "-f": 
                                        rule += "Ů��";
                                        ob = filter_array(ob, (: $1->query("gender") =="Ů��" :));
                                        break;
                                case "-m": 
                                        rule += "����";
                                        ob = filter_array(ob, (: $1->query("gender") == "����" :));
                                        break;
                                case "-a": 
                                        opt_number = 1;
                                        break;
                                case "-d": 
                                        rule += "����";
                                        ob = filter_array(ob, (: $1->query_temp("netdead") :));
                                        break;
                                default:
                                        if(option[i][0]=='@'){
                                        RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
                                        write("��·ѶϢ���ͳ������Ժ�\n");
                                        return 1;
                                        }
                                        ob1 = present(option[i], environment(me));
                                        if(!ob1) {
                                                ob1 = find_player(option[i]);
                                        }
                                        if(!ob1) {
                                                ob1 = find_living(option[i]);
                                        }
                                        if((!ob1) && (option[i] =="me")) {
                                           ob1=me;
                                        }
                                        if(!ob1) {
                                                return notify_fail("û�������һ��������\nָ���ʽ : who [-h] [-l] [-p] [-f] [-m] [-a] [-d][<ID>]\n");
                                        }
                                        me = ob1; 
                                        if(me->query("family/family_name")) {
                                                rule += me->query("family/family_name");
                                        } else {
                                                rule += "��ͨ����";
                                        }
                                        ob = filter_array(ob, (: $1->query("family/family_name") == $2->query("family/family_name") :), me);
                                }
                        }
                }
                str += rule + "����У�";
        str += HIY"\n������������������������������������������������������������������������\n"NOR;      
        list = sort_array(ob,"sort_user");
        if(!sizeof(list)) {
                str = "Ŀǰ��Ϸ�в�û��" + rule + "��ҡ�\n";
        } else if(opt_number) {
                str = HIY"��"+ MUD_NAME+"��"NOR + WHT"Ŀǰ����"+chinese_number(sizeof(ob))+ "λ" + rule + "��ҡ�\n";
                } else if(opt_long) {
                        i = sizeof(list);
                        while(i--) {
                                str += sprintf("%s%s%s%s\n",
                                                interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                                list[i]->is_ghost() ? HIB"@"NOR : " ",
                                                list[i]->query("gender") == "Ů��" ? HIM "��"NOR :HIC "��" NOR,
                                                list[i]->short(1)
                                );
                        }
                str += HIY"������������������������������������������������������������������������\n"NOR;
                str += sprintf("����%sλʹ���������У�ϵͳ������%s\n\n", 
                                CHINESE_D->chinese_number(numPlayer), query_load_average());
        } else {
                        i = sizeof(list);
                        while(i--){
                                str += sprintf("%s%s%s%-20s ", 
                                                interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                           list[i]->is_ghost() ? HIB"@"NOR : " ",
                                                list[i]->query("gender") == "Ů��" ? HIM "��"NOR :HIC "��" NOR,
                                                sprintf("%s(%s)", list[i]->name(1), capitalize(list[i]->query("id"))));
                                if(i%3 == sizeof(list)%3) {
                                        str += "\n";
                                }
                        }
                        if(sizeof(list)%3) {
                                str += "\n";
                }
                str += HIY"������������������������������������������������������������������������\n"NOR;
                str += sprintf("����%sλʹ���������У�ϵͳ������%s\n\n", 
                                CHINESE_D->chinese_number(numPlayer), query_load_average());
        }
        if(remote) {
                return str;
        } else {
                me->start_more("", str, 0);
                }
        return 1;
} 
int sort_user(object ob1, object ob2) {
        string name1, name2;
        if(wiz_level(ob1) != wiz_level(ob2)) {
                return wiz_level(ob2) - wiz_level(ob1);
        }
        name1 = ob1->query("family/family_name");
        name2 = ob2->query("family/family_name");
        if(intp(name1)) {
                name1 = "";
        }
        if(intp(name2)) {
                name2 = "";
        }
        if(name1 > name2) {
                return -1;
        }
        if(name1 < name2) {
                return 1;
        }
   return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");
} 
int help() {
        write(" 
ָ���ʽ : who [-h] [-l] [-p] [-f] [-m] [-a] [-d] [<ID>] 
���ָ������г���������Ϸ�е���Ҽ���ȼ��� 
-h �г�������Ļ��
-l ѡ���г��ϳ���ѶϢ��
-p ֻ�г�ͬ���ɵ���ҡ�

-f ֻ�г���Ϸ�е�Ů��ҡ�
-m ֻ�г���Ϸ�е�����ҡ�
-a ֻ�г���ǰ��Ϸ����ҵ���������
-d ֻ�г���ǰ��Ϸ�д��ڶ���״̬�е���ҡ� 
<ID> �г�<ID>��������������ɵ���ҡ� 
"HIG"*"NOR" ��ʾ"HIG"����"NOR"�У�"HIR"#"NOR" ��ʾ"HIR"����"NOR"�У�"HIB"@"NOR" ��ʾ"HIB"����"NOR"�С� 
���ָ� finger \n\n");
        return 1;
}     
