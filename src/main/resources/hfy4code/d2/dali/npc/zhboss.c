// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�ӻ����ϰ�", ({ "zahuoboss" ,"boss"}) );
        set("gender", "����" );
        set("age", 55);
        set("long",
                "һ��������Ц���ӻ����ϰ塣\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([
                "d/dali/obj/huapot" : 10,
                "d/dali/obj/caidao" : 10,
                "d/dali/obj/lighter" : 10,
                "d/dali/obj/bow" : 10,
                "d/dali/obj/liandao" : 10,
                "d/dali/obj/cloth" : 10,
                "d/dali/obj/fpole" : 10,
                "d/dali/obj/diechai" : 10,
        ]) );
        set_skill("unarmed",100);
        set_skill("dodge",200);
        setup();
//        if (!random(2)) carry_object("d/dali/npc/obj/xiushu");
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
message_vision("$N��$n˵����ӭ����ӭ�������ʲô�Լ����ɡ�\n",this_object(),ob);
                        break;
        }
}