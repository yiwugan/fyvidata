 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int second_sword(object me,object target,int extra,int bonus,object weapon);
int perform(object me, object target)
{
        string msg;
        int extra, bonus, rsen;
        object weapon;

        extra = me->query_skill("doomsword",1);
		    bonus = me->query_skill("doomforce",1);
        weapon=me->query_temp("weapon");

        if ( extra < 50) return notify_fail("��ĺ��촵Ѫ�������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ӽ��÷��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
       
       me->add_temp("apply/attack", extra*bonus/20);
        msg = HIR "$N��Ȼת����������һ�ס�ӽ��÷����������ν��÷��Ѫ������������ɱ������\n\n"+HIW"������δ�����ơ���δ��" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "�����庮�����ѡ�Ц����" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "������ɡ����롫���ѱ�" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "����ϼ�����޸�����δͨ" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "�������࡫��ױ���ڱ���"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "�������ɡ�������к�"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "�������������ǡ�Ѱ��ɫ"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIW  "����Ũ������������ѩ�С���"NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -extra*bonus/20);

        if (me->query("class")=="fighter") {
       if(random(me->query("combat_exp")+extra*extra*extra)>target->query("combat_exp")){
					msg = HIC "\n���һʽ�������ˣ�����̹ǣ�$N�������˸����¡�\n"NOR;
					target->start_busy(2);
					message_vision(msg, target);
        rsen = target->query("resistance/sen");
				target->set("resistance/sen",0);
                target->receive_damage("sen", extra +  random(bonus), me);
								target->set("resistance/sen",rsen);
							}
			}       
        
                 
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
        
} 
