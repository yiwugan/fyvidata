#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,myexp,yourexp,cpexp;
//      if(me->query("class")!="knight")
//              return notify_fail("ֻ�п���ֵ��Ӳ���ʹ�����������ľ�����\n");
        extra = me->query_skill("windy-steps",1);
        if ( extra < 50) return notify_fail("��ģۼ�����ʮ��ʽ�ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
        if (target->query("step_less")==1) 
                return notify_fail(HIW"����������������տ�����ᱻ�˲����Ի�ġ�\n"NOR);
        
        message_vision(HIY"$N"+HIY"�����������ޣ��½󸡶����·�����ƣ�������$n"+HIY"���ݰ���ת���죡\n"NOR,me,target);
        
        yourexp=(int)target->query("combat_exp");
        myexp= (int)me->query("combat_exp");
        cpexp= myexp/2+random(myexp)+extra/50*random(myexp)/2;
        if(me->query("class") != "knight" && userp(me)) cpexp=random(myexp)*2;
        if( yourexp<cpexp )
        {
                message_vision(HIG"���$N"+HIG"���ŵ��ۻ����ң���Ӧ��Ͼ��\n"NOR,target);
                target->start_busy(2+random(2));
        }
        else{
                message_vision(HIW"���$N"+HIW"�Լ�ת�˸�ͷ���ۻ���\n"NOR,me);
                me->start_busy(2);
        }
        return 1;
}    
