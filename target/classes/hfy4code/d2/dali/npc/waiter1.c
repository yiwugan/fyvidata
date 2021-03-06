// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("品香居士", ({ "jushi" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long",
                "一位白发长髯的老者，对品茶有独到之处。\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "/d/dali/obj/mx" : 10,
                "/d/dali/obj/teapot" : 10,
        ]) );
        setup();
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
        switch( random(3) ) {
                case 0:
                        say( "品香居士笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，你可知道大理的名茶是什么吗？\n");
                        break;
                case 1:
                        say( "品香居士微笑着说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}