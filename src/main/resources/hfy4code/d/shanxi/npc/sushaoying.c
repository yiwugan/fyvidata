//weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("苏少英", ({ "su shaoying","su" }) );
        set("gender", "男性" );
        set("title", "峨嵋派 少侠" );
        set("nickname", HIM"三英四秀之"NOR );
        set("long",
        "一个是个很洒脱的人，既没有酸腐气，也不会拿肉麻当有趣，是个饱学的举人，\n可是听他的声音，年纪却仿佛很轻。\n"
                );
        set("attitude", "peaceful");
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 300000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 20);
        set_temp("apply/armor",150);
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 9999);

        set("chat_chance", 5);
        set("chat_msg", ({
                "苏少英谈笑风生，正在说南唐後主的风流韵事。。。\n",
                "苏少英低头道，“他是个多情人，他的凄婉绝伦，果然没有人能比得上。。。” \n",
                }) ); 
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("move", 50);
        set_skill("sky-sword", 50);
        set_skill("sky-steps", 50);                
        map_skill("parry", "sky-sword");
        map_skill("sword", "sky-sword");
        map_skill("move", "sky-steps");
        map_skill("dodge", "sky-steps");
        setup(); 
        carry_object("/obj/weapon/sword")->wield();
        add_money("gold",5);
        carry_object("/obj/armor/cloth")->wear();
} 