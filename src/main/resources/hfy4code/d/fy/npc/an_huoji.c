#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("安生店伙计", ({"huo ji"}) );
    set("gender", "男性" );
    set("long", "安生堂新来的活计，忙时帮着老板招呼客人，没事就拿着把刨斧修补棺木。\n");
    set("attitude", "friendly");
    set("age", 25);
    set("cor", 25);
    set("cps", 25);
    set("combat_exp", 380000);
    
    set("force_factor", 30+random(30));
    set("force",100);
    set("max_force",100);
    
    set_skill("axe",100);
    set_skill("unarmed", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("move", 100);
    set_skill("wuche-axe",60);
    set_skill("puti-steps",100);
    
    map_skill("dodge","puti-steps");
    map_skill("axe","wuche-axe");
    map_skill("parry","wuche-axe");
    setup();
    carry_object(__DIR__"obj/heicloth")->wear();
    carry_object(__DIR__"obj/paoaxe")->wield();
}   
