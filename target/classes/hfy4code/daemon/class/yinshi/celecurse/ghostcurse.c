#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extradam;
        if(me->query("class")!="yinshi")
                return notify_fail("ֻ�е����ȵ��Ӳ����½�ͷ��\n");
        
        if((int)me->query_skill("cursism") < 300 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n"); 
       // if (me->query("timer/ghostcurse")+180>time())
         //       return notify_fail("���ķ����ܼ�������Ҫ�ú���Ϣһ��\n");
        
        if((int)me->query("kee") < 500 )
                return notify_fail("�����Ѫ������\n");
                 write("�����˭�Ļꣿ");
                 input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
} 
void select_target(object me, string name)
{
        mapping ob_list;
        object ob,new1;
        string msg;
        object room;
        string *list;
        object *inv;
        int i,HERE = 0;
        if( !name || name=="" ) {
                write("��ֹʩ����\n");
                return;
        } 
                ob = find_living(name);
                room = environment(me);
        me->receive_wound("kee",random(500)); 
        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)|| ob->is_ghost()
                || ob->query("no_curse")){
                write("���޷����ܵ�����˵Ĺ�ꡣ\n");
           return; }
        msg = HIW "$N˫������һ�ӣ�һ��Ũ��ӵ��¾��������\n" ;
    if( ob_list = room->query("objects"))
                {
                list = keys(ob_list);
                for(i=0;i<sizeof(list);i++)
                        if(list[i] == base_name(ob) || list[i] == base_name(ob)+".c")
                                {HERE=1;break;}
                }
        if( HERE && random(10) >0) {
                        seteuid(geteuid(me));
                        new1 = new(base_name(ob));
                        new1->be_ghost(1);
                        new1->set("combat_exp", ((int) new1->query("combat_exp"))*10);
                        inv=all_inventory(new1);
                        for(i=0;i<sizeof(inv);i++)
                                destruct(inv[i]);
                        new1->move(room);       
                        new1->set("title",HIB "�л�"NOR);
        msg +=  "Ũ���ƺ���$N��߽�����Ũ����һ����Ӱ������\n" NOR;
                new1->start_call_out((: call_other, __FILE__, "melt", new1 :), 
(int)me->query_skill("cursism")/10 + 10);
                me->set("timer/ghostcurse",time());
                me->add_temp("apply/astral_vision", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 10);
                }
        else
        msg += "Ũ��������ʧ�ˣ�����\n"NOR;
        message_vision(msg, me);
} 
void melt(object ob)
{
        message_vision("$N�������黯����ʧ�ˣ�����\n",ob);
        destruct(ob);
} 
void remove_effect(object me)
{
        me->add_temp("apply/astral_vision", -1);
        tell_object(me, "��ͻȻ�������Լ����еĹ�ꡣ\n");
} 