// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("Ʒ���ʿ", ({ "jushi" }) );
        set("gender", "����" );
        set("age", 52);
        set("long",
                "һλ�׷����׵����ߣ���Ʒ���ж���֮����\n");
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
                        say( "Ʒ���ʿЦ�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����֪�������������ʲô��\n");
                        break;
                case 1:
                        say( "Ʒ���ʿ΢Ц��˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}