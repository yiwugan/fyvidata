 // TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        string msg;
        int lvl, ap, dp; 
        if((int)me->query_skill("spells") < 80 )
             return notify_fail("��ķ��������ߣ�\n");
  
//   if(!me->is_fighting())
//              return notify_fail("���Ƿ��еģۺ��Ǿ���ֻ������ս����ʩչ��\n"); 
        
        if( !target ) target = me;
                else if(me!=target)
                        return notify_fail("���Ƿ��еģۺ��Ǿ���ֻ���������Լ������ϡ�\n");
    
        if(target->query_temp("timer/flex"))
                return notify_fail("��������Ѿ��õ������ˡ�\n"); 
        if((int)me->query("mana") < 150 )
                return notify_fail("��ķ���������\n"); 
        me->add("mana", -150);
    
        msg = HIC "$N���������дʣ�һ����â��$Nͷ�������������$N��Χ��\n\n" ; 
        msg +="��â����һ����ף�����ס$N��ȫ��\n";
        lvl = (int)me->query_skill("spells") * 2;
        target->set_temp("timer/flex",1);
        target->add_temp("apply/flexibility",lvl/6);
        seteuid(ROOT_UID);
        target->start_call_out( (: call_other, __FILE__, "remove_hanxing",target, lvl :),random(lvl/3)+lvl/3);
        message_vision(msg+NOR,me);
        me->start_busy(1);
        return 1;
} 
void remove_hanxing(object me, int lvl)
{
    me->delete_temp("timer/flex");
    me->add_temp("apply/flexibility",-lvl/6);
    message_vision(HIY "\n\n$N����Ĺ�׷���ҫ�۵�һ������ʧ�ˡ�\n\n" NOR, me);
}  
