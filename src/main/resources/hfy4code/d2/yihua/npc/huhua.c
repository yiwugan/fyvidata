#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name(HIW"百合"NOR, ({ "bai he", "he" }) );
        set("title", "移花宫护花使者");
        set("gender", "女性" );
        set("age", 35);
        set("long", "一个风情万种的女人。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 1250000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tiannvsanhua" :),
        }) );
        set_skill("sword", 80);
        set_skill("lanhua-sword",80);
        set_skill("yanyu-steps",80);
        set_skill("dodge",60);
         map_skill("dodge", "yanyu-steps");
          map_skill("sword", "lanhua-sword");
       
        add_money("gold", 10);
       // carry_object(__DIR__"obj/cq1")->wield();

}

