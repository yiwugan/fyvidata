 //mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int extra);
int perform(object me, object target)
{
        string msg;
        int extra; 
        extra = me->query_skill("enmeiryu",1);
        if(extra<100) return notify_fail("��½��Բ����ȭ������Ϊ�������޷�ʹ���ϵ������ŵľ��С�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ϵ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");  
        extra = me->query_skill("enmeiryu",1) / 3; 
         if (me->query("class")=="shaolin")  extra = extra *3/2;
        message_vision(HIY"$NͻȻһЦ��������$n����ǰһ�Σ�Ծ����һ�ࡣ$nһʱ�޷�����$N����Ӱ�� 
���ϵ������ţ��� \n",me,target);
        begin_perform(me,target,4,extra);
        return 1;
        
}      
string *perform_msg=({
        HIY"$N�����ڵ���һ�ţ����岻��˼����ٴε���˫�ŵ���$n��ϥ�ؽڡ�\n"NOR,
        HIY"$N��������֮�ƣ��ٴ�ת������Ѹ�ײ����ڶ�֮�ƣ�ɨ��$n�ľ�����\n"NOR,
        HIY"$N�߸�Ծ�𣬿���һ��š������Ȼ�Խ������͵���$n��ͷ��ն��������\n"NOR,
        HIY"$N�͵شӲ���Ծ��$n������$n��֪����֮ʱ��һ����������$n�����š�\n"NOR,
        }); 
int begin_perform(object me,object target,int count,int extra)
{
        string msg;
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target)
        ||environment(target)!=environment(me)          )
                return 0;
        if(count)
        {
                msg=perform_msg[--count];       
//         me->stop_busy();
                me->add_temp("apply/attack", extra);    
                me->add_temp("apply/damage", extra);            
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra);
                begin_perform(me,target,count,extra);
        }
        else
                me->start_busy(3); 
        return 1;
} 
