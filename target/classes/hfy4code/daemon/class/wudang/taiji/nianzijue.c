#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int extra, skill, i; 
  //  if(me->query("class")!="wudang" && userp(me))
    //            return notify_fail("̫��ճ�־����䵱���֮����\n"); 
    skill= me->query_skill("taiji",1);
	
    if (skill < 60)
        return notify_fail("���̫��ȭ���������\n"); 
    
	extra = skill;
      if( me->query("class") != "wudang" ) extra/=2;
      	if (userp(me) && me->query_skill_mapped("force") == "taijiforce") extra/=2;

    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("��ճ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if (target->query("step_less")==1) 
                return notify_fail(HIW"����������������տ�����ᱻ��ȭ���Ի�ġ�\n"NOR); 
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");  
    if (skill < 165) {
        msg = CYN "$N"+NOR CYN"ʹ��̫��ȭ���е�"+HIC"��ճ��"+NOR CYN"�־�����ͼ����$n"+NOR CYN"�Ĺ��ƣ�";
        me->start_busy(1);
        if( random(me->query("combat_exp")*2/3) > (int)target->query("combat_exp")/2) {
            msg += "���$p"+NOR CYN"��$P"+NOR CYN"���˸����ֲ�����\n" NOR;
            target->start_busy( 2 + random(1)); //���busy 3�����busy 2
        }
        else {
            msg += "����$p"+NOR CYN"������$P"+NOR CYN"����ͼ����û���ϵ���\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
    }
    else {
        msg = HIR "$N"+HIR"�����Ķ���˫ȭ�û�Ϊ�������СС��ԲȦ��$n"+HIR"��ȥ��";
	  if( me->query("class") != "wudang" ) i = 2;
		else i = 5;  //�����䵱������ߺߣ�Ч����һ��
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/i
 ) {
            msg += "���$p"+HIR"ͷ��Ŀѣ����$P"+HIR"��ȭ��Χס��������ƵƵ���У�\n" NOR;
            target->start_busy(3);
            me->start_busy(random(2));
            target->receive_damage("kee",((int) me->query("force_factor")*random(extra)/3),me);
            message_vision(msg, me, target);
            target->set_temp("damaged_during_attack", 1);
            COMBAT_D->report_status(target, 0);
            COMBAT_D->win_lose_check(me,target,1);
        }
        else {
            msg += "����$p"+HIR"����Ӧ�У���$P"+HIR"�Ĺ����������Ρ�\n" NOR;
            me->start_busy(random(2));
            message_vision(msg, me, target);
        } 
        return 1;
    }
}   
