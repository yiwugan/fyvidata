 // iceforce.c2
inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name", "���ľ�");
        set("usage/force", 1);
        set("effective_level", 100);
        set("learn_bonus", 0);
        set("practice_bonus", -10);
        set("black_white_ness", 10);
        set("skill_class", "yinshi");
}        

void skill_improved(object me)
{
        int s; 
        s = me->query_skill("iceheart", 1);
        if( s == 151) {
        	    tell_object(me, HIW"����һ���о�����Ա��ľ�����һЩ�µ���ʶ���ƺ���Ҫȥ���������\n" NOR);
              if (me->query("family/master_id") == "master lan" || me->query("marks/master_lan") )me->set("marks/iceheart",1);
        }
        if( s == 200) {
          tell_object(me, HIW"�����ڰѱ��ľ��������۷徳�硣\n" NOR);
        }
}

int effective_level()
{
        object me=this_player();
        int skill,n;
        skill=me->query_skill("iceheart",1);
        if( skill < 221) return 100;
        if( skill > 220) return 150;
                     
}  
