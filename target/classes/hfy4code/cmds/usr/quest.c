 // quest.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
        
#include <ansi.h>
inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object ob, string arg) {
        int i, nowtime = time();
        object me;
        object* mem;
        if(!arg || !wizardp(ob)) {
                me = this_player();
        mem = pointerp(me->query_team()) ? me->query_team() : ({ me }); 
        for(i=0; i<sizeof(mem); i++) {
                if (mem[i]) {
                    if (mem[i] != me) {
                        if(mapp(mem[i]->query("quest"))) {
                                mapping quest;
                                quest =  mem[i]->query("quest");
                                tell_object(me, WHT"�����Ա "+ mem[i]->name() + WHT" ���ڵ�������: " + quest["quest_type"] + "��"NOR + quest["quest"] + NOR WHT"����\n"YEL);
                                nowtime = (int)time() - mem[i]->query("task_time");
                                if(nowtime  < 900) {
                                        time_period(nowtime, me);
                                } else 
                                        write(YEL"����"+ mem[i]->name() +"�Ѿ�û���㹻��ʱ����������ˡ�\n"NOR);
                        }
                    }
                }
        }   
    if(!me->query("quest")) {
        if((me->query("next_time")) > time()) {
                    return notify_fail(HIW"��Ҫ��" 
                + QUESTS_D->wait_period(me->query("next_time") - time()) 
                + "֮��ſ�Ҫ����\n"NOR);
        }
        else {
            return notify_fail(NOR"������û���κ�����\n");            
            }
    }
         
        if(mapp(me->query("quest"))) {
                mapping quest;
                quest =  me->query("quest");
                write(NOR"\n�����ڵ�������" + quest["quest_type"] + "��" + quest["quest"] + "����\n");
        } else {
                string quest;
                quest =  me->query("quest");
                write("�����ڵ������ǹ���" + quest+ "��\n");
        }
        nowtime = (int)time() - me->query("task_time");
        if(nowtime  < 900) {
                time_period(nowtime, me);
        } else {
                write(NOR"�������Ѿ�û���㹻��ʱ����������ˡ�\n");
                me->set("quest", 0 );
                return notify_fail("��������Զ�ȡ���ˡ�\n");
        }
        } else {
         if(!(ob = present(arg, environment(ob))) && !(ob =  find_player(arg))) {
                return notify_fail("��Ҫ�쿴˭������\n");
        }
        if(!ob->query("quest")) {
                return notify_fail(ob->name()+"����û���κ�����\n");
        }
        
        if(mapp(ob->query("quest"))) {
                mapping quest;
                quest =  ob->query("quest");
                write(ob->name()+"���ڵ�������" + quest["quest_type"] + "��" + quest["quest"] + "����\n");
        } else {
                string quest;
                quest =  ob->query("quest");
                write(ob->name()+"���ڵ������ǹ���" + quest+ "��\n");
        }
        nowtime = (int)time() - ob->query("task_time");
        if(nowtime  < 900) {
                time_period(nowtime, this_player());
   } else {
                return notify_fail("����"+ob->name()+"�Ѿ�û���㹻��ʱ����������ˡ�\n");
        }
        }       
        return 1;
} 
int time_period(int timep, object me) {
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        
        if(d) time = chinese_number(d) + "��";
        else time = "";
        
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        tell_object(me,"�����Ѿ���ʼ��" + time + "��\n");
        return 1;
} 
int help(object me) {
        write(@HELP
ָ���ʽ : quest
 
���ָ�������ʾ���㵱ǰ������
HELP);
        return 1;
}    
