 // steal.c
#include <ansi.h> 
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string what, who;
        object ob, victim, guard;
        int sp, dp;
        if( environment(me)->query("no_fight"))
                return notify_fail("�����ֹ���ԡ�\n");
        
        if (guard=present("police",environment(me))) {
                message_vision(guard->query("name")+"��$N˵�������������ʲô��\n",me);
                return 1;
                }
        
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("��ôΣ�յĵط������ǲ�Ҫ��͵�����˰ɡ�\n"); 
        if( me->query_temp("stealing") )
                return notify_fail("���Ѿ����һ��������ˣ�\n"); 
        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n"); 
        victim = present(who, environment(me));
        if( !victim || victim==me) return 
                notify_fail("�������ԵĶ��������\n");
        if( userp(victim) && !living(victim))
                return notify_fail("�㲻��͵�ε�������ϵĶ�����\n");
        if( ! victim->is_character())
                return notify_fail("����ã������������������������������\n");
        if (victim->is_corpse())
                return notify_fail("����͵�ˣ�ֱ���þ��С�\n");
        
        if( !wizardp(me) && wizardp(victim) )
                return notify_fail("��Ҳ���͵�������ϵĶ�����\n");
        if((int)me->query_skill("stealing",1) < 25 )
                return notify_fail( victim->name()+"���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + 
"���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
                ob = inv[random(sizeof(inv))];
        }
        
        sp = (me->query_skill("stealing")+me->query_kar())*100/360;
                if( sp < 1 ) sp = 1;
                if (sp > 100) sp=100;
                if( me->is_fighting() ) {
                        sp /= 2;
                        me->start_busy(3);
                }
        
        dp = (victim->query("sen")+ ob->weight()/10)*100/(me->query("sen")+1);
                if (dp<100) dp = 100;
                if( victim->is_fighting() ) dp *= 3;
                if( ob->query("equipped") ) dp *= 5; 
        write("�㲻����ɫ����������" + victim->name() + "���ȴ��������� 
...\n\n");
//      tell_object(me,"sp="+(string)(sp)+", dp="+(string)(dp)+"\n");
        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp); 
        return 1;
} 
void compelete_steal(object me, object victim, object ob, int sp, int 
dp)
{
        me->delete_temp("stealing");
        me->add("score",-1);
        if(!victim) {
                tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ������ˡ�\n");
                return;
        }
        if( environment(victim) != environment(me) ) {
                tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
                return;
        }
        if((int)ob->query("no_get")||(int)ob->query("lore")) {
                tell_object(me,"��͵�����Ƕ���\n");
                return;
   }
        if( !living(victim) || (random(sp+dp) > dp) ) {
                if( !ob->move(me) ) {
                        tell_object(me, "������һ" + ob->query("unit") + 
ob->name() 
                                + "�����Ƕ������̫���ˣ����ò�������\n");
                        return;
                }
                tell_object(me, HIW "�����ˣ�\n\n" NOR);
                tell_object(me, "��ɹ���͵��һ" + ob->query("unit") + 
ob->name() + "��\n");
                if( living(victim) )
                if( random(sp) < dp/4 )
                        message("vision", "�㿴��" + me->name() + 
"�������ش�"
                                + victim->name() + "����͵����һ" + 
ob->query("unit")
                                + ob->name() + "��\n", environment(me), ({ 
me, victim }) );
        } else {
                if( random(sp) > dp/4 ) {
                        tell_object(me, victim->name() + 
"�������һתͷ���㼱æ�������˻�ȥ��\n"
                                "���ã�û�б����֡�\n");
                        return;
                }
                tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
                message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + 
ob->name() + "��\n\n"
                        + "$N�ȵ�������ʲ�ᣡ��\n\n", victim, me);
                if( userp(victim) ) victim->fight_ob(me);
                else victim->kill_ob(me);
                me->fight_ob(victim);
                me->start_busy(5);
                
                if (me->query("class")=="beggar") {
                if (me->query_skill("stealing")>=300) me->start_busy(2);
                        else if (me->query_skill("stealing")>=200) me->start_busy(3);
                        else if (me->query_skill("stealing")>=100) me->start_busy(4);
                }
                          
                me->add("thief", 1);
        }
} 
int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��> 
���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, �����ʲ�����......�����Լ�ȥ�����ޡ�
HELP
    );
    return 1;
}
       
