//add by xiaolang
//copyright for glqx.net
#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        object wolfboss,wolf;
        int wolfcurse, exp;
        int count;
        
        if ((string)me->query("class") != "wolfmount")
                return notify_fail("ֻ����ɽ���Ӳſ������ǹ��衣\n");
        if( !me->is_fighting() )
                return notify_fail("���ڲ������ǹ����ʱ��\n");
                
        if(userp(me) && me->query("wolf_timer/yulanggongwu")+ 300 > time())
                return notify_fail("���ʹ���ˣ����ǹ���ݲ��á�\n");
                
        if( me->query_temp("wolf")>=2)
        	return notify_fail("�����Ѿ�û�����ˣ�\n");
        wolfcurse = (int)me->query_skill("wolf-curse",1);
        exp = (int)me->query("combat_exp");
        if(wolfcurse < 200 )
                return notify_fail("�������Ѫ�仹�������������������ǵĹ��衣\n");   
        count=3+(wolfcurse-200)/10;
        if(count>=6) count =6;
        seteuid(getuid());
        me->receive_damage("sen",random(wolfcurse/2));
        me->receive_damage("gin",random(wolfcurse/2));
        wolfboss= new("/obj/npc/wolfboss");
        wolfboss->move(environment(me));
        wolfboss->setboss(me, (wolfcurse));
        wolfboss->set("possessed", me); 
        wolfboss->set("name",WHT"��������"NOR);
        for(int i=0;i<count;i++)
        {
        	wolf= new("/obj/npc/wolfguard");
        	wolf->move(environment(me));
        	wolf->setguard(me, (wolfcurse));
        	wolf->set("possessed", me);
        	wolf->set("boss",wolfboss);
        	wolf->set("name",WHT"������"NOR);
        }       
        me->add_temp("wolf",1); 
        me->remove_all_killer();
        message_vision( WHT"\n$N����������������дʣ�ͻȻ֮�䣬һֻֻ��������������˷�ӿ�ֳ�������\n"NOR, me);     
        message_vision( WHT"\n\n������"+HIR"Χ��$N���ܣ������κ����˺��Լ������ˡ�\n"NOR ,me);
        me->start_busy(random(count)+1);
        me->set("wolf_timer/yulanggongwu",time());
        return 1;
} 