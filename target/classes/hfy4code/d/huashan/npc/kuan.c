 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("苦庵上人", ({ "ku an" }) );
        set("gender", "男性");
        set("age", 65);
        set("long",
"一个愁眉苦脸的老道。\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "苦庵上人叹道：“那七妙神君果真厉害，我们实在是不得已啊。”\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIG"峨嵋"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",5);
        set("class","bonze");
        set("fly_target",1);
        
        set("combat_exp", 3500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("force", 2000);
        set("max_force",2000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/kee",50);
        set("resistance/gin",50+random(40));
        set("resistance/sen",50);        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);              
        set_skill("lotusforce", 150);
        set_skill("notracesnow",150);
        set_skill("dabei-strike",165);
        set_skill("cloudstaff",150);
        set_skill("staff",150); 
        map_skill("staff","cloudstaff");
        map_skill("unarmed","dabei-strike");
        map_skill("force", "lotusforce");
        map_skill("dodge","notracesnow");
        map_skill("move","notracesnow");
        map_skill("parry","cloudstaff");
        map_skill("sword","cloudstaff");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/staff")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
       
