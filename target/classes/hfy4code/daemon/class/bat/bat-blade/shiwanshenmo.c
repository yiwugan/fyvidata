 // shiwanshenmo.c   ʮ����ħ
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra, n, force;
        int tmp,chance;
        object weapon;
        
        if ( (string) me->query_skill_mapped("dodge") != "meng-steps")
                return notify_fail("��ʮ����ħ����Ҫ�ۻ��β����ݵ���ϣ�\n");
        
        extra = me->query_skill("bat-blade",1);
        if (extra < 100) return notify_fail("��ģ����𵶷��ݻ��������죡\n");
        
        tmp = me->query_skill("meng-steps",1);
        if (tmp < 100)  return notify_fail("��ģۻ��β����ݻ��������죡\n");
        
        if (me->query("class")=="bat") n=0;
                else n=100;
        
        if(userp(me) && me->query_temp("timer/shiwanshenmo")+n > time())
                return notify_fail("��ʮ����ħ����Ҫ����Ƭ�̡���\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ʮ����ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        chance=extra+tmp;
        
        force= me->query_skill("force",1)/3;
        if (me->query_skill_mapped("force")=="wuzheng-force" && me->query("class")=="bat")
                force= me->query_skill("wuzheng-force",1);
        
        me->add_temp("apply/attack",tmp+force);
        me->add_temp("apply/damage",extra*3+force);
        
   weapon = me->query_temp("weapon");
        msg = MAG  "\n\n$N��������ؼ�ʮ����ħ���ޱ�������һʽ��ʮ������ħ ���缱�������$n��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if (chance>random(300)) {
                msg = HIB  "\n$N"+HIB"����$w"+HIB"�ó�����Ĺ⻪����$n��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(350)) {
                msg = HIR  "\n$N"+HIR"����$w"HIR"�����������ǵĺ�Х��$n"+HIR"��ȥ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(400)) {
                msg = HIW  "\n$N"+HIW"����$w"+HIW"��Ȼ��������Ե���������$n��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(450)) {
                msg = HIC  "\nʮ����ħ�����ƶ����֣�$N"+HIC"����$w"+HIC"����Ī����Ȼ����$n"+HIC"����ǰ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                if(!userp(me) && me->query("m_success/Ѫ����")&& random(10)>3)
                        target->apply_condition("qicaibat",random(10)+10);
        }
        me->add_temp("apply/attack",-tmp-force);
        me->add_temp("apply/damage",-extra*3-force);
        me->set_temp("timer/shiwanshenmo",time());
        if (me->query_busy()<3) 
                me->start_busy(3);
       
        return 1;
}      