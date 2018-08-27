#include <ansi.h>
#include <combat.h>
inherit SSERVER;
static string *sym_dee = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" }); 
int perform(object me, object target)
{
        string msg,day;
        int extra,time,damage;
        mixed *local;
        object weapon;
        
        if( me->query("class") != "wolf" )
        	return notify_fail("只有狼山弟子才能使用『天狼噬血』。\n");
        
        extra = me->query_skill("wolf-blade",1);
        
        if ( extra < 151) return notify_fail("你的［天狼噬血刀］还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me);    
        if( !target     
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『天狼噬血』只能对战斗中的对手使用。\n");
        local = NATURE_D->getTime(time());      
        day = sym_dee[local[1]]; 
        if(  day == "戌" || day == "亥" || day == "子"
           ||day == "丑" || day == "寅" || day == "卯"  )
           {
           	damage = extra*3;
           	me->add_temp("apply/damage",extra);
           	me->add_temp("apply/attack",damage);
        	msg = RED "$N突然仰天长嚎，夜色下，依稀可看到$N瞳孔慢慢地由红变绿，手中一道血色的刀光把$n笼罩其中！"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = WHT "天·血红的刀光迅速在空中腾饶！"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = MAG "狼·茫茫夜空下，那光芒聚成一只巨大无比的天狼扑向$n！"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = HIC "噬·天狼露出的利齿在夜月下闪耀着慑人心魄的寒光。"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/damage",-extra);
           	me->add_temp("apply/attack",-damage);
           	if( random(2) )
           	{
           		me->add_temp("apply/damage",2*extra);
           		me->add_temp("apply/attack",2*damage);
           		msg = RED"血·天狼即现！无血不归！"NOR;
        		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        		me->add_temp("apply/damage",-2*extra);
           		me->add_temp("apply/attack",-2*damage);
           		if( target->query_temp("damaged_during_attack") )//没有打中，那么也要伤血
           		{
        			target->receive_wound("kee",random(extra/2)+extra/2);
                        	target->receive_damage("kee",extra+extra/2);
                        	target->set_temp("last_damage_from",me);
                        	COMBAT_D->report_status(target);
                        	COMBAT_D->win_lose_check(me,target,1);
                        }
                }
                else
                {
                	msg = RED"血·血红刀光犹如天狼的利牙一下就到了$n喉咙！"NOR;
                	me->add_temp("apply/damage",2*extra);
           		me->add_temp("apply/attack",2*damage);
        		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        		me->add_temp("apply/damage",-2*extra);
           		me->add_temp("apply/attack",-2*damage);
           	}
        }
        else
        {
        	damage = extra*2;
        	me->add_temp("apply/damage",extra);
           	me->add_temp("apply/attack",damage);
           	msg = RED "$N突然仰天长嚎:-天-狼-噬-血-，手中一道血色的刀芒暴涨，腾空而出的气焰把$n笼罩其中！"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = WHT "血红的刀在空中忽隐忽现，如梦如幻，$n如临梦境！"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = MAG "突然血刀隐没，天空出现一头巨大的天狼扑向$n！"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = HIC "天狼锋利的牙齿闪耀出的光芒让$n不寒而栗！。"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/damage",-extra);
           	me->add_temp("apply/attack",-damage);
           	if( random(2) )
           	{
           		me->add_temp("apply/damage",2*extra);
           		me->add_temp("apply/attack",2*damage);
           		msg = RED"天狼即现！无血不归！"NOR;
        		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        		me->add_temp("apply/damage",-2*extra);
           		me->add_temp("apply/attack",-2*damage);
           		if( target->query_temp("damaged_during_attack") )//没有打中，那么也要伤血
           		{
        			target->receive_wound("kee",random(extra/2)+extra/2);
                        	target->receive_damage("kee",extra+extra/2);
                        	target->set_temp("last_damage_from",me);
                        	COMBAT_D->report_status(target);
                        	COMBAT_D->win_lose_check(me,target,1);
                        }
                }
                else
                {
                	msg = RED"血红刀光犹如天狼的利牙一下就到了$n喉咙！"NOR;
                	me->add_temp("apply/damage",2*extra);
           		me->add_temp("apply/attack",2*damage);
        		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        		me->add_temp("apply/damage",-2*extra);
           		me->add_temp("apply/attack",-2*damage);
           	}
        	
        }
        if( me->query_busy()<4) me->start_busy(4);
        return 1;
}
	