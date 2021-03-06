 inherit NPC;
#include <ansi.h> 
void create()
{
        object armor;
        set_name("赤阳道长", ({ "chi yang" }) );
        set("gender", "男性");
        set("age", 65);
        set("long",
"一个面色赤红，身材高大的道人。\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
        "赤阳道长笑道：“那大名鼎鼎的七妙神君，还不是一样栽在我手里。”\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIW"武当"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",15);
        set("class","wudang");
        set("fly_target",1);
        set("combat_exp", 4400000);        
        set("int", 30);
        set("cps", 40);
        set("spi", 30);
        set("fle",50);
        
        set("force", 2000);
        set("max_force",2000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/gin",40);
   set("resistance/kee",40);
        set("resistance/sen",40);
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chanzijue" :),
                (: perform_action, "unarmed.nianzijue" :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
          
        set_skill("taijiforce", 150);
        set_skill("five-steps",160);
        set_skill("taiji",180);
        set_skill("taiji-sword",150);
        
        map_skill("unarmed","taiji");
        map_skill("force", "taijiforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("parry","taiji-sword");
        map_skill("sword","taiji-sword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/sword")->wield();
         armor=new("/obj/armor/cloth");
        armor->set_name("丝织的道服",({"cloth"}) );
        armor->move(this_object());
        armor->wear();

} 
        
