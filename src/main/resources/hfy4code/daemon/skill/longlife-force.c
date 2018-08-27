#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "苍生诀");
        set("usage/force", 1);
        set("effective_level", 150);
        set("skill_class", "knight");
        set("learn_bonus", -120);
        set("practice_bonus", -100);
        set("black_white_ness", -20);
}
int practice_skill(object me)
{
        return notify_fail("苍生诀只能用学的，或是从运用(exert)中增加熟练度。\n");
}  
void skill_improved(object me)
{
        int s,diff;
        
        s = me->query_skill("longlife-force", 1);
        diff = (s-80)/20;
        if((int)me->query("age_modify") > -diff && diff > 0) {
			if(me->query("age") < 11)
			{
        tell_object(me, HIG "由於你苦心钻研苍生诀的长生秘诀，你似乎更发年轻了！\n" NOR);
		
			}
			else{
        tell_object(me, HIG "由於你苦心钻研苍生诀的长生秘诀，你显得更发年轻了！\n" NOR);
                me->set("age_modify",-diff);
                me->update_age();
			}
        }
}
