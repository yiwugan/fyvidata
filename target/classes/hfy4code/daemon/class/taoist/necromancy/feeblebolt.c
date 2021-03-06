 // feeblebolt.c
#include <ansi.h> 
inherit SSERVER; 
int cast(object me, object target)
{
        string msg, target_class;
        int damage, ap, dp,lvl, skill;
        int dam,extradam; 
        if(me->query("class")!="taoist")
                return notify_fail("只有三清宫的弟子才能够使用三清道术。\n"); 
        if((int)me->query_skill("necromancy",1) < 60 )
                return notify_fail("你的法术不够高！\n");
        
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这种法术只能对战斗中的对手使用。\n");
        
        lvl=me->query_skill("necromancy",1); 
        if((int)me->query("mana") < 25)
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 20 )
                return notify_fail("你的精神没有办法有效集中！\n");
        if((int)me->query("mana") < 25+lvl/2)
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 20+lvl/2)
                return notify_fail("你的精神没有办法有效集中！\n");
        
        if (userp(me)) {
                if (lvl<100) {
                        me->add("mana", -25);
                        me->receive_damage("sen", 20);
                } else {
                        me->add("mana", -25-(lvl-100)/5);
                        me->receive_damage("sen", 20+(lvl-100)/5);
                }
        }
        
        if (me->query("mana")<0) me->set("mana",0);
   
        if( random(me->query("max_mana")) < 20 ) {
                write("你失败了。\n");
                return 1;
        }
        
        msg = HIW "$N口中喃喃地念著咒文，左手一挥，手中聚起一团白光射向$n！\n\n" NOR;
        
        skill= me->query_skill("necromancy",1);
        ap = me->query_skill("spells");
        dam = ap;
        ap = ( ap * ap / 10 ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                
                if (skill<=185) {
                        extradam=dam/2;
                        damage = (int)me->query("max_mana") / 8 + random(extradam);
                        if (me->query("max_sen")<2200)  damage+= random(me->query("max_sen")/8);
                                else damage+= random(2200/8); 
                        damage = damage + random(damage); 
//              acerage 618, highest 1100, lowest 175
                } else {
                        damage=dam*2+random(dam*3);
                        if (skill<200) damage=damage*50/100;
                                else damage=damage*60/100;
//              average 700, lowest 400, highest 1000   
//              average 850 lowest 480  highest 1200
                }
//              message_vision("damage is "+(string)(damage),me);
                
                if( skill>=185 ) {
                        msg +=  HIR "结果「嗤」地一声，白光从$p"+HIR"身上透体而过，拖出一条长长的七彩光气，光气绕了\n"
                                        "回转过来又从$N"+HIR"顶门注入$P"+HIR"的体内！\n" NOR;
                        me->receive_heal("sen",target->receive_damage("sen", damage, me)/3);
                        target->receive_wound("sen", damage/3, me);
                } else {
                        msg += "结果「嗤」地一声，白光从$p"+HIR"身上透体而过，无声无息地钻入地下！\n";
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
           }       
                        
        } else
                msg += "但是被$n躲开了。\n"; 
        message_vision(msg, me, target);
        if (damage>0) {
                target->set_temp("damaged_during_attack", 2);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,damage);
        }
        me->start_busy(2);
        return 1;
}     
