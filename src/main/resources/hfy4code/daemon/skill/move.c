 // move.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "�����Ṧ");
        set("effective_level",          50);
} 
void skill_improved(object me)
{
        int s, t, n; 
        s = me->query_skill("move", 1);
        if( s%10==9 && (int)me->query("agi") < s/5) {
                tell_object(me, HIW "����������Ṧ������ٶ�����ˡ�\n" NOR);
//              me->add("agi", 2);
                me->set("agi",(s+1)/5);
        }
        t = me->query_skill("fengyu-piaoxiang", 1);
		if (s>320 && t>320) {
			n = 1+(t-311)/10;
			if( n > 9 ) n = 9;
			if( me->query("no_busy") < n ) {
			me->set("no_busy",n);
            tell_object(me, HIY "�㳤���غ��˿���������������ɲ�Ǽ䣬����Ṧ������ﵽ�˸��ߵľ��磡����\n" NOR);
			}
		}
}       
