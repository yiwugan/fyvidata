#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        string msg;
        int lvl, ap, dp;
    
//    if(!me->is_fighting())
//        return notify_fail("���Ƿ��еģۻ��Ǿ���ֻ������ս����ʩչ��\n"); 
        
        if( !target ) target = me;
                else if(me!=target)
                return notify_fail("���Ƿ��еģۻ��Ǿ���ֻ���������Լ������ϡ�\n");
    
        if((int)me->query_skill("spells") < 80 )
                return notify_fail("��ķ��������ߣ�\n"); 
        if( !target
                ||!target->is_character()
                ||target->is_corpse() )
                return notify_fail("��Ҫ��˭ʩչ���������\n");
    
        if(target->query_temp("in_jixing"))
                return notify_fail("�����ڲ�����Ҫʩչ���Ǿ���\n");
    
        if((int)me->query("mana") < 150 )
                return notify_fail("��ķ���������\n");
    
        me->add("mana", -150);  
        msg = HIC "$N���������дʣ�һ����â��$Nͷ�������������$N��Χ��\n\n" ; 
/*  ap = me->query_skill("spells");
    ap = ( ap * ap /100 * ap/30 ) * (int)me->query("sen") ;
    dp = offensive_target(me)->query("combat_exp");
    if( random(ap+me->query("combat_exp")) + me->query("combat_exp") > dp )
    {*/
        msg +="��â����һ��������ע����$N��ȫ��\n";
        lvl = (int)me->query_skill("spells")/2;
        if ((string)me->query("class") != "wudang") lvl=lvl /2;
        target->set_temp("in_jixing",1);
        target->add_temp("apply/damage",lvl);
        seteuid(ROOT_UID);
        target->start_call_out( (: call_other, __FILE__, "remove_hanxing",target, lvl :),
                                random(lvl)+lvl);
/*    } else
        msg += "�������Ͼ���ʧ�ˡ�\n";*/
    
        message_vision(msg+NOR,me);
        me->start_busy(1);
        return 1;
} 
void remove_hanxing(object me, int lvl)
{
    me->delete_temp("in_jixing");
    me->add_temp("apply/damage",-lvl);
    message_vision(HIY "\n\n$N����һ�����ƺ��йɹ�â������⡣\n\n" NOR, me);
}  
