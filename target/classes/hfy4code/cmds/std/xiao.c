#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object wolf;
        int summonwolf, exp;
        int guard;
        
        if ((string)me->query("class") != "wolfmount")
                return notify_fail("ֻ����ɽ���Ӳſ�����������\n");
        if ( me->is_busy() )
                return notify_fail("��������æ���޷���������\n");
        if( !me->is_fighting() )
                return notify_fail("����û����Ҫɱ�㣡\n");
        if(((int)me->query("sen")< 80)||((int)me->query("gin")<80))
                return notify_fail("��ľ���״��̫���ˣ������޷���Ч����������\n");
                
        summonwolf = (int)me->query_skill("summonwolf",1);
        exp = (int)me->query("combat_exp");
        if(summonwolf < 25 )
                return notify_fail("��Ļ���֮�������������޷�����������\n");   
        
        if(summonwolf <150) guard =1;
                else guard= 2;
        
        if (summonwolf <180)
        if (environment(me) && !environment(me)->query("outdoors"))
                return notify_fail("�㲻���������ң�\n"); 
        if (!environment(me)->query("outdoors"))
                guard = 1;
                
        if( me->query_temp("max_guard") > guard )
                return notify_fail("���󸽽��Ѿ�û�����ˡ�\n"); 
        seteuid(getuid());
        if (summonwolf<100){    
                me->receive_damage("sen",80);
                me->receive_damage("gin",80);
        } else {
                me->receive_damage("sen",80+(summonwolf-80)/3);
                me->receive_damage("gin",80+(summonwolf-80)/3);
           }
        wolf= new("/obj/npc/wolf");
        wolf->move(environment(me));
        wolf->invocation(me, (summonwolf));
        wolf->set("possessed", me); 
        if (summonwolf<50)
                wolf->set_name("��ë����",({ "wolf" }));
        else if (summonwolf<75)
                wolf->set_name(WHT"��ë����"NOR,({ "wolf" }));
        else if (summonwolf<100)
                wolf->set_name(YEL"��ë����"NOR,({ "wolf" }));
        else if (summonwolf<125)
                wolf->set_name(RED"��ë����"NOR,({ "wolf" }));
        else if (summonwolf<150)
                wolf->set_name(HIW"��ë����"NOR,({ "wolf" }));
        else if (summonwolf<175)
                wolf->set_name(HIR"��ë����"NOR,({ "wolf" }));
        else 
                wolf->set_name(HIY"��ë����"NOR,({ "wolf" }));  
        me->add_temp("max_guard",1);
        me->remove_all_killer();
        message_vision(HIB "\n$N�����Ǻ����ء�໡������ء�໡�����ʱ��ɽ��ҰȺ��������\n" NOR, me);     
        message_vision( "\n\n$N��ݺݵ�����������\n" , wolf);
        return 1;
} 
int help(object me)
{
        write(@HELP
ָ���ʽ��xiao
 
���ָ������ɽ���Ӻ������������Լ���
�ܷ��к����ǣ�������ˮƽ�ĸߵ;�Ҫ����ļ����ˡ�
 
HELP
    );
    return 1;
}     
