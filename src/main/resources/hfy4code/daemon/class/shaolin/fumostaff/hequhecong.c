 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
    string msg;
    int extra,myexp, hisexp;
    object weapon;
    extra = me->query_skill("fumostaff",1);
    if (me->query_skill("staff") < 150 || extra<100) 
                return notify_fail("���Τ�ӷ�ħ�ȷ����������죡\n");
      
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("�ۺ�ȥ�δӣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n"); 
    if (target->query("step_less")==2) 
                return notify_fail(HIW"����������������տ�����ᱻ�˼����Ի�ġ�\n"NOR); 
    myexp = (int) me->query("combat_exp");
    hisexp= (int)target->query("combat_exp");
    message_vision(HIW"$N"HIW"չ��Τ�ӷ�ħ�ȷ�����Ȼ�ó�����ã���֣�\n"NOR, me); 
    if (me->query("class")=="shaolin")      myexp=myexp/2+random(myexp)*11/4;
                else myexp=random(myexp)*5/2;
    
    if (extra >149 && me->query_skill("zen",1)>149 && me->query("class")=="shaolin")
			myexp = myexp+random(myexp)*11/4;
    
    if (!userp(me)) myexp=myexp/2+random(myexp)*5/2;
                
    if(hisexp < myexp)
    {
        target->start_busy(3);
        message_vision(YEL"$N"NOR YEL"һʱ���ƺ����˸ú�ȥ�δӣ���������������\n"NOR,target);
        if(!me->is_busy()) me->start_busy(1);
    }
    else
    {
        message_vision(HIR"����$N"HIR"��$n"HIR"�ľٶ������޶ã�\n"NOR,target,me);             
        if(me->query_busy()<2) me->start_busy(2);
    }
    return 1;
} 
