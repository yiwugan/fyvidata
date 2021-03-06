// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("店小二", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ([
                "/d/dali/obj/jiduan" : 10,
                "/d/dali/obj/frsq" : 10,
                "/d/dali/obj/jxys" : 10,
                "/d/dali/obj/qszp" : 10,
                "/d/dali/obj/hyxz" : 10,
                "/d/dali/obj/jiudai" : 10,
                "/d/fy/npc/obj/dan" : 2,   
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
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝口酒，歇歇脚吧,顺便品尝一下大理的风味小吃。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "店小二说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝几盅小店的茶花酒吧，这可是本地的特产哟。\n");
                        break;
        }
}
