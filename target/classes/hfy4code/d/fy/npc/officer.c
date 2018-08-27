 // post_officer.c
inherit NPC; 
string send_mail();
string receive_mail(); 
void create()
{
        set_name("����", ({ "officer", "post officer" }) );
        set("title", "�������䳤");
        set("gender", "����" );
        set("age", 43);
        set("long",
                "���絣�η�������䳤�Ѿ��м����ˣ��˺ܺã�\n"
                "���������ķ����൱����������������վ�������졣\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
                "��վ" : "�ǰ�... ������Ƿ������Ҫ���Ż�������",
                "����" : (: send_mail :),
                "����" : (: receive_mail :),
                "mail" : (: receive_mail :),
        ]) );
        set_skill("literate", 70);
        set_skill("unarmed", 400);
        setup();
        add_money("coin", 70);
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{       
        ::init();
        add_action("do_rent","rent");
} 
string send_mail()
{
        object mbox; 
        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
   seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "Ŷ... Ҫ������������������䣬���ŵķ�����������˵����\n";
} 
string receive_mail()
{
        object mbox; 
        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ������е��Ŷ������档\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
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
        ob=new(__DIR__"obj/carriage");
    ob->move(environment());
        message_vision("$Nʻ�˹��� \n",ob); 
    chefu=new(__DIR__"chefu");
    chefu->move(environment());
    chefu->get_quest("/d/fy/carriageway");
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
