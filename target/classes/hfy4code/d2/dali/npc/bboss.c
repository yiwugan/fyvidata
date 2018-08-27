// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("兵器铺老板", ({ "bingboss" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long",
                "一个满脸堆笑的老板。\n");
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
message_vision("$N对$n说：我这里有最好的兵器，来点什么？\n",this_object(),ob);
                        break;
        }
}