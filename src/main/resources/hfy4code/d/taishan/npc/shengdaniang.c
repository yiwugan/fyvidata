 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("ʢ����", ({ "sheng daniang" }) );
        set("nickname",HIR "ɢ����Ů" NOR);
        set("gender", "Ů��");
        set("age", 65);
        set("long",
"��ͷ������˿��ʢ��ׯŮ���ˣ������˳ơ�ɢ����Ů����ʢ���\n"
); 
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "ʢ����˵��������ϱ��һ������һ�������ڴ������˵���������������ʮ���궼��Ը��Ȣ���ˡ�\n",
        }) );
          
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 5); 
        
        set("combat_exp", 3700000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40); 
        set("force", 2000);
        set("max_force",2000);
        set("force_factor", 60);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
         
        set_skill("move", 200);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 150);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);
                
        set_skill("throwing",200);            
        set_skill("hanmei-force", 100);
        set_skill("tanzhi-shentong",160);
        set_skill("anxiang-steps",160);
        set_skill("lingxi-zhi",160);
        
        map_skill("unarmed","lingxi-zhi");
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
