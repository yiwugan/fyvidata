//ximen@sxfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg,weapon_name;
        int myexp,yourexp,mystr,yourstr,extra,skill,armor;
        object weapon; 
        skill = me->query_skill("suiyu-strike",1);
        extra = me->query_skill("unarmed") ;
        if (me->query("class")!="tieflag"  )
                return notify_fail ("非铁血大旗门宗亲不能使用"WHT"［破兵］"NOR"绝技。\n");
        if (me->query("family/master_id")!="master yun" && me->query("combat_exp") < 10000000)
                return notify_fail("只有云铮亲传弟子才可以使用［"WHT"破兵"NOR"］绝技。\n");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                  return notify_fail("［"WHT"破兵"NOR"］只能对战斗中的对手使用。\n");
        if ( skill < 80)
                  return notify_fail("你的［碎玉拳法］还不够纯熟！\n"); 
        weapon = target->query_temp("weapon");
        myexp = (int) me->query("combat_exp") / 1000;
        if(me->query_temp("tiexue"))myexp*=3/2;
	if(me->query_skill_mapped("force") != "tiexue-force") myexp*=2/3;
        mystr = (int) me->query_str();
        yourexp = (int) target->query("combat_exp") / 1000;
        yourstr = (int) target->query_str();
	  target->delete_temp("last_damage_from");
        if ( objectp(weapon) )
        {
              weapon_name = weapon->query("name");
              message_vision(MAG "\n$N瞬间捕捉到$n手中"NOR+weapon_name+MAG"舞动的轨迹，右拳全力猛地击出。\n\n"+NOR, me,target);
              if (( (myexp + random(myexp)) * mystr ) > (yourexp * yourstr) )
              {
                   message_vision(HIY "$n只觉$N霸道的拳劲袭来，虎口剧痛之下，手中"NOR+weapon_name+HIY"被震得脱手飞出！\n"+NOR,me,target);
                   weapon->unequip();
                   target->start_busy(2);
                   armor = target->query_skill("iron-cloth");
                   me->add_temp("apply/attack", extra*2);
                   me->add_temp("apply/damage", extra*2);
                   msg = HIR"$N趁$n阵脚未稳，左拳探出，迅捷无比地直击其空门！"NOR;
                   COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                    if( target->query_temp("last_damage_from") && armor >0)
                    {
                    message_vision(BLU"\n$N刚猛的内劲冲破$n的护体神功，如洪水般侵入$n的经脉！\n"NOR,me,target);
				    target->receive_damage("kee", armor*skill/80, me);
                    }
                   me->add_temp("apply/attack", -extra*2);
                   me->add_temp("apply/damage", -extra*2);
                   me->start_busy(3);
                   weapon->move(environment(target));
                   message_vision(CYN "\n“当”的一声，"NOR+weapon_name+CYN"在空中翻转数圈后，最终落于地上。\n"+NOR,me,target);
              }
			        else 
			        {
						        message_vision(HIR "$n只觉得虎口一麻，手中"+weapon_name+"险些脱手，$N这全力一拳竟无功而返！\n" NOR,me,target);
						        if(me->query_busy()<3) me->start_busy(3);
						        COMBAT_D->do_attack(target,me, TYPE_PERFORM);
			        }
        }
        else
        {
                          armor = target->query_skill("iron-cloth");
			        me->add_temp("apply/attack", extra*3);
			        me->add_temp("apply/damage", extra*5);
			        msg = HIR"$N大喝一声：“阁下无兵可破，且接我此招！”双拳齐出，直往$n胸口攻至！\n\n"NOR+HIY "$N霸道的拳劲涌入，“砰”的一声，$n竟被震得倒退两步！"NOR;
			        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
			        me->add_temp("apply/attack", -extra*3);
			        me->add_temp("apply/damage", -extra*5);
                    if( target->query_temp("last_damage_from") && armor > 0 )
                    {
                    message_vision(BLU"\n$N刚猛的内劲冲破$n的护体神功，如洪水般侵入$n的经脉！\n"NOR,me,target);
				    target->receive_damage("kee", armor*skill/6, me);
				    target->set_temp("damaged_during_attack", 1);
				    COMBAT_D->report_status(target, 0);
				    COMBAT_D->win_lose_check(me,target,1);
                    }
			        target->start_busy(1);
			        if(me->query_busy()<2) me->start_busy(2);
        }
        return 1;
}      
