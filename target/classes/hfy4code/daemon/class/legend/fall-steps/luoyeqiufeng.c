 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, yourexp,myexp,cpexp; 
        if(me->query_temp("luoyeqiufeng")+2>time())
                return notify_fail("��ո�ʩչ������Ҷ���ݣ���\n");
        extra = me->query_skill("fall-steps",1);
        if ( extra < 90) return notify_fail("��ģ���粽�ݻ��������죡\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����Ҷ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if (target->query("step_less")==2) 
                return notify_fail(HIW"�Է�������������տ�����ᱻ�˲����Ի�ġ�\n"NOR);
                
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                
        message_vision(HIY"$N"+HIY"��̤�˷�������������е���Ҷ��Ʈ�첻����\n"NOR,me,target);
                
        me->set_temp("luoyeqiufeng",time());
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=myexp/2+ (4+extra/110)*random(yourexp)/2;
        if(me->query("class") != "legend" && userp(me)) cpexp=(4+extra/150)*random(myexp)/4;
        
        if(yourexp < cpexp)
        {
                message_vision("���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n",target);
                target->start_busy(3);
        }
        else{
           msg = HIR"��ϧ$N"+HIR"������$n"+HIR"��������$p"+HIR"ٿȻ������"NOR;
                COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
        }
        return 1;
} 
