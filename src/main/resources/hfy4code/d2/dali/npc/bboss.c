// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�������ϰ�", ({ "bingboss" }) );
        set("gender", "����" );
        set("age", 35);
        set("long",
                "һ��������Ц���ϰ塣\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([
                "d/dali/obj/huadao" : 3,
                "d/dali/obj/longsword" : 3,
        ]) );
        set_skill("unarmed",100);
        set_skill("dodge",200);
        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N��$n˵������������õı���������ʲô��\n",this_object(),ob);
                        break;
        }
}