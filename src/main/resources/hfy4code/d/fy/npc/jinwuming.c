 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER; 
void smart_fight();
void smart_busy();
void smart_attack(); 
int leave();
#include <ansi.h>
void create()
{
    set_name("荆无命", ({ "master jin", "master", "master jinwu" }) );
    set("nickname", RED"左手剑"NOR);
    set("gender", "男性" );
    set("age", 44);
    set("class","assassin");
    set("reward_npc", 1);
    set("difficulty", 10); 
    set("cor", 40);
    set("cps", 30);
    set("int", 30);
    set("str", 15);
    set("per", 3);
    set("agi",25);
        set("ill_boss",5);
    set("attitude","friendly");
    set("max_force", 2500);
    set("force", 2500);
    set("force_factor", 20);  
    set("long",
        "
这人的身子站得更直，更挺，就像是一杆枪。他整个人似已麻木，既不知痛痒，
也不知哀乐。
\n"
        );
    create_family("金钱帮", 2, "护法");
    set("rank_nogen",1); 
    set("combat_exp", 2000000);
    set("score", 2000);
    
    set("inquiry",  ([
                "leave": (: leave :),
                ]) );
    set_skill("perception", 100);
    set_skill("dodge", 100);
    set_skill("force", 180);
    set_skill("literate", 100);
    set_skill("jingxing",100);
    set_skill("sword", 200);
    set_skill("jinhong-steps",160);
    set_skill("unarmed",100);
    set_skill("flame-strike",100);
    set_skill("move",160);
    set_skill("lefthand-sword",220);
    set_skill("sharen-sword",180);
    set_skill("parry",100);
    set_skill("yoga",200);
    map_skill("parry","sharen-sword");
    map_skill("unarmed","flame-strike");
    map_skill("dodge", "jinhong-steps");
    map_skill("sword", "lefthand-sword");
    map_skill("force", "jingxing"); 
    set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
    }) );    
    set("ranks",({"帮众","副香主","香主","副堂主","堂主",
                   "副坛主","坛主","副舵主","舵主",
                      "护法","大护法","副帮主"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
    carry_object(__DIR__"obj/leftsword")->wield();
}  
void attempt_apprentice(object me)
{
      command("say 好！很好！");
      command("recruit " + me->query("id") ); 
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "assassin");
}
 
void init()
{       
        ::init();
        add_action("do_killing", "kill");
    
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "assassin"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N喝道：在我面前杀我的弟子，不想活了！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="assassin") return 0;
        message_vision(CYN"$N向你瞧了瞧说：“人各有志，我不勉强。“\n"NOR, this_object());
   message_vision(CYN"$N说：只是我的金虹步伐的妙处你是体会不到了。\n"NOR,this_object());
        return 1;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>200) {
                                if (this_object()->query_temp("weapon")){
                                command( "say 好厉害的硬功！会一会我的烈焰寒冰掌！");
                                command("unwield sword");
                                }
                        } else  command("wield sword");
                        
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else this_object()->smart_attack();
                        
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.duxin");      
        }    
