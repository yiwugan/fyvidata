 // ���������콣���ľ��С����˺�һ��
#include <ansi.h> 
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int delay,i;
        
	if ((int)me->query_skill("sky-sword",1)>=200)
	            i=(me->query_skill("sky-sword",1) - 180)/20;
	if(i == 0) i=1;
	if(i >= 3) i=3;          
        if (me->query("class")!="emei")
                return notify_fail ("�����˺�һ��ֻ�ж��ҵ�����ʹ�á�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����˺�һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int) me->query_skill("sky-sword",1) < 200)
                return notify_fail("������콣�����������������ܷ��������˺�һ����\n");
        delay=1+ random(3-i);
        message_vision(HIG"$N�������ֹˮ������������ء�\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), delay);
        me->start_busy(1+random(3-i));
        return 1;
}
void kill_him(object me, object target)
{
        int targetexp,damage,mylevel,myexp,targetkee;
        int res_kee;
        int i,x,lvl;
        string msg;
        
        if ((int)me->query_skill("sky-sword",1)>=200)
	    i=(me->query_skill("sky-sword",1) - 180)/20;
	if(i == 0) i=1;
	if(i >= 3) i=3;   
	
	lvl=me->query_skill("sky-sword",1);
	x=(lvl-190)/2;
        if(x==0) x=1;
        if(x>=50) x=50;
        res_kee=target->query("resistance/kee");
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg = HIY "\n����һ����û������$N���У���ʱ��ͣ��ֹ�������Ϣ���ղŵ�һ���� 
���ƺ�ֻ��һ�����Σ���Ȼ�޴档" ;
        targetexp=target->query("combat_exp");
        myexp=me->query("combat_exp");
	mylevel=me->query_skill("sky-sword", 1)/3;
        targetkee=target->query("max_kee");
        damage=targetkee*(20+random(50)+random(mylevel))/100;
        if(random(targetexp*2)+myexp>targetexp)
           {     msg += HIR "\n$nֻ������һ����һ֧Ѫ��ͻȻ��$p��ǰ������\n" NOR;
                 target->start_busy(random(i));
           }                
        else {
                msg+=HIR "\n$n�͵�һ�����ǳ��Ǳ��Ķ����$N����һ������ȴ�޷��������Ľ�����\n"NOR;
                damage=random(damage/2);
                target->start_busy(1+random(i));
        }
        target->set("resistance/kee",res_kee/(random(x)+1));
        target->receive_damage("kee",damage); 
        message_vision(msg, me, target);
//      target->set_temp("damaged_during_attack", 1);
        COMBAT_D->report_status(target);
        target->set("resistance/kee",res_kee);
        target->set_temp("last_damage_from",me);
        }
        me->start_busy(2);
        return ;
}  

