// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��С��", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("vendor_goods", ([
                "/d/dali/obj/jiduan" : 10,
                "/d/dali/obj/frsq" : 10,
                "/d/dali/obj/jxys" : 10,
                "/d/dali/obj/qszp" : 10,
                "/d/dali/obj/hyxz" : 10,
                "/d/dali/obj/jiudai" : 10,
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
                        say( "��С��Ц�����˵������λ" + RANK_D->query_rank(ob)
                                + "�������ȿھƣ�ЪЪ�Ű�,˳��Ʒ��һ�´���ķ�ζС�ԡ�\n");
                        break;
                case 1:
                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_rank(ob)
                                + "����������\n");
                        break;
                case 2:
                        say( "��С��˵������λ" + RANK_D->query_rank(ob)
                                + "�������ȼ���С��Ĳ軨�ưɣ�����Ǳ��ص��ز�Ӵ��\n");
                        break;
        }
}