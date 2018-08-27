// dtz.c

inherit NPC;

void create()
{
        set_name("轻浮少年", ({ "younger" }) );
        set("gender", "男性" );
        set("age", 16);
        set("long", "一个无所事事的轻浮少年.\n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );

        setup();
        add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        
}