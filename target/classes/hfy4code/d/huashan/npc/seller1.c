 //
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("卖面的老头子", ({ "lao zhang", "zhang" }) );
        set("gender", "男性" );
        set("age", 57);
        set("long",
                "他的确已很老了，须发都已斑白，此刻正坐在那里，低着头喝面汤，
挂在摊头的纸灯笼已被油烟熏得又黑又黄，就像是他的脸。\n");
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
