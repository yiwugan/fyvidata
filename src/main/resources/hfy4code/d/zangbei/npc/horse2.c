 inherit NPC;
#include <ansi.h>
string horsedesc();
void create()
{
        set_name("�쿥��", ({ "red horse","horse" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 3);
       //set("long", "һƥƤë������Ұ���������ڵ�����ɱ��ţ���֪�Ƿ����ѱ����������������\n");
        set("long",(: horsedesc :));
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
                set("int",40);
        set("cor",80);
        set("str",50);
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "hoof"}) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
                  "�쿥���ԡ������ԣ������쳤Х�˼�����\n",
        }) );
        set("combat_exp", 3000000);
        set_temp("apply/attack", 300);
        set_temp("apply/dodge",300);
        set_temp("apply/armor", 100);
        set_temp("apply/damage",200);
        setup();
}
void init()
{
        add_action("do_xunfu","xunfu");
        add_action("do_ride","ride");
} 
string horsedesc()
{
        object me;
        me = this_player();
   if (me ->query_temp("marks/ѱ��_�쿥��"))
        {       
                return "���ϣ�����壩��ƥ��������ܵ����������һ�ߡ�\n";
        }
        return "һƥƤë����Ӱ������Ұ���������ڵ�����ɱ��ţ���֪�Ƿ����ѱ����������������\n";
} 
int do_xunfu(string arg)
{
        object me;
        if (arg != "�쿥��" && arg != "red horse" && arg != "Ұ��" && arg!= "horse" )
                return notify_fail("��Ҫѱ��ʲô��\n");
        
        me = this_player();
        if (me->query_temp("marks/ѱ��_�쿥��"))
                return notify_fail("��ƥҰ���Ѿ�����ѱ���ˡ�\n");
        
        message_vision("$N��˻һ������β̤�㣬���߿񱼣�Ӳ��Ҫ��$n������������ \n",this_object(),me);
        
        if (me->query_skill("dodge",1) >=100 && me->query_skill("animal-talk",1)>=150 && me->query_skill("animal-training",1)>=150)
        {
                message_vision(HIC"$n����ץס���ף�����$N������������̩ɽ�㸽������\n "NOR,this_object(),me);
                message_vision("$N���ڰ�����������ѱ���ش��Ŵ�������\n$n�����������$N��ͷ��������Ծ��������\n",this_object(),me);
                if (!me->query("marks/ѱ��_Ұ��"))
                {
                        me->add("potential",500);
                        me->add("score",100);
                        tell_object(me,"�㱻�����ˣ�\n��ٵ�Ǳ��\nһ�ٵ��ۺ�����\n\n");
                        me->set("marks/ѱ��_Ұ��",1);
                }
                me->set_temp("marks/ѱ��_�쿥��",1);
        }else   {
                message_vision("$n���ڲ�֧����$N����ˤ��������\n",this_object(),me);
                me->unconcious();
        }
        return 1;
} 
int do_ride(string arg)
{
        object me,room;
        
   if (arg != "�쿥��" && arg != "red horse" && arg != "Ұ��" && arg!="horse")
                return notify_fail("��Ҫ��ʲô��\n");
        
        me = this_player();
        if (!me->query_temp("marks/ѱ��_�쿥��"))
                return notify_fail("����Ҫ��ѱ����ƥ����\n");;
        
        return notify_fail("�쿥�����εؿ�����˵��������˵�Ǹ��ط������ܿ��ţ��õ��ĵ�һ����\n");
        
        message_vision(HIC"$n�����������쳤Хһ������������˫�ȼн���������һ�ޡ��� ��\n\n"NOR,this_object(),me);
        message_vision(HIW"$N���Ծ����һ���������ҡ���Խ������һ����̬�����ƣ��������ë 
��ɽ�������ɵ�Ʈ����������пգ�������ﻮ��һ�������Ļ��ߣ��������� 
Զ����Ũ��� \n"NOR,this_object(),me);
                if (!room=find_object(AREA_ZANGBEI"lake1")) 
                        room=load_object(AREA_ZANGBEI"lake1");
                me->move(room);
                message_vision("$N�������󣬳��ź쿥����������\n",me);
                message_vision("$NԾ�������쿥��̤���ȥ��\n",me);
        destruct(this_object());
        return 1;
}
