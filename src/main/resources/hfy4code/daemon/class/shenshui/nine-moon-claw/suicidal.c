#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
    string msg;
    int skill_bonus, myexp;
    if(me->query("class")!="shenshui")
        return notify_fail("ֻ����ˮ�����Ӳ���ʹ����Ψ�Ҷ��𡹵ľ�����\n"); 
    if( !target ) target = offensive_target(me); 
    if( !target||!target->is_character()||!me->is_fighting(target) )
        return notify_fail("��Ψ�Ҷ���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
    msg = RED "$N˫Ŀ���࣬���������׹�צ���һʽ��Ψ�Ҷ��𡹣�";
    
    if ( me->query_skill_mapped("force") == "nine-moon-force") {
        skill_bonus = (int) me->query_skill("nine-moon-force" ,1) 
                     +(int) me->query_skill("nine-moon-claw" ,1);
                        
    }
    skill_bonus = (skill_bonus>=40) ? skill_bonus/40 : 1 ;
    
    myexp = (int) me->query("combat_exp");
   
    if( random(skill_bonus*myexp) + myexp * 9/10 >
        (int)target->query("combat_exp") )
    {
        msg += "���$p��$N���˸����ֲ�����\n" NOR;
        target->receive_damage("kee",(int) me->query("max_kee"),me);
        target->receive_wound("kee", ((int) me->query("max_kee")-20),me);
    }
    else msg += "����$p���Ƕ����$N�����һ������\n" NOR; 
    message_vision(msg, me, target);
    me->unconcious();
    return 1;
}  
