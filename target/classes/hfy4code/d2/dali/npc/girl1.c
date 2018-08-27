// dtz.c

inherit NPC;
int random_action();
void create()
{
        set_name("苗族姑娘", ({ "girl" }) );
        set("gender", "女性" );
        set("age", random(5)+10);
        set("long", "一个美丽又善良的苗族姑娘\n");
        set("per",30);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_action :),
                (: random_move :)
        }) );

        setup();
        add_money("silver", 10);
        carry_object("/obj/cloth")->wear();
        
}

int random_action()
{
switch(random(5)){
        case 0:
                command("wink");
                break;
        case 1:
                command("smile");
                break;
        case 2:
                command("scowl");
                break;
                }
}