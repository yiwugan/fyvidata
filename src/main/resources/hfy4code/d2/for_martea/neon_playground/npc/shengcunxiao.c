 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("ʢ��Т", ({ "sheng cunxiao" }) );
        set("nickname",HIM "���Ľ���" NOR);
        set("gender", "����");
        set("age", 40);
        set("long",
"һ�������Ϻ졢ʨ�����ڣ�������Ŷ��ڵ�����󺺡�\n"
);
        set("inquiry", ([
               
        ]) );
       
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 2); 
        
        set("combat_exp", 1500000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
        set("pursuer", 1); 
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 300);
        set("max_atman", 300);
        set("mana", 300);
        set("max_mana", 300);
        
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.yexuechuji" :),
        }) ); 
          
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qiuzhi-sword",150);            
        set_skill("hanmei-force", 150);
        set_skill("anxiang-steps",140);
        set_skill("zhaixin-claw",120);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("sword","qiuzhi-sword");
        map_skill("parry","qiuzhi-sword");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object(__DIR__"obj/n_sword1")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
    
