#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string  msg;
        object  weapon;
        int skill;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［鬼诛］只能对战斗中的对手使用。\n");
        skill=me->query_skill("snowshade-sword",1);
        if(skill<50)
                return notify_fail("你的雪影剑法修为太差了，无法使用［鬼诛］！");
        if(me->query("class")!="taoist")
                return notify_fail("只有三清宫的弟子才能够使用［鬼诛］。\n");
        
        if( (int) me->query("mana") <skill*3) return notify_fail("你的法力不足。\n");
        
        msg = HIR "$N喝道：魑魅魍魉，接本座一招！\n" NOR;
        if (weapon = me->query_temp("weapon"))
                msg = msg + HIW "$N手中的"NOR+weapon->name()+HIW"脱手飞出，竟凭空化作一道耀眼的光华！\n\n" NOR;
        message_vision(msg, me);
        target->receive_damage("sen", 0, me);
        if(target->is_zombie()==1) {
                me->add("mana", - 100);
                message_vision(HIW "神剑透体而过，无数道异芒从$N身上散射出来！\n" NOR, target);
                target->die();
                return 1;
        } 
        else
                me->add("mana", - skill*3);
                message_vision(HIW "神剑透体而过，$N全身一震，仿佛有点魂不守舍。\n" NOR, target);
		        target->receive_damage("sen", skill*5+random(skill*5), me);
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
        
}        
