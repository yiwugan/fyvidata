 // quest.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
        
#include <ansi.h>
inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object ob, string arg) {
        int i,nowtime,fail_time;
        object me;
        object* mem;
        nowtime = (int)time();
        fail_time = (int)time();
  if(!arg || !wizardp(ob)) {
                me = this_player();

        if(!me->query("have_mission")) write("������û���κ���֯����\n");
        else {
                string mission;
                mission =  me->query("mission/name");
                write("�����ڵ���֯�����ǹ��ڡ�" + mission+ "����\n");
        nowtime = me->query("mission/mission_time") - (int)time();     //ʣ��ʱ��
        if(nowtime<=0){
                write(NOR"�������Ѿ�û���㹻��ʱ������������֯�����ˡ�\n");
                me->delete("mission");
                me->set("mission_fail",1);
                me->set("mission_wait",fail_time+600);
                me->set("have_mission",0);
                return notify_fail("�����֯�����Զ�ȡ���ˡ�\n");
        }else {time_period(nowtime, me);}
        }
  } 

  else {
         if(!(ob = present(arg, environment(ob))) && !(ob =  find_player(arg))) {
                return notify_fail("��Ҫ�쿴˭����֯����\n");
        }
        if(!ob->query("have_mission")) {
                return notify_fail(ob->name()+"����û���κ���֯����\n");
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
        tell_object(me,"�����֯������" + time + "������\n");
        return 1;
} 
int help(object me) {
        write(@HELP
ָ���ʽ : mission
 
���ָ�������ʾ���㵱ǰ����֯����
HELP);
        return 1;
}    
