#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg,id_enemy;
        int damage, ap, dp;
        int extradam, my_exp;
        
        if(me->query("class")!="yinshi")
                return notify_fail("ֻ�е����ȵ��Ӳ����½�ͷ��\n");
        if((int)me->query_skill("celecurse", 1) < 150
                && userp(me))
                return notify_fail("��Ľ�ͷ�������ߣ�\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
                ||!target->is_character()
                ||target->is_corpse()
                ||target==me)
                return notify_fail("��Ҫ��˭ʩչ�����ͷ��\n");
    
        if((int)me->query("kee") < 100 && userp(me))
                return notify_fail("�����Ѫ������\n");
    
        me->receive_wound("kee", 10);
        msg = RED "$N"+RED"�����к��һ����һ��ϸ�緢˿��Ѫ������$n��\n\n" NOR;
    
        ap = me->query_skill("cursism");
        my_exp=me->query("combat_exp");
        dp = target->query("combat_exp");
    
        if (userp(me)) {
                extradam = me->query("kee");
                extradam = extradam/5;
        } else  extradam = 1000; 
//      message_vision("extradam is"+(string)(extradam)+".\n",me);
//      =10000/5
    
        damage = ap*4 + random(ap*5) + extradam/4;
//      400x4+ random(400x5) + 2000/4
//      lowest 2100, highest 4100, average 3100 
// message_vision("damage is"+(string)(damage)+".\n",me);
 
        if(damage >me->query("max_kee")) damage = me->query("max_kee");
    
        if (userp(me)) ap=random(my_exp/80*ap);
                        else ap=random(8*my_exp);
        if( ap>dp) {
                if (!me->is_fighting(target)) {
                if (!userp(target)||!userp(me)) {
                        target->kill_ob(me);
                        me->kill_ob(target);
                }else { 
                        id_enemy=target->get_id();
                        me->ccommand("kill "+id_enemy);
                        target->kill_ob(me);
                }
                }
                message_vision(msg, me, target);
                target->receive_wound("kee", damage/2, me);
                target->receive_damage("kee", damage/2, me);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
        } else          {
                msg += WHT"���Ǳ�$n"NOR+WHT"�����ˣ���\n"NOR;
                message_vision(msg, me, target);
                if (!me->is_fighting(target)) {
                if (!userp(target)||!userp(me)) {
                        target->kill_ob(me);
                        me->kill_ob(target);
                }else { 
                        id_enemy=target->get_id();
                        me->ccommand("kill "+id_enemy);
                        target->kill_ob(me);
                }
                }
        }
        me->start_busy(3) ;   
        return 1;
}        
