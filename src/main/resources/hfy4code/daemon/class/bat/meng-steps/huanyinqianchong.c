 // ��Ӱǧ��
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,n, myexp;
        extra = me->query_skill("meng-steps",1);
        if ( extra < 100) return notify_fail("��ģۻ��β����ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۻ�Ӱǧ�أ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
        if (me->query("class")=="bat" && extra >=170) n=0;
                else n=10;
        if(me->query_temp("huanyinqianchong")+n>time() && userp(me))
                return notify_fail("��ո�ʩչ���ۻ�Ӱǧ�أݣ���\n");   
        message_vision(HIR"$N"+HIR"����ӰͻȻһ��ʮ��ʮ��١��ٱ�ǧ��"+HIR"$n"+HIR"�类"+HIR"$N"+HIR"��ǧ�ػ�ӰΧס��\n" NOR,me,target);
        myexp=random(me->query("combat_exp")*3);
        if (me->query("class")=="bat")
                myexp=myexp+me->query("combat_exp")/5;
                
        if((int)target->query("combat_exp") < myexp)
        {
        message_vision(HIW "���"+HIW"$N"+HIW"Ŀѣ��ڣ��ľ�������\n" NOR,target);
        target->start_busy(3);
        me->set_temp("huanyinqianchong",time());
        }
        else{
        message_vision(YEL"���"+YEL"$N"+YEL"��������Ӱ�����ң�\n"NOR,target);
        me->start_busy(2);
        }
        return 1;
}   
