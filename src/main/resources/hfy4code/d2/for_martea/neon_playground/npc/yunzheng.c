 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("���", ({ "yun zheng" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"һ���������������µ����ꡣ\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������Ц������������Ӣ�ű������ҽ��ռ������ˣ�һ��������Ѱ�㸴��!\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIW"�����ӵ�"NOR);
        set("score", 10000);
        set("class", "tieflag");
        set("reward_npc", 1);
        set("difficulty", 1); 
        
        set("combat_exp", 1500000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 300);
        set("max_atman", 300);
        set("mana", 300);
        set("max_mana", 300);
        
        
   set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.chansi" :),
        }) ); 
          
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
          
        set_skill("hanmei-force", 150);
        set_skill("tie-steps",160);
        set_skill("ill-quan",150);
        
        map_skill("unarmed","ill-quan");
        map_skill("force", "hanmei-force");
        map_skill("dodge","tie-steps");
        map_skill("move","tie-steps");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/armor/cloth")->wear();
} 
    
