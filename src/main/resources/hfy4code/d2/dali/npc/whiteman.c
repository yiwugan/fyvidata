inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��������", ({ "white younger","younger" }) );
        set("gender", "����" );
        set("age", 22);
        set("str", 46);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("max_atman", 3000);
        set("atman", 3000);
        set("max_force", 10000);
        set("force", 10000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("force_factor", 50);


        set("long",     "������������Ժ�Ļ�ơ�\n");


        set("combat_exp", 500000);
//        set("attitude", "friendly");
//        set("rank_info/respect", "����");

        set_skill("unarmed", 100);
        set_skill("throwing", 250);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 91);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

        set("chat_chance", 5);
        set("chat_msg", ({
                "���������µ����㵽�ǿ����߰���������\n",
        }) );

        set("vendor_goods", ([
                __DIR__"obj/wqi":20,
                __DIR__"obj/wqi1":20,
                __DIR__"obj/wqi2":20,
        ]) );

        setup();

        carry_object(__DIR__"obj/wqi1")->wield();
        carry_object(__DIR__"obj/wcloth")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
}