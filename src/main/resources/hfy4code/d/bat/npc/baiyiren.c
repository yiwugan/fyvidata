 inherit NPC;
#include <ansi.h>  
void create()
{
        set_name("东海白衣人", ({ "white cloth man", "man" }) );
        set("nickname", HIC "一剑震神州" NOR );
        set("gender", "男性");
        set("age", 32);
        set("long",
"
这是一位武功盖世的东瀛武士，曾以一剑横扫中原武林,
所向无敌，后来败在紫衣侯的手中，遂不知其去向。
\n"
        );
        create_family("樱花", 1, "武士"); 
        set("attitude", "heroism");
        set("combat_exp", 4500000);
        set("score", 200000);
 
        set("reward_npc", 1);
        set("difficulty", 20);
        set("class","ninja");
        set("chat_chance", 1);
        set("chat_msg", ({
"东海白衣人轻蔑的道：你们中国武士真是不堪一击！\n",
"东海白衣人傲然道：我代表大和武士向你挑战，敢不敢接受？\n",
"东海白衣人冷冷道：我一剑就可以横扫你们的江湖！\n",
        }) ); 
        set("agi",45);
        set("int",30);
        set("str", 40);
        set("cor", 300);
        set("cps", 30);
        set("con", 30);
                       
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor",90);
        set("mana",1500);
        set("max_mana",1500); 
        set_skill("unarmed", 200);
        set_skill("ghosty-force",300);
        set_skill("enmeiryu",180);
        set_skill("ittouryu",160);
        set_skill("ninjitsu",200);
        set_skill("dodge", 180);
        set_skill("ghosty-steps",200);
        set_skill("blade",160);
        set_skill("literate", 140);
        set_skill("force", 180);
        set_skill("parry", 140);
        set_skill("magic", 100);
        
        map_skill("magic", "ninjitsu");
        map_skill("unarmed", "enmeiryu");
        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("force", "ghosty-force");
        map_skill("dodge", "ghosty-steps");
        
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.shiden" :),
                (: perform_action, "unarmed.shimon" :), 
                          }) );  
        setup(); 
        carry_object("/obj/weapon/sword_katana");
        carry_object("/obj/armor/cloth",
                        ([      "name"  :       HIW"樱花武士服"NOR,
                                "armor_prop/armor":     8,
                                "long"  : 0 ])
                        )->wear();
}
void init(){
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
} 
void win_enemy(object loser)
{
say("东海白衣人「哼」地一声，说道：便是有这许多不堪一击的家伙....\n"); 
}
void lose_enemy( object winner)
{
        object gweapon;
        say("\n东海白衣人讶然道：终於遇见一个对手了， 高处不胜寒！\n\n");
        if (winner->query("class")=="shenshui" && winner->query_temp("marks/bai_ask"))
        if (!winner->query("marks/胜白衣人")) {
                winner->set("marks/胜白衣人",1);
                message_vision(CYN"东海白衣人道：此刀赠与阁下，以表敬意。\n"NOR,this_object());
                if (!gweapon=present("black blade",this_object())){
                        gweapon = new("/obj/weapon/sword_katana");
                        gweapon->move(this_object());
                        }       
                gweapon->move(this_player());
        }
} 
int accept_fight(object me)
{
        message_vision(WHT"东海白衣人长吸一口气，浑身骨节喀喀作响。\n"NOR,this_object());
        set("kee",this_object()->query("max_kee"));
        set("sen",this_object()->query("max_sen"));
        command("say 好，让我们切磋一下武功！\n");
        return 1;
} 
int heal_up()
{
 this_object()->start_busy(0);
 ::heal_up();
 return 1;
}
