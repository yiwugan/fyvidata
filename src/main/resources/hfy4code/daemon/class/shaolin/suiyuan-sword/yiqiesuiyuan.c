 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("suiyuan-sword",1) ;
        if (extra < 100) 
                return notify_fail("�����Ե���ǽ����������죡\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��һ����Ե��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        
        if (hisexp>3500000) hisexp=hisexp*3;
        
        if(random(hisexp) < myexp  && weapon && random(2))      
        {
        message_vision(
HIG "\n$Nʹ��һʽ��һ����Ե�ݣ����������߰��ס$n���еı��У�"+ 
weapon->name()+  HIG"���ֶ��ɣ�\n" NOR, me,target);
        if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
        me->add_temp("apply/attack", extra*4);
        me->add_temp("apply/damage", extra*2);
        msg = HIY+ "\n$Nʹ��һʽ��һ����Ե�ݣ����е�"+(me->query_temp("weapon"))->name()+HIY"�������ֱ��$n��$l��\n"+ NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra*4);
        me->add_temp("apply/damage", -extra*2);
        if (me->query_busy()<2) me->start_busy(2);
        }
        return 1;
}   
