 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "�޿�����");
        set("usage/force", 1);
        set("skill_class", "ninja");
        set("learn_bonus", 0);
        set("practice_bonus", -110);
        set("black_white_ness", -20);
}
int practice_skill(object me)
{
        return notify_fail("�޿�����ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}  
void skill_improved(object me)
{
        int s,diff;
        
        s = me->query_skill("ghosty-force", 1);
        diff = (s-100)/10;
       
        if((int)me->query("age_modify") > -diff && diff > 0) {
			 if (me->query("age")< 11) 
        	{
        		tell_object(me, HIG "����޿�������פ����Ч�����ƺ��������ˣ�\n" NOR);
        		//return 1;  
        		} else
        			 {
        tell_object(me, HIG "����޿�������פ����Ч�����Եø��������ˣ�\n" NOR);
                me->set("age_modify",-diff);
              me->update_age();}
              }
/*      if(random(diff) > 10 && me->query("gender") == "����") {
                tell_object(me,"��о�������һ�ȣ���ǰһ�ڣ�\n");
                me->set("gender","Ů��");
                me->unconcious();
        }
*/
} 
int valid_learn(object me)
{
        object ob;
        
        if(!::valid_learn(me)) {
           return 0;
        }
        if (!me->query("tianfeng/done_quest"))
                return notify_fail("���ʮ����δ��Ӧת���������书��\n");
        if (!(int)me->query("tianfeng/ghosty-force")){
                return notify_fail("���ʮ����δ��Ӧ���������书��\n");
        }
        return 1;
} 
