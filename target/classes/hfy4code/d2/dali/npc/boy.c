inherit NPC;
int give_him();
void create()
{
        set_name("光屁股的小孩儿", ({ "boy","little boy" }) );
        set("gender", "男性" );
        set("age", 5);
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("per",2);
        set("chat_chance", 5);
        set("chat_msg", ({
                "光屁股的小孩儿拍打着水面，泛起片片涟漪.\n",
                "光屁股的小孩儿说道：太好玩了！！\n",
        }) );
        setup();
}