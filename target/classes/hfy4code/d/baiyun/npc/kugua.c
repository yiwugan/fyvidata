 inherit NPC;
void create()
{
        set_name("苦瓜大师", ({ "kugua dashi","kugua" }) );
        set("gender", "男性" );
        set("class", "shaolin");
        set("age", 52);
        set("str", 26);
        set("cor", 14);
        set("cps", 29);
        set("int", 25);
        set("long", "一个面貌清峻，须眉尽白的老和尚。虽然苦瓜大师不擅武道，但他的厨艺却为\n天下无双，由他亲手烹制的素斋更是名满天下。\n");
        set("combat_exp", 100000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "苦瓜大师绕着斩蟒台走了几圈，脸色愈来愈苍白，浑身有如电击，竟战栗起来。\n",
        }) );
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        setup();
        carry_object(__DIR__"obj/sengyi")->wear();
}
int accept_fight(object me)
{
        command("say 善哉善哉，老衲年事已高，不通武道，施主勿开玩笑。\n");
        return 0;
}       
