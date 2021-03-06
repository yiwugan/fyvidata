 // superbolt.c
#include <ansi.h> 
inherit SSERVER; 
int cast(object me, object target)
{
        string msg;
        int damage, ap, dp,lvl;
        int extradam; 
        if(me->query("class")!="taoist")
                return notify_fail("只有叁清宫的弟子才能够使用叁清道术。\n"); 
//        if(!me->query("open_sesame") )
//                return notify_fail("你的叁清道术还不能神气合一。\n");  
        if((int)me->query_skill("necromancy") < 180 )
                return notify_fail("你的叁清道术不够高！\n"); 
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
        
        if (lvl<100) {
                me->add("mana", -25);
                me->receive_damage("sen", 20);
        } else {
                me->add("mana", -25-(lvl-100)/2);
                me->receive_damage("sen", 20+(lvl-100)/2);
        }
        if (me->query("mana")<0) me->set("mana",0);
        
        if( random(me->query("max_mana")) < 20 ) {
           write("你失败了。\n");
                return 1;
        }
        msg = HIG "$N口中喃喃地念着咒文，左手一挥，手中聚起五色光芒，霎时化为叁股！\n\n";
        msg += HIC "一团青光射向$n！\n" NOR; 
        ap = me->query_skill("necromancy");
        extradam = ap/2;
        ap = (  ap * ap /10  ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 4 + random(extradam*5);
                if (me->query("max_sen")<3000)  damage+= random(me->query("max_sen")/8);
                        else damage+= random(3000/8);
                damage = damage + random(damage);       
                if (lvl> 130 && me->query("combat_exp")<target->query("combat_exp")*3/4)
                        damage = damage*(me->query("combat_exp")/100)/(target->query("combat_exp")/100);        
                if( damage > 0 ) {              
                        msg +=  HIR "结果「嗤」地一声，青光从$p身上透体而过，拖出一条长长的黑气钻入地下！\n"NOR;
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/3, me);
                } else
                        msg += "结果「嗤」地一声，青光从$p身上透体而过，无声无息地钻入地下！\n";
        } else
                msg += "但是被$n躲开了。\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
            COMBAT_D->win_lose_check(me,target,damage);
        } 
        msg = HIW "\n一团白光射向$n！\n" NOR; 
        ap = me->query_skill("necromancy");
        extradam = ap/2;
        ap = ( ap * ap / 10 ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 8 + random(extradam*3);
                if (me->query("max_sen")<2200)  damage+= random(me->query("max_sen")/8);
                        else damage+= random(2200/8); 
                damage = damage + random(damage);
           
                if( damage > 0 ) {
                        msg +=  HIR "结果「嗤」地一声，白光从$p身上透体而过，拖出一条长长的黑气钻入地下！\n"NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                } else
                        msg += "结果「嗤」地一声，白光从$p身上透体而过，无声无息地钻入地下！\n";
        } else
                msg += "但是被$n躲开了。\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
           COMBAT_D->win_lose_check(me,target,damage);
        } 
        msg = HIM "\n一团紫光射向$n！\n" NOR; 
        ap = me->query_skill("necromancy");
        extradam = ap/2;
        ap = ( ap * ap / 10 ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 8 + random(extradam*3);
                if (me->query("max_sen")<2200)  damage+= random(me->query("max_sen")/8);
                        else damage+= random(2200/8);
                damage = damage + random(damage); 
                
                if( damage > 0 ) {
                        msg +=  HIR "结果「嗤」地一声，紫光从$p身上透体而过，拖出一条长长的七彩光气，光气绕了\n"
                                        "回转过来又从$N顶门注入$P的体内！\n" NOR;
                        me->receive_heal("gin", target->receive_damage("gin", damage, me));
                        target->receive_wound("gin", damage/3, me);
                } else
                        msg += "结果「嗤」地一声，紫光从$p身上透体而过，无声无息地钻入地下！\n";
        } else
                msg += "但是被$n躲开了。\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
           COMBAT_D->win_lose_check(me,target,damage);
        } 
        me->start_busy(2);
        return 1;
}       
