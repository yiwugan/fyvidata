#include <ansi.h>
inherit F_CLEAN_UP;
#define MAX_GUARD 1
int main(object me, string arg)
{
        object soldier;
        string where;
        int strategy,leadership, exp, title;
        if ((string)me->query("class") != "official")
        return notify_fail("�㲻�ǳ�͢���٣������Լ��չ��Լ��ɣ�\n");
        
/*      where=file_name(environment(me));
        if (userp(me) && where[0..6]=="/d/cave") 
                return notify_fail("�˵��Ѳ����ٸ���Ͻ��Χ��ֻ�ܿ����Լ��������ˣ����ͣ�\n");*/
        
        strategy = (int)me->query_skill("strategy",1);
        leadership = (int)me->query_skill("leadership",1);
        exp = (int)me->query("combat_exp");
        if(strategy < 25 || leadership < 25)
        return notify_fail("�����������֮��̫���ˣ�û��Ը�����㣡\n"); 
        if (exp<10000)
        return notify_fail("��ľ���̫���ˣ�������Х����\n");
        
        
        if (me->query("marks/�ٸ�/����"))
        return notify_fail("�ؼ�ʱ�̽б������������ٱ�û������ث�ֵ�ͽ�ܡ�\n");
        if( !me->is_fighting() )
        return notify_fail("����û����Ҫɱ�㣡\n");
        if((int)me->query("sen")< 150)
                return notify_fail("�����̫���ˣ�\n");
        if((int)me->query("sen")< 150+(strategy+leadership-200)*3/5)
                return notify_fail("�����̫���ˣ�\n");
        
        if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("�������ڵĹ�λ�����Ѿ��ܵ��㹻�ı�����\n");
        
        if ((strategy+leadership)>200)
                me->receive_damage("sen",150+(strategy+leadership-200)*3/5);
                else me->receive_damage("sen",150);
        
           if (random(leadership+strategy) < 13) {
        message_vision(HIB "\n$N����һ����Х��Ԯ������ʲ��Ҳû�з�����\n" NOR, me);   
        return 1;
        } 
        if (leadership+strategy>260 && random(100)<5)
                message_vision(HIB "\n$N����һ����Х��Ԯ������ʲ��Ҳû�з�����\n" NOR, me); 
        else {
                seteuid(getuid());
                soldier= new("/obj/npc/danei_guard");
                soldier->move(environment(me));
                if (leadership>220) leadership = 220;
                if (strategy>200) strategy = 200;
                soldier->invocation(me, (leadership+strategy));
                soldier->set("possessed", me);
                soldier->set_leader(me);
                
                title = leadership+ strategy;
                if (title < 200)
                        soldier->set_name("���ڸ���",({ "bodyguard" }));
                else if (title<300)
                        soldier->set_name(HIY"��ǰ����"NOR,({ "bodyguard" }));
                else 
                        soldier->set_name(HIR"������"NOR,({ "bodyguard" }));
                        
                me->add_temp("max_guard",1);
                me->remove_all_killer();
                message_vision(HIB "\n$N����һ����Х��Ԯ��\n" NOR, me);   
                message_vision(HIB "\n$NӦ��������\n" NOR, soldier);
        } 
        return 1;
} 
int help(object me)
{
        write(@HELP
ָ���ʽ��alert
 
���ָ���ù�Ա���������������Լ���
�ܷ��к������֣���������ˮƽ�ĸߵ;�Ҫ����Ա
��ְ�Ĵ�С�ˡ�
 
HELP
    );
    return 1;
}    
