 // void_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        int skill;
        int my_exp,his_exp;
if(me->query("class")!="bonze" && me->query("class")!="yinshi" )
                return notify_fail("ֻ�еõ���ɮ����������ʿ�ſ���ʹ�ÿ�ʶ��ͨ��\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۿ�ʶ��ͨ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)target->query_temp("voidsense") ) 
                return notify_fail("�����Ѿ������ˣ�����ץ��ʱ��������\n");
        if( me->query("atman") < 150 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 150 )
                return notify_fail("��ľ�������\n");
        if((int) me->query_skill("essencemagic",1) < 60)
                return notify_fail("��İ�ʶ��ͨ�������");
        me->add("atman", -100);
        me->receive_damage("gin", 100);
        message_vision(HIY "$N˫�ֺ�ʮ����ü���ף��������� ...\n" NOR, me);
        
        skill= (int) me->query_skill("essencemagic",1);
        my_exp=(int)me->query("combat_exp");
        his_exp=(int)target->query("combat_exp");
        
        
        if (target->query("dungeon_npc") || target->query("quality")) his_exp = his_exp*2;
                else if (his_exp>5000000 || userp(target)) his_exp=his_exp*2;
        
        if(his_exp < my_exp*3/4+random(my_exp/20*skill))        
        {
                message_vision(HIW"$N��ͷһ����ֻ���������½�Ϊ�������ƣ����β�������������\n"NOR, target);
                target->add_temp("apply/dodge", -skill);
                if (userp(target)) target->add_temp("apply/parry", -skill);
                target->add_temp("apply/attack",-skill);
				target->set_temp("voidsense", 1);
                target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), skill/4);
                return 1;
        }
        message_vision(HIR"$N���һ����������֮�飬Ҳ�Ź⻪����\n"NOR, target);
        message_vision(YEL"$N������ɫ�����Ծ���΢΢������\n"NOR,me);
        me->start_busy(1);
        return 1;
} 
void remove_effect(object target, int amount)
{
        target->add_temp("apply/dodge", amount);
        if (userp(target)) target->add_temp("apply/parry", amount);
        target->add_temp("apply/attack", amount);
        target->delete_temp("voidsense");
         message_vision( HIR"$N����һ�ݣ��������γ��ѡ�\n" NOR, target);
}
 
    
    
       
