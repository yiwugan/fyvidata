#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
    int extra, bonus,n;
    string msg;
    if (me->query("class") != "huashan") return notify_fail("ֻ�л�ɽ���ӿ���ʹ�á�ժ��ʽ����\n");
    if( !target ) target = offensive_target(me);
    extra=me->query_skill("zhaixin-claw",1);
    if (extra<50) return notify_fail("��ġ�ժ���֡�����������\n"); 
    if( !target||!target->is_character()||!me->is_fighting(target) )
        return notify_fail("��ժ��ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
     if ((!userp(target)) && me->query("timer/zhaixin")+600>time())
        return notify_fail("��ժ��ʽ���ķ��������󣬲�������ʹ�á�\n"); 
    
    msg = HIW "$n��ɫ��òҰ���ֽ��˫������ָ�ⷢ��ӨӨ�Ĺ�â�� 
$n��Ȼ��һ����õ�������$N��ǰ��˫צ�����ץ��$N�Ŀڣ� \n"NOR; 
    
        me->set("timer/zhaixin",time());        
/*  cloud-dance is temperorily taken out from huashan skills
        the bonus here is not reasonable, given players can using alias with Level 1 
        cloud-dance to get the bonus.
        we might consider add it back in the future patch. --- silener */ 
//  give bonus to NPC kill
        if (userp(target)) bonus = 2;
                else bonus = 3;  
                n = 150/extra + bonus;
    if( random(extra*extra*extra*bonus/4 + me->query("combat_exp")/8)*bonus + me->query("combat_exp")/2>
 (int)target->query("combat_exp")&& random(5) && !target->query("boss")) {
        msg += RED"\n\n$N"RED"�ò������ŵ��۹⿴���Լ��Ŀڵ�Ѫ��������һ�Σ����ڵ��ϡ� \n" NOR;
        target->receive_wound("kee", ((int) target->query("max_kee")+300000),me);
    }
    else msg += HIC"\n\n$N��æ���з�ס$n������ɭɭצӰ�������ˣ��㿪��$n������һ���� \n" NOR; 
    message_vision(msg, target, me);
    me->set("sen",50);
    me->set("force",0);
    me->set("force_factor",0);
    me->start_busy(n);
    return 1;
}       
