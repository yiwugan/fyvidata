 // tea_waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("�販ʿ", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "�販ʿ��æ���к�����, һ�����Ų��, һ������Ĩ��\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "�販ʿ");
        set("vendor_goods", ([
                "/obj/food_item/teapot": 10,
                "/obj/food_item/dumpling": 10,
                "/obj/food_item/chicken_leg": 20,
                __DIR__"obj/longjin":10,
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
                        say( "�販ʿЦ�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "�販ʿ��ë��Ĩ��Ĩ���ŵ�һ�����ӣ�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say( "�販ʿ˵������λ" + RANK_D->query_respect(ob)
                                + "�����������Ųɵ��²�Ҷ����! ���㰡!...\n");
                        break;
        }
}       
