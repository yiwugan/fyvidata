 inherit NPC;
inherit F_VENDOR;
int wieldstaff();
void create()
{
        set_name("胭松", ({ "yan song", "song" }) );
        set("gender", "女性" );
        set("age", 22);
        set("per", 30);
        set("class","lama");
        set("long",
                "胭松是葛伦高僧的得意二弟子。\n");
        create_family("大昭寺", 21, "弟子");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set_skill("iron-cloth", 100);
        set_skill("jin-gang", 10);
        set_skill("lamaism", 10);
        set_skill("unarmed", 100);
        set_skill("staff", 100);
        set_skill("lamastaff", 100);
        set_skill("bloodystrike", 100);
        map_skill("unarmed", "bloodystrike");
        map_skill("staff", "lamastaff");
        map_skill("iron-cloth", "jin-gang");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fefawubian" :),
                (: wieldstaff  :)
        
        }) );   
        set("inquiry", ([
                "舍利子": "嗯....你出银子，我卖给你。\n",
                "真舍利子": "嗯....我派人送入关，但那人死在大漠中了。\n",
        ]) );
        set("vendor_goods", ([
                __DIR__"obj/fake-tooth":30,
        ]) );
        setup();
        carry_object(__DIR__"obj/whtclothh")->wear();
        carry_object(__DIR__"obj/5staff");
        
}       
int wieldstaff()
{
command("wield all");
perform_action("staff.fofazhizun");
command("unwield all");
return 1;
}
