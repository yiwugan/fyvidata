 //
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("�������ͷ��", ({ "lao zhang", "zhang" }) );
        set("gender", "����" );
        set("age", 57);
        set("long",
                "����ȷ�Ѻ����ˣ��뷢���Ѱ߰ף��˿��������������ͷ��������
����̯ͷ��ֽ�����ѱ�����Ѭ���ֺ��ֻƣ���������������\n");
                set("per", 5);
                set("combat_exp", 10);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/soup" : 10,
            __DIR__"obj/soup1" : 10,
            __DIR__"obj/soup2" : 10,
            __DIR__"obj/soup3" : 10,
            __DIR__"obj/soup4" : 10,
            __DIR__"obj/soup5" : 10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}   
