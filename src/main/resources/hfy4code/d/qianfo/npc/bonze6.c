 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_qin();
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("云空", ({ "yunkong" }) );
        set("gender", "男性" );
        set("class", "bonze");
        set("title","兴国禅寺云字辈大师");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 60);
        set("int", 25);
        set("long", "他是兴国禅寺中颇有威望的云字辈大师\n");
        set("combat_exp", 4500000);
        set("attitude", "friendly");
        
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor",50);
        set("max_atman",1500);
        set("atman",1500);
        set("mana",1500);
        set("max_mana",1500);
        
        set("resistance/kee",50);
        set("resistance/gin",50);
        set("resistance/sen",50); 
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );                   
                set_skill("kwan-yin-spells",130);
          set_skill("spells", 150);
          map_skill("spells","kwan-yin-spells");  
        set_skill("dabei-strike",200);
        set_skill("notracesnow",200);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("lotusforce", 150);
        set_skill("dabei-strike",120);
        set_skill("move",200);
        
        set_skill("essencemagic",150);
        set_skill("magic",200);
        map_skill("magic","essencemagic");
            map_skill("force", "lotusforce");
            map_skill("dodge","notracesnow");
            map_skill("unarmed","dabei-strike");
            map_skill("move","notracesnow");
              
        set("chat_chance", 1);
        set("chat_msg", ({
                "云空说道：你想学击鼓吗？\n",
        }) );
        set("inquiry", ([
                "击鼓" : (: give_qin :),
                "jigu" : (: give_qin :),
        ]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}
int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
} 
int give_qin()
{
        object obj;
if( !query("given"))
        {
command("say 这把佛鼓你拿去练吧！！\n");
obj = new(__DIR__"obj/fegu");
obj->move(this_player());
set("given",1);
        }
else
command("say 我的佛鼓已送人了！\n");
        return 1;
} 
void reset()
{
delete("given");
}  
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie-bolt");
                return;
        }
        if (random(3)>1) who->perform_action("unarmed.qianshouqianbian");
        return;
}  
