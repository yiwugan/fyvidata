 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i, bonus, exp_bonus;
        
        object weapon, *enemy;
        
/*      
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［天下无狗］只能对战斗中的对手使用。\n");
*/
        if((int)me->query_skill("dagou-stick",1) < 120 && userp(me))
                return notify_fail("你的打狗棒法还不够熟练！\n");        
        enemy=me->query_enemy();
        if(!sizeof(enemy))
                return notify_fail("［天下无狗］只能对战斗中的对手使用。\n");
        if(target)
                return notify_fail("这个绝招不需要指定使用对象！！\n");
                
        weapon = me->query_temp("weapon"); 
        extra = me->query_skill("dagou-stick");
        bonus = 0;
        if (extra>150 && me->query("class")== "beggar") bonus= extra*3; 
        me->add_temp("apply/attack", extra);  
        me->add_temp("apply/damage", extra+bonus);
        msg = HIY  "\n\n$N"+HIY"低喝一声［"+HIR"天—下—无—狗"+HIY"］！\n"+HIW"$N"+HIW"内力骤然凝聚，"+
weapon->name() +
HIW"化成满天棍影，铺天盖地散向在场每一个人！\n" NOR;
        message_vision(msg,me);
        for(i=0;i<sizeof(enemy);i++)
        {
                msg=HIY"$N"+HIY"手中的$w"+HIY"直取$n"+HIY"的$l！！"NOR;
                me->set_temp("dagou/pfm",1);
           COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
                me->delete_temp("dagou/pfm",1);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra-bonus);
        if (me->query_busy()<2) 
                me->start_busy(2);
        return 1;
}  
