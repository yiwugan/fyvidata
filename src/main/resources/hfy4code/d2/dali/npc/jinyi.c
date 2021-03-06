#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "锦衣卫士" NOR, ({ "jinyi weishi", "weishi"}) );
        set("title","皇宫");
        set("gender", "男性" );
        set("age", 25);
        set("long", "他一身五彩锦衣，腰佩宝刀，真有说不出的威风。\n");
        set("combat_exp", 700000);
        set("attitude", "friendly");
        set_skill("sword", 90+random(100));
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("duan-sword", 80);
        set_skill("duan-force", 80);
        set_skill("iron-cloth", 200);
        map_skill("force","duan-force"); 
        map_skill("sword","duan-sword"); 
        map_skill("parry","duan-sword"); 
        set("chat_chance", 2);
        set("chat_msg", ({
                "锦衣卫士向你喝道：皇宫里不要乱跑！！\n",
                "锦衣卫士向你喝道：站住！！干什么的？？\n",
        }) );
        
        setup();
        add_money("silver", 150);                                               carry_object(__DIR__"obj/jinyi")->wear();
        carry_object("obj/weapon/sword")->wield();
}