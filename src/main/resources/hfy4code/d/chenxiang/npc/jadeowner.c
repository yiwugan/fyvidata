 inherit NPC;
inherit F_VENDOR; 
void create()
{
    set_name("郑甲", ({ "zhengjia", "zheng" }) );
    set("gender", "男性" );
    set("age", 39);
    set("title", "珠宝商");
    set("long", "这里卖的玉都是上等的缅玉，而且价钱合理。\n");
    set("combat_exp", 7000);
    set("attitude", "friendly");
    set_skill("dodge", 100);
    set_skill("parry", 120);
    set("vendor_goods", ([
        __DIR__"obj/jade1":7,
        __DIR__"obj/jade2":7,
        __DIR__"obj/jade3":7,
        __DIR__"obj/jade4":7,
        ]) );
    set("inquiry", ([
        "玉脖套" : "我这没有的卖，不过你可以买几块缅玉弧然后找石匠加工嘛。\n",
        "yubotao" : "我这没有的卖，不过你可以买几块缅玉弧然后找石匠加工嘛。\n",
        "王石匠" : "王石匠？他不会理你的，除非你认得“一石谷捣得三斗米”。\n",
        "wang" : "王石匠？他不会理你的，除非你认得“一石谷捣得三斗米”。\n",
        ]));
    setup();
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
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " 郑甲笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉可以消灾，买几块吧？ \n");
                        break;
                case 1:
                        say( " 郑甲笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉是吉祥之物，多买几块吧。 \n");
                        break; 
        }
}   
void reset()
{
    set("vendor_goods", ([
        __DIR__"obj/jade1":7,
        __DIR__"obj/jade2":7,
        __DIR__"obj/jade3":7,
        __DIR__"obj/jade4":7,
        ]) );
} 
