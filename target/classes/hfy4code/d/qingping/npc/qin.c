 // thousand_hand.c
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("琴儿" , ({ "qiner", "qin er", "girl" }) );
        set("long", "一位十二三岁的小丫头。\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500); */
        set("age", 13);
        set("gender", "女性" );
        set("inquiry", ([
        ]) );
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */ 
        set("combat_exp", 5000);
        set_skill("dodge", 50+random(50));
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(AREA_CHUENYU"obj/yellow_flower")->wear();
} 
