#include <ansi.h>
inherit NPC;
void use_poison();
void sonic_attack();
void create()
{
    set_name(HIY"金甲武士"NOR, ({ "golddoor guardian", "guard" }) );
//      set_title("荧河守护武士");
    set("age", 400);
    set("long", "一个金盔金甲的武士，面目被金盔全部挡住，奇怪的是他的背后有一双黑翼。\n");
    set("attitude", "heroism");
    set_skill("dodge", 250+random(100));
    set_skill("move", 450+random(200));
    set("combat_exp", 1000000+random(2000000));
        set("bellicosity", 300);
        set("invisibility",1);
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
//            (: sonic_attack :),
    }) ); 
    setup();
}      
