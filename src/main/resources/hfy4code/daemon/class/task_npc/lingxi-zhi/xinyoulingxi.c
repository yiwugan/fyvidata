#include <ansi.h>
inherit SSERVER;
void remove_effect(object me);
int perform(object me, object target)
{
        int skill;
//              if (!me->query("marks/悟出灵犀")&& userp(me))
//                      return notify_fail (HIG"你还未能悟出“心有灵犀”。\n"NOR);
                
/*              if (target==me) return notify_fail("“心有灵犀”只能对对手使用。\n");
                if (!target) target=offensive_target(me);
                if (!target||!target->is_character()||!me->is_fighting(target))
                        return notify_fail("“心有灵犀”只能对战斗中的对手使用。\n");*/
        skill=me->query_skill("lingxi-zhi",1);
        if (skill<160 && userp(me))
                return notify_fail("“心有灵犀”需要160级灵犀指法。\n");
        if (me->query_temp("xinyoulingxi"))
                        return notify_fail("你已经在施展“心有灵犀”了。\n");
                
        tell_object(me,HIW"你的脑海中豁然一片空明，对方一举一动无不被你算中。\n"NOR);
                me->set_temp("xinyoulingxi", 1); 
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me 
 :), 10); 
        if (me->is_fighting()) me->start_busy(2);
        return 1;
} 
void remove_effect(object me)
{
        me->delete_temp("xinyoulingxi");
        tell_object(me, "你“心有灵犀”的功效已经过去了。\n");
}
     
