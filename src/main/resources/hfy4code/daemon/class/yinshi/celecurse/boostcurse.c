#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int add_agi, bonus;
        int my_exp, your_exp;
        if(me->query("class")!="yinshi")
                return notify_fail("ֻ�е����ȵ��Ӳ����½�ͷ��\n");
        if( !target ) target = me;
        if((int)me->query_skill("celecurse",1) < 20 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n");
        my_exp=me->query("combat_exp");
        your_exp=target->query("combat_exp");
        if (my_exp>your_exp*3 || my_exp<your_exp/3)
                return notify_fail("���˹������̫Զ,�޷��½�ͷ.\n");
        if( !userp(target))
                return notify_fail("��ֻ�ܶ�����������ͷ��\n");
        if( (int)target->query_temp("boostcurse") ) 
                return  notify_fail("�����Ѿ������˽�ͷ��\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ������\n");
        me->receive_wound("kee", 100);
        msg = HIC "$N���쳤Х������ؼ��������Ϊһ�壮����\n\n" NOR;
        message_vision(msg,me);
        add_agi=  me->query_skill("cursism")/20;
        target->add_temp("apply/agility",add_agi);
        target->add_temp("apply/move",add_agi*5);
        
        if (me->query_skill("cursism")>300){
                bonus = add_agi/4;
                target->add_temp("apply/strength",bonus);
                tell_object(target, HIG "���Ȼ�����Լ�ǿ��������\n" NOR );
                }
        target->set_temp("boostcurse",1);
        me->start_busy(2);
        tell_object(target, HIG "���Ȼ�����Լ���������������\n" NOR );
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target, add_agi, bonus :), (int)me->query_skill("cursism")/3);
        return 1;
} 
void remove_effect(object me, int amount, int bonus)
{
        me->delete_temp("boostcurse");
        tell_object(me, HIG"�����ϵĵĽ�ͷʧЧ�ˣ�\n"NOR);
        me->add_temp("apply/agility",-amount);
        me->add_temp("apply/move",-amount*5);
        if (bonus!=0) me->add_temp("apply/strength",-bonus);
}      
