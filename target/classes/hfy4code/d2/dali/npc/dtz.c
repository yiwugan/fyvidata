// dtz.c

inherit NPC;

void create()
{
        set_name("�ḡ����", ({ "younger" }) );
        set("gender", "����" );
        set("age", 16);
        set("long", "һ���������µ��ḡ����.\n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );

        setup();
        add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        
}