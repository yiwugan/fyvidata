 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("�廨��Ů��", ({ "sewing girl" }) );
        set("gender", "Ů��");
        set("age", 25);
        set("long",
"һ����ˮ������Ů,��������������ǰ�廨��\n"
); 
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 2); 
        
        set("combat_exp", 3000000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30); 
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
         
        set_skill("move", 200);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 180);
        set_skill("sword", 150);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);
                
        set_skill("throwing",140);            
        set_skill("hanmei-force", 100);
        set_skill("tanzhi-shentong",161);
        set_skill("anxiang-steps",150);
        set_skill("zhaixin-claw",150);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("throwing","tanzhi-shentong");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
        
        setup(); 
        add_money("gold", random(5));
        carry_object(__DIR__"obj/n_stone")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1) {
                who->perform_action("throwing.mantianhuayu");
           return;
        }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->is_busy()&& !who->is_busy()) {
                                this_object()->smart_attack();
                        }
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<3*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("throwing.tanzhijinghun");
} 
smart_attack() {
        this_object()->perform_action("throwing.mantianhuayu"); 
        }     
