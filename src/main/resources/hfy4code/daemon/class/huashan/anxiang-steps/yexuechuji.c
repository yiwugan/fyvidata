 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp;
        extra = me->query_skill("anxiang-steps",1);
        if ( extra < 50) return notify_fail("��ģ۰��㸡Ӱ�ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("��ҹѩ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
        if (target->query("step_less")==2) 
                return notify_fail(HIW"����������������տ�����ᱻ�˲����Ի�ġ�\n"NOR);
        
        message_vision(WHT"$N����Ӱ��Ȼ������ʲ������ƺ�������һ�Ƶ����İ���\n"NOR, me); 
        message_vision(WHT"��ҹѩ�ں�÷��Ʈ�䣬ѩ���趯֮�䣬����������㸡����\n"NOR, me); 
        myexp = me->query("combat_exp")+random(me->query("combat_exp") / 85 * extra);
        if (me->query("class")!="huashan") myexp = me->query("combat_exp")*1/5+random(me->query("combat_exp") / 100 * extra);
        if(myexp > target->query("combat_exp"))
        {
                message_vision(HIW"\n$N"+HIW"������Խ��Խ����������������ã����ѩ�С�\n"NOR, target); 
                message_vision(HIG"�����ư����У�$N"+HIG"������Щ����������\n"NOR, target); 
                target->receive_damage("gin", 40,me);
                target->start_busy(3);
        }
        else{
                message_vision(HIY"\n$N"+HIY"���Ĺ�һ����Ϊ$n"+HIY"������һ��̤��������$n"+HIY"�Ŀ��ţ�\n"NOR, target, me); 
                me->start_busy(2);
        }
        return 1;
}    
