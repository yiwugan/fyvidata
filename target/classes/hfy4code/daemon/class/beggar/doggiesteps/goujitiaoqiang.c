 // silencer@fy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int ap,dp; 
//      if(me->query("class")!="beggar")
//      return notify_fail("���ֲ��ǽл��ӣ�ʹ��������߯������˰ɡ�\n"); 
        extra = me->query_skill("doggiesteps",1);
        if ( extra < 50) return notify_fail("��ģ�Ұ�������ݻ��������죡\n"); 
        if((int)me->query("kee")*100/(int)me->query("max_kee") > 80 && me->query("class")!="beggar")
                return notify_fail("��û���ؼ�ʱ���أ�\n");   
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۹�����ǽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        message_vision(HIW"\n$N���һ���������类�Ƽ���Ұ����˫��һǰһ��������$n�߳���
        ����δ��֮ʱ����Ȼ�����ת�� \n"NOR,me,target);
        ap=(int)target->query("combat_exp");
        dp=(int)me->query("combat_exp");
        
        message_vision(HIW"\n��� \n"NOR,target,me);
        if(ap<dp/2+random(dp*(extra/200)))
        {
                me->remove_killer(target);
                target->remove_killer(me);
                message_vision(YEL"\n$Nһ�����ֲ�������$n��������˹�ȥ�� \n"NOR,target,me);
                return 1;
        }
        message_vision(HIR"$N����һչ����ס$n��ȥ·�� "NOR,target,me);
        msg = YEL "$N���һ���������ù������������Ƴ�$n��$l��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                
        message_vision(HIW"\n���� \n"NOR,target,me);
        if(ap<dp/2+random(dp*(extra/150)))
        {
           me->remove_killer(target);
                target->remove_killer(me);
                message_vision(YEL"\n$Nһ�����ֲ�������$n��������˹�ȥ�� \n"NOR,target,me);
                return 1;
        }
        message_vision(HIR"$N����һ�Σ�����$n��ǰ��"NOR,target,me);
        msg = YEL "$N�����ܻ���ʹ��[������]����$n��$l��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);  
        message_vision(HIW"\n�͵���һ�� \n"NOR,target,me);
        if(ap<dp/2+random(dp*(extra/150)))
        {
                message_vision(YEL"\n$Nһ�����ֲ�������$n��������˹�ȥ�� \n"NOR,target,me);
                me->remove_killer(target);
                target->remove_killer(me);
                return 1;
        } 
        me->start_busy(2);
        message_vision(HIR"$N�ݶ��ھ���$nֻ������һ�ͣ����޿ɱ� \n"NOR,target,me);
        return 1;
}    
