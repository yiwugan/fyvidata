#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int extra,skill,attack,force;
        object weapon;
        if (me->query("class")!="tieflag" )
                return notify_fail ("����Ѫ���������ײ���ʹ��"CYN"�����㡹"NOR"������\n");        
        extra = me->query_skill("sword");
        force = me->query_skill("jiayiforce",1);
			  skill = me->query_skill("xiaoxiang-sword",1);
        if ( userp(me) && (me->query_skill_mapped("force") != "cloudsforce" && me->query_skill_mapped("force") != "jiayiforce" && me->query_skill_mapped("force") != "tiexue-force"))
                return notify_fail(CYN"�����㡹"NOR"������Ҫ��Ѫ�����ŵ��ķ���ϣ�\n");
			  if(skill < 75)
			  	    return notify_fail("������㽣���ȼ�������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(CYN"�����㡹"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if((int)me->query("kee")*10/(int)me->query("max_kee") < 4)
                return notify_fail("����������㣬����ʹ��"CYN"�����㡹"NOR+"������\n");
			  if(me->query_skill("jiayiforce")>=125 && me->query_skill_mapped("force") == "jiayiforce")
			  attack = extra + skill;
              else attack = extra;
			  if(me->query_skill("jiayiforce")>=160 && me->query_skill_mapped("force") == "jiayiforce")
			  attack += force;
        weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",attack);
        me->add_temp("apply/damage",attack);
        msg = HIB  "��Х����$N���󷭷ɣ�"+ weapon->name() + HIB"���ڿ�����������ؽ�������佣���������԰�����ǵ���$n��ȥ��\n"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
      	if( target->is_busy() || target->query_temp("chansi") || target->query_temp("cutkee") )
      	{
            msg =  weapon->name() + HIC +"��â����������������һ��$N���潣�ƣ�ֱ��$nҪ����\n"NOR;
            msg += HIR "��������һ��Ѫ����֮�������\n"NOR;
            me->add_temp("apply/attack",attack*3);
            me->add_temp("apply/damage",attack*3);
            COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
            me->add_temp("apply/attack", -attack*4);
            me->add_temp("apply/damage", -attack*4);
        }
        else
        {
            msg = HIY  "�������Ľ������ֱ�Ӹ�������ĽǶ�Ϯ��$n��$n����ʧ�أ�����֪����мܣ�\n"NOR;
            msg += HIR "������ɢ�����Σ�������ȴ�������Ѫ����\n" NOR;
            me->add_temp("apply/attack",attack*3/2);
            me->add_temp("apply/damage",attack*3/2);
            COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
            me->add_temp("apply/attack", -attack*5/2);
            me->add_temp("apply/damage", -attack*5/2);
        }
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
}  
