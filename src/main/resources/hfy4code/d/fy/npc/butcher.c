  // butcher.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR; 
int tell_him();
void create()
{
        set_name("�����", ({ "butcher", "da" }) );
        set("title", "��������");
        set("gender", "����" );
        set("age", 35);
        set("long", "һ����������ӣ��ͺ���ļһ\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 25000);
                set("chat_chance", 1);
        set("chat_msg", ({
                "�����̾�˿�����Ī���ҵķ����д�������ĥ�������û�������\n",
        }) ); 
                set("inquiry", ([
                "����" : (: tell_him :),
                "ĥ��" : (: tell_him:),
                "ĥ��ʯ" : (: tell_him:),
                "�Ҷ���ţͼ��" : (: tell_him:),
        ])); 

        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set("vendor_goods", ([
                __DIR__"obj/yangtou": 22,
                __DIR__"obj/zhutou" : 22,
                __DIR__"obj/niutou" : 22,
        ]) ); 
        setup();
        add_money("coin", 2);
        carry_object("/obj/armor/cloth")->wear(); 
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
        add_action("do_spare","spare");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 2:
                        say( "������ֿ�����, Ц�ŵ�����λ"  
                                + RANK_D->query_respect(ob)
                                + "��Ҫ��������? \n");
                        break;
        }
} 
 
int do_spare(string arg)
{
        object me;
        object obj;
        string file;
        me = this_player();
        if(!arg) return notify_fail("ָ�spare <name>\n");
                if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û��"+arg+"��\n");
        if(base_name(obj) == "/obj/npc/pet" && obj->query("owner") == me->query("id")
        && obj->query("possessed") == me)
        {
        message_vision("$N�Դ����˵�������Ҵ����$n�����Լ����̶��֣���\n",me,obj);
        message_vision("$N����һ���������꣢һ��Ť����$n�Ĳ��ӣ�\n",this_object(),obj);
        seteuid(ROOT_UID);
        file = obj->query_save_file()+".o";
        obj->die();     
        rm(file);
        seteuid(getuid());
        return 1;
        }       
        return notify_fail("�㲻������ô����\n");
} 
void reset(){ 
    set("vendor_goods", ([
            __DIR__"obj/yangtou": 22,
            __DIR__"obj/zhutou" : 10,
            __DIR__"obj/niutou" : 10,
    ]) );       
}   
int tell_him()
{
    object me;
    me =this_player();
        
    tell_object(me,"����ӵ����۴�ʦ���˿鱦ʯ��ĥ�������ǵ����ǻ���������Ҷ������׷����ͺ��ˣ�\n");
               
    return 1;
} 

int accept_object(object me, object obj)
{
        object iron;
        if( (string) obj->query("name") == "�Ҷ���ţͼ��")
        {
                obj = new(__DIR__"obj/giron");
                message_vision(NOR"\n$Nһ������ͼ����˼��飬����������$n����˵����������\n"+CYN"$N˵�����������᷽������׷������۴�ʦ���ҵ���ĥ����ʯͷ�ҾͲ�Ҫ�ˡ�\n" + NOR"$N���ְѰ��ϵ�"+obj->name() + NOR"�ӵ����ϣ������ζ���о���ͼ������\n"+"$n��$N���������ϼ�����ϵ�"+obj->name()+NOR"���뻳�С�\n\n"NOR, 
                            this_object(),this_player() );

                        iron = new(__DIR__"obj/giron");
                        if(iron) iron->move(this_player());
                        
                        
           return 1;       
        }
        else {return notify_fail("����ӹŹŹֵֹ�����һ�ۣ�ת����ȥ�����ɻ\n");}
            
        return 1;
} 
