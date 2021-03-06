 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("红莲花", ({ "lin shouou" }) );
        set("gender", "男性");
        set("age", 18);
        set("long",
"一个乾枯瘦小，却长着两只大眼睛的少年乞丐，手里拿着根竹竿，正瞧着你笑。\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "红莲花喃喃道：“这里面一定有一个大阴谋，是什么呢？”
。”\n",
        }) );
          
        set("attitude", "friendly");
        set("title","少年乞丐");
//        set("nickname", HIG"义薄云天"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",20);
        set("class","tiexue");
        
        set("combat_exp", 4500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 500);
        set("max_atman", 500);
        set("mana", 500);
        set("max_mana", 500);
        
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
        set_skill("fall-steps",150);
        set_skill("meihua-shou",150);
        set_skill("diesword",140);
        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","diesword");
        map_skill("sword","diesword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
    
