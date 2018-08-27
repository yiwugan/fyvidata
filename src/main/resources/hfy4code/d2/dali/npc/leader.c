#include <ansi.h>
inherit NPC;

void create()
{
        set_name("侍卫头" , ({ "guard leader","leader"}) );
        set("gender", "男性" );
        set("age", 25);
        set("long", "他是个皇宫里的守卫头。\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set_skill("sword", 90+random(100));
        set_skill("dodge", 100);
        set_skill("duan-sword", 100);
        set_skill("iron-cloth", 200);
        map_skill("sword","duan-sword"); 
        set("chat_chance", 2);
        set("chat_msg", ({
                "侍卫头向侍卫说道：好好干！！\n",
                "侍卫头笑着对侍卫说道：咱们这差使，多好！！好好干吧！！\n",
        }) );
        
        setup();
        add_money("silver", 150);                                                                       carry_object(__DIR__"obj/tengjia")->wear();
        carry_object("/obj/weapon/sword")->wield();
}