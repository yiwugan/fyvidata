#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("qiankun-shan",1) ;
        if ( extra < 50) return notify_fail("你的乾坤风流扇不够纯熟！\n");
        if(me->query_skill("qiankunstrike",1)> 1)    extra = extra *5;
              //    if( me->query_temp("parryup") ) extra = random(extra)*2+extra;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［风流犹拍古人肩］只能对战斗中的对手使用。\n");
               // me->set_temp("14sword",1);
        {
        me->add_temp("apply/attack", extra*5);
        me->add_temp("apply/damage", extra*5);
        msg = HIC"$N突然哈哈大笑，刀势一转，口中吟道「别人笑我太疯癫，我笑别人看不穿。。。」 \n"
        HIC "只见这随意的一招，刀气纵横交错，扑面而来！！！ \n"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*5);
        me->add_temp("apply/damage", -extra*5);
        if (me->query_busy()<2) me->start_busy(2);
                //me->set_temp("14sword",0);
        }
        return 1;
}      
