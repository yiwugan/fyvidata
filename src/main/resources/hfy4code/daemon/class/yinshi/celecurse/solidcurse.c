#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int lvl;
        object corp,room,ghost;
        
        if(me->query("class")!="yinshi")
                return notify_fail("ֻ�е����ȵ��Ӳ����½�ͷ��\n");
        
        if((int)me->query_skill("celecurse",1) < 120 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n"); 
        if( !target
        ||  !target->is_ghost()
        ||  target==me
        ||  userp(target) )
                return notify_fail("��ֻ�ܶԹ���������ͷ��\n");
        room=environment(target); 
        if (me->query_temp("timer/solidghost")>0)
                return notify_fail("���Ѿ�����סһ�������ˡ�\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ������\n");
        if(!corp = present("corpse",environment(me)))
                return notify_fail("�����Χû��ʬ�壡\n");
//      if( target->query("combat_exp") > me->query("combat_exp")*10)
//              return notify_fail("��ĵľ��鲻���Կ���"+target->name()+"��\n");
        
        lvl=me->query_skill("cursism");
        me->receive_wound("kee", 100);
        msg = HIC "$N��ն���$n��㼸�£�$n������վ��������\n\n" NOR;
        message_vision(msg,me,corp);
                
        seteuid(getuid());      
        ghost=new("/obj/npc/solidghost");
        ghost->invocation(me,lvl);
        ghost->set("name",corp->query("victim_name")+"������");
        ghost->move(environment());
        destruct(target);
        destruct(corp);
   me->set_temp("timer/solidghost",1);
        msg = HIC "$n��$N����������ë���Ȼ��Ц���������ˣ���ʲô�Ը���������\n\n" NOR;
        message_vision(msg,me,ghost);
        
        me->start_busy(2);
        return 1;
}   
