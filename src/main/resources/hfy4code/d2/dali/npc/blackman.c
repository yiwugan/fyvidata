inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��������", ({ "black younger" }) );
        set("gender", "����" );
        set("age", 25);
        set("str", 46);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("force_factor", 10);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 10000);
        set("force", 10000);
        set("max_mana", 300);
        set("mana", 300);

        set("long",     "������������Ժ�Ļ�ơ�\n");


        set("combat_exp", 500000);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 80);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

        set("chat_chance", 2);
        set("chat_msg", ({
                "����������૵����������ô�ߣ�������\n",
        }) );

        set("vendor_goods", ([
                __DIR__"obj/bqi":20,
                __DIR__"obj/bqi1":20,
        ]) );

        setup();

        carry_object(__DIR__"obj/bqi1")->wield();
        carry_object(__DIR__"obj/bcloth")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
}
