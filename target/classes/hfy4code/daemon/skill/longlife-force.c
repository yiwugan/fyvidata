#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "������");
        set("usage/force", 1);
        set("effective_level", 150);
        set("skill_class", "knight");
        set("learn_bonus", -120);
        set("practice_bonus", -100);
        set("black_white_ness", -20);
}
int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}  
void skill_improved(object me)
{
        int s,diff;
        
        s = me->query_skill("longlife-force", 1);
        diff = (s-80)/20;
        if((int)me->query("age_modify") > -diff && diff > 0) {
			if(me->query("age") < 11)
			{
        tell_object(me, HIG "�����������в������ĳ����ؾ������ƺ����������ˣ�\n" NOR);
		
			}
			else{
        tell_object(me, HIG "�����������в������ĳ����ؾ������Եø��������ˣ�\n" NOR);
                me->set("age_modify",-diff);
                me->update_age();
			}
        }
}
