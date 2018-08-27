inherit NPC;
void create()
{
        set_name("浇水的和尚", ({ "monk", "heshang"}) );
        set("gender", "男性" );
        set("age", 12);
        set("long", "一个天龙寺的小和尚，正在给茶花浇水。\n");
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set_skill("unarmed", 5+random(100));
        set_skill("move",30);
        set_skill("dodge", 40);
        set_skill("force",100);
        set("force",100);
        set("force_factor",20);
        set("max_force",1000);
        
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}