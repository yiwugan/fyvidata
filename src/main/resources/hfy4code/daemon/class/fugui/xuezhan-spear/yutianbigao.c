#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        int basic;
        int i, flag;
        object weapon;
        
        extra = me->query_skill("xuezhan-spear",1);
        tmp = me->query_skill("hawk-steps",1);
        flag = 0;
        
        if ( extra < 40) 
                return notify_fail("���Ѫսǹ�����������죡\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "hawk-steps")
                return notify_fail("������ȸߣ���Ҫ�����������ݵ���ͣ�\n");
        if ( tmp < 40 )
                return notify_fail("��ģ����������ݻ��������죡\n");
        
        if ( userp(me) && me->query_skill_mapped("force") != "skyforce")
                return notify_fail("������ȸߣ���Ҫ�۱̿��ķ��ݵ���ϣ�\n");
        
                
        basic = extra/40 + tmp/40;
        if (basic>4)
                basic=4;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ȸߣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        msg = HIR"$N������"NOR+weapon->name()+HIR"��أ�����������չ�ᣬһ�ɳ��죡\n"NOR;
        message_vision(msg, me, target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
   {
                message_vision("���$NĿ�ɿڴ�����֪����мܣ�\n",target);
				if (target->query_busy()<2) 
                            target->start_busy(2);
                me->add_temp("apply/attack",tmp*3);
                me->add_temp("apply/damage",extra/5);
                for(i=0;i<basic;i++)
                {
                        if (me->is_busy()) continue;
                        msg = HIY"��Ц���У�$N����»��������ֽ�����Ծ��\n"NOR;
                        message_vision(msg, me, target);
                        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                }
                if (me->query_busy()<3) 
                        me->start_busy(3);
				me->add_temp("apply/attack",-tmp*3);
                me->add_temp("apply/damage",-extra/5);
        }
        else{
                message_vision("����$N�Ѿ�����$n�Ĺ�ʽ��$n�������ƣ�\n",target,me);
                me->start_busy(2);
                if (me->query("class")!="fugui"|| extra<140)
                        COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_PERFORM,msg);
                
        }
        return 1;
}      
