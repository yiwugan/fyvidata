 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("����", ({ "waiter" }) );
        set("gender", "����" );
    set("title", "�ϰ�" );
        set("age", 62);
        set("long",
                "һ����ͷ��Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set_skill("iron-cloth", 2000);
        set_skill("unarmed", 100);
        set_skill("bloodystrike", 50);
        map_skill("unarmed", "bloodystrike");
        set("rank_info/respect", "�϶���");
        set("vendor_goods", ([
                __DIR__"obj/junksword":10,
                __DIR__"obj/junkblade":10,
                __DIR__"obj/junkstaff":10,
                __DIR__"obj/jade3":10,
                "/obj/item/bag":10,
        __DIR__"obj/huboots":2,
                __DIR__"obj/wineskin":10,
        __DIR__"obj/guskin":3,
                __DIR__"obj/sheep_leg":10,
                __DIR__"obj/snake_drug":10,
                __DIR__"obj/movebook":10, 
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
        add_action("do_rent","rent");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "���ϰ�����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "���ϰ������ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say( "���ϰ�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȼ���С��ľưɣ��⼸��Ŵӽ����￪���Ӵ��\n");
                        break;
        }
} 
int do_rent(string arg)
{ 
        object ob, chefu;
        object me = this_player();
        object silver;
        if (arg != "carriage" && arg != "mache")
        {
                return notify_fail("��Ҫ��ʲô��\n");
        } 
        if (query("mark/rented"))
        {
                return notify_fail("���Ѿ����ȥ�� \n");
        }
        silver=present("silver_money", me);
    if(!silver) return notify_fail("������û������ѽ��\n");
        if (silver->query_amount()<8) return notify_fail("���Ǯ������\n");
    silver->add_amount(-8); 
        ob=new("/d/fy/npc/obj/carriage");
    ob->move(environment());
        message_vision("$Nʻ�˹��� \n",ob); 
    chefu=new("/d/fy/npc/chefu");
    chefu->move(environment());
    chefu->get_quest("/d/guanwai/guanwaicarriageway");
    chefu->set_carriage(ob);
        message_vision("$N���˹��� \n",chefu); 
        set("mark/rented",1);
        message_vision("$N�����ţ��������� \n",me);
        me->move(ob);
        chefu->go_now();
        
        call_out("check_status",30,chefu);
        return 1;
} 
int check_status(object ob)
{
        if (!ob)
        {
                set("mark/rented",0);
        }else
        {
                call_out("check_status",30,ob);
        }
} 
void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/junksword":10,
                __DIR__"obj/junkblade":10,
                __DIR__"obj/junkstaff":10,
                __DIR__"obj/jade3":10,
                "/obj/item/bag":10,
        __DIR__"obj/huboots":2,
                __DIR__"obj/wineskin":10,
        __DIR__"obj/guskin":3,
                __DIR__"obj/sheep_leg":10,
                __DIR__"obj/snake_drug":10,
                __DIR__"obj/movebook":10, 
        ]) );
}       
