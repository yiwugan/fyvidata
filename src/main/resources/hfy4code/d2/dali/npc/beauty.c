// dog.c

inherit NPC;

void create()
{
        string *order=({"��", "��", "��", "��","��","��"});
        set_name((order[random(6)]) +"����", ({ "beauty"}) );

        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ��ɫ�ĺ�����\n");
        
        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 2);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "�����ڻ���������衣\n",
        }));
        set("arrive_msg","���˹���");
        set("leave_msg","�ɿ���");
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);

        setup();
}