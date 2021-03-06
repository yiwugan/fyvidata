 // bandit.c
#include <ansi.h>
inherit NPC;
void create() {
    set_name("土匪", ({ "tufei", "bandit"}) );
        set("title", "黄风山");
    set("long","一个满脸伤疤加横肉的家伙。\n");    
    set("attitude", "aggressive");
    set("vendetta/authority",1);
    set("per", 1);
    set("intellgent",1);
        set("pursuer",1);
    set("combat_exp", 100000+random(400000));
        set("bellicosity", 10000);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
            name()+ "喝道：今天老子要钱又要命！！\n",
            name()+ "笑道：贼娘的，去死吧！\n",
                        HIR+ name()+ HIR"大喊：砍死一个够本，砍死两个赚一个！！\n"NOR,
    }) ); 
    set_skill("unarmed", 70+random(50));
    set_skill("axe", 70+random(50));
    set_skill("blade", 70+random(50));
    set_skill("hammer", 70+random(50));
    set_skill("sword", 70+random(50));
    set_skill("parry", 70+random(50));
    set_skill("dodge", 70+random(50));
    set_skill("move", 100+random(50)); 
    set_temp("apply/attack", 70);
    set_temp("apply/dodge", 70);
    set_temp("apply/armor", 70);
    set_temp("apply/damage", 30+random(200));
    set_temp("apply/move", 100); 
    setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/food_item/chicken_leg");
        carry_object("/obj/food_item/wineskin");
} 
