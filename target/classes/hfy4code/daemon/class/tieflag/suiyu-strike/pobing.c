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
                return notify_fail ("����Ѫ���������ײ���ʹ��"WHT"���Ʊ���"NOR"������\n");
        if (me->query("family/master_id")!="master yun" && me->query("combat_exp") < 10000000)
                return notify_fail("ֻ������״����Ӳſ���ʹ�ã�"WHT"�Ʊ�"NOR"�ݾ�����\n");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                  return notify_fail("��"WHT"�Ʊ�"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ( skill < 80)
                  return notify_fail("��ģ�����ȭ���ݻ��������죡\n"); 
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
              message_vision(MAG "\n$N˲�䲶׽��$n����"NOR+weapon_name+MAG"�趯�Ĺ켣����ȭȫ���͵ػ�����\n\n"+NOR, me,target);
              if (( (myexp + random(myexp)) * mystr ) > (yourexp * yourstr) )
              {
                   message_vision(HIY "$nֻ��$N�Ե���ȭ��Ϯ�������ھ�ʹ֮�£�����"NOR+weapon_name+HIY"��������ַɳ���\n"+NOR,me,target);
                   weapon->unequip();
                   target->start_busy(2);
                   armor = target->query_skill("iron-cloth");
                   me->add_temp("apply/attack", extra*2);
                   me->add_temp("apply/damage", extra*2);
                   msg = HIR"$N��$n���δ�ȣ���ȭ̽����Ѹ���ޱȵ�ֱ������ţ�"NOR;
                   COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                    if( target->query_temp("last_damage_from") && armor >0)
                    {
                    message_vision(BLU"\n$N���͵��ھ�����$n�Ļ����񹦣����ˮ������$n�ľ�����\n"NOR,me,target);
				    target->receive_damage("kee", armor*skill/80, me);
                    }
                   me->add_temp("apply/attack", -extra*2);
                   me->add_temp("apply/damage", -extra*2);
                   me->start_busy(3);
                   weapon->move(environment(target));
                   message_vision(CYN "\n��������һ����"NOR+weapon_name+CYN"�ڿ��з�ת��Ȧ���������ڵ��ϡ�\n"+NOR,me,target);
              }
			        else 
			        {
						        message_vision(HIR "$nֻ���û���һ�飬����"+weapon_name+"��Щ���֣�$N��ȫ��һȭ���޹�������\n" NOR,me,target);
						        if(me->query_busy()<3) me->start_busy(3);
						        COMBAT_D->do_attack(target,me, TYPE_PERFORM);
			        }
        }
        else
        {
                          armor = target->query_skill("iron-cloth");
			        me->add_temp("apply/attack", extra*3);
			        me->add_temp("apply/damage", extra*5);
			        msg = HIR"$N���һ�����������ޱ����ƣ��ҽ��Ҵ��У���˫ȭ�����ֱ��$n�ؿڹ�����\n\n"NOR+HIY "$N�Ե���ȭ��ӿ�룬���顱��һ����$n������õ���������"NOR;
			        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
			        me->add_temp("apply/attack", -extra*3);
			        me->add_temp("apply/damage", -extra*5);
                    if( target->query_temp("last_damage_from") && armor > 0 )
                    {
                    message_vision(BLU"\n$N���͵��ھ�����$n�Ļ����񹦣����ˮ������$n�ľ�����\n"NOR,me,target);
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
