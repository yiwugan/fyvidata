 // yingjichangkong
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        int extra;
        int yourexp,myexp,cpexp;
        string msg;
        
        
        extra = me->query_skill("hawk-steps",1);
        if ( userp(me) && extra < 100) return notify_fail("��ģ����������ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ӥ�����գ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
   
        if (target->query("step_less")==1) 
                return notify_fail(HIW"����������������տ�����ᱻ�˲����Ի�ġ�\n"NOR);
        
        message_vision(HIB "$N"+HIB"���������������ӥ����죬�������裡\n"NOR,me,target);
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=myexp/2+ (2+extra/50)*random(myexp)/2;
        
        if(me->query("class") != "fugui" && userp(me)) cpexp=(2+extra/50)*random(myexp)/2;
        
        if( yourexp < cpexp)    {
                message_vision(HIB"$N"+HIB"����һ�������������ʧ�����������Լ������վ�������ľ����\n"NOR,target);
                target->start_busy(2+random(2));
        }
        else{
                msg = HIR"��ϧ$N"+HIR"������$n"+HIR"����������Ԫ��һ�����$p"+HIR"һ��Īչ��"NOR;
                COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
                me->start_busy(2);      
   }
        return 1;
} 
