// taijian.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("小太监", ({ "xiao taijian","taijian" }) );
        set("gender", "男性" );
        set("age", 14);
        set("long",
                "他是一个入宫不久的小太监，还未通世事。\n");
        set("title","皇宫");
        set("int",14);
        set("str",12);
        set("cor",14);
        set("int",20);
        set("per",30);
        set("combat_exp", 250);
        set("attitude", "friendly");
//        set("rank_info/respect", "李老四");
        set("chat_chance", 3);
        set("chat_msg", ({
                "这儿真安静啊．．\n",
  //            (: random_move :),
        }) );
        set_skill("dodge",50);
        setup();
}