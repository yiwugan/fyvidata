#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int your_exp,n;
        int i;
        
        if (me->query_skill("liangyi-force")<60)
                return notify_fail("������Ʊգ���Ҫ����60�������ķ���\n");
        
//      if(me->query_skill_mapped("force") != "liangyi-force") 
//              return notify_fail("������Ʊգ���Ҫ�����ķ�����ϡ�\n");
        
        if (me->query("force")<100)
                return notify_fail("�������������\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
                ||!target->is_character()
                ||!me->is_fighting(target) )
                return notify_fail("������Ʊգ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
    
        message_vision("$N"+CYN"ʹ�������ķ���һ�С�����Ʊա����ҽ�ʵ������飬ճ��ճ�棬
���ƴ�ס"+"$n"+CYN"���󣬺ᾢ������\n"NOR, me, target);
        me->start_busy(1);      
        if (userp(me)) me->add("force",-100);
        
        your_exp= target->query("combat_exp")/3;              
        if(random(me->query("combat_exp")+me->query("combat_exp")/9) > your_exp)        
        {
        message_vision("\n$N"+CYN"����������ǰһ�壬�����������ʼվ����\n"NOR,target);
        n= me->query_skill("liangyi-force", 1)/60;
        target->start_busy(1+random(n));
        } else message_vision(WHT"����"+"$n"+WHT"������"+"$N"+WHT"����ͼ����û���ϵ���\n"NOR, me, target);
        return 1;
}     
