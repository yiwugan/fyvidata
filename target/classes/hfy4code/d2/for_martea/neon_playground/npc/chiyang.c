 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("��������", ({ "chi yang" }) );
        set("gender", "����");
        set("age", 65);
        set("long",
"һ����ɫ��죬��ĸߴ�ĵ��ˡ�\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������Ц�������Ǵ������������������������һ�������������\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIW"�䵱"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",20);
        set("class","wudang");
        
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
        set_skill("taiji",165);
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
        carry_object("/obj/armor/cloth")->wear();
} 
    
