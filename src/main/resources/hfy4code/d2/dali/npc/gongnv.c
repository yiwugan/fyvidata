// taijian.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("小宫女", ({ "xiao gongnv","gongnv" }) );
        set("gender", "女性" );
        set("age", 14);
        set("long",
                "她是一个入宫不久的小宫女，还未通世事。\n");
        set("title","皇宫");
        set("int",14);
        set("str",12);
        set("cor",14);
        set("int",20);
        set("per",30);
        set("combat_exp", 250);
        set("attitude", "friendly");
        set_skill("dodge",50);
        setup();
}