 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string dodskill,msg;
    int extra, count, n;
    int tmp,chance;
    extra = me->query_skill("shenji-blade",1);
    if ( extra < 50) return notify_fail("��ģ���������ݻ��������죡\n");
    dodskill = (string) me->query_skill_mapped("dodge");
    if ( dodskill != "shenji-steps")
        return notify_fail("�ۼƳ���������Ҫ����������ݵ���ͣ�\n");
    tmp = me->query_skill("shenji-steps",1);
    if ( tmp < 50 )return notify_fail("��ģ���������ݻ��������죡\n");
	if (me->query("class") != "emei")
	{
		extra = extra /2;
		tmp = tmp /2;
	}

        chance=(extra+tmp)/2;
        
        chance=chance<160? 160-chance:0;
        
        
    if( !target ) target = offensive_target(me);
    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("�ۼƳ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    me->add_temp("apply/attack",tmp);
    me->add_temp("apply/damage",extra/2);
    msg = HIR  "\n\n$N�ӳ���������еľ�����ص�һʽ�������ƣ�����������������\n\n"NOR;
	count = 0;
//    if(chance<random(160))
//    {
        msg+=HIR"\n��սƪ��\n$N����$wֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
//    }
    if(chance<random(160))
    {
        msg = HIY  "ʤսƪ��\n$N����$w"+HIY"б��$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {    
        msg = HIW  "��սƪ��\n$N����$w"+HIW"ƽ��$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {        
		msg = HIG  "��սƪ��\n$N����$w"+HIG"�ῳ$n��" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {    
        msg = HIM  "��սƪ��\n$N����$w"+HIM"�ݶ�$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {    
        msg = HIC  "��սƪ��\n$N����$w"+HIC"����$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {       
        msg = HIB  "��սƪ��\n$N����$w"+HIB"����$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
//  if(chance<random(160))
//    {    
    msg = HIR  "��սƪ��\n$N����$w"+HIR"�ӽ����������$n"+HIR"ɱȥ��" NOR;
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	count++;
//    }
    me->add_temp("apply/attack",-tmp);
    me->add_temp("apply/damage",-extra/2);
    if(count <= 5) n = 3;
    if(count > 5 && count < 8) n = 4;
    if(count == 8) n = 5;
    if(me->query("combat_exp")<=1600000 && n >= 4) n = 3;
    if(me->query_busy()<n) me->start_busy(n);
    return 1;
} 
