inherit NPC;
void create()
{
        set_name("ɨ�صĺ���", ({ "monk", "heshang"}) );
        set("gender", "����" );
        set("age", 12);
        set("long", "һ�������µ�С���У�����æ��ɨ�ء�\n");
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set_skill("unarmed", 5+random(100));
        set_skill("move",30);
        set_skill("dodge", 40);
        set_skill("force",100);
        set("force",100);
        set("force_factor",20);
        set("max_force",1000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}