 //
inherit NPC;
inherit F_VENDOR; 
void create()
{
    set_name("�������ͷ", ({ "old man", "rednose man" }) );
    set("gender", "����" );
        set("nickname", "�������Ƶ�");
    set("age", 50);
    set("long",
            "���������������ڣ�������ȴ����������֪������������������
Ϊ�����ӹ��ò������������Լ�ȴ���ú����⡣ \n");
        set("per", 4);
        set("combat_exp", 100);
    set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������ͷ���������е������������ġ���Ҷ�࡯һ���¶��о���������
�Ǿ����㣬�����¡��ǣ�����Ҳ���硣\n",
                "�������ͷ�����е������������ġ���Ҷ�࡯���͹��Ǻ�����ɣ��������
��������������Ҳ�Ȳ��������ĺþ��ˡ�\n", 
        })); 
    set("vendor_goods", ([
        __DIR__"obj/wineskin" : 10,
        __DIR__"obj/horsebean" : 10,
        __DIR__"obj/peanut" : 10,
    ]) );
    setup();
    carry_object("/obj/armor/cloth")->wear();
        
} 
void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}    
