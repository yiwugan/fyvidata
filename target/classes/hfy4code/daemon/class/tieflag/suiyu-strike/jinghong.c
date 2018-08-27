//ximen@sxfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,skill,armor;
        object weapon; 
        skill = me->query_skill("suiyu-strike",1);
        extra = me->query_skill("unarmed") ;
        if (me->query("class")!="tieflag" )
                return notify_fail ("非铁血大旗门宗亲不能使用"RED"［惊鸿］"NOR"绝技。\n");
        if (me->query("family/master_id")!="master yun" && me->query("combat_exp") < 10000000)
                return notify_fail("只有云铮亲传弟子才可以使用"RED"「惊鸿」"NOR"绝技。\n");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                  return notify_fail(NOR"［"RED"惊鸿"NOR"］只能对战斗中的对手使用。\n");
        if ( skill < 130)
                  return notify_fail("你的［碎玉拳法］还不够纯熟！\n"); 
//        if( (int)me->query("kee") >= (int)me->query("max_kee")*3/4)
//        	      return notify_fail("情况还没糟到要使用这招的地步吧？\n");
	if(me->query_skill_mapped("force") == "tiexue-force") extra+=skill;
      if( !me->query_temp("tiexue") )
	{ 
	if( me->query_temp("timer/jinghong") + 8 > time() )
              return notify_fail("你刚使用完［"RED"惊鸿"NOR"］，全身真气紊乱，不能马上再次使用！\n");
	}
                    armor = target->query("resistance/kee");
        		  target->delete_temp("last_damage_from");
			        me->add_temp("apply/attack", extra*4);
			        me->add_temp("apply/damage", extra*5);
                  message_vision(YEL "\n$N长啸声起，浑身散出无边杀气，脚踏奇步往$n欺近！\n"+NOR, me,target);
			        msg =WHT "$n受$N杀气所摄，心胆皆寒，急忙飘身退后。。。\n"NOR;
			        msg +=MAG"\n但$N数步间已赶上飞退的$n，双拳在最短距离内发劲，拳风如千斤铁锤般直捣$n要害！"NOR;
			        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
			        me->add_temp("apply/attack", -extra*4);
			        me->add_temp("apply/damage", -extra*5);
                          if((int)me->query("kee") >= (int)me->query("max_kee")*2/3)
                          me->set_temp("timer/jinghong",time());
                    if( target->query_temp("last_damage_from")  && armor > 0 )
                   {
		            target->set("resistance/kee",0);
                    message_vision(RED"\n$N的拳劲直窜入$n的奇经八脉，$n当下受到不轻的内伤！\n"NOR,me,target);
		            target->receive_damage("kee", armor*skill*2/3, me);
		            target->set("resistance/kee",armor);
		            target->set_temp("damaged_during_attack", 1);
		            COMBAT_D->report_status(target, 0);
		            COMBAT_D->win_lose_check(me,target,1);
//                    target->start_busy(1);
                   }
		me->start_busy(2);
        return 1;
}      
