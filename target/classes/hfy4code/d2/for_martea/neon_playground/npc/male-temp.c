 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("ɽ����", ({ "taoist shan" }) );
        set("nickname",HIY "����" NOR);
        set("gender", "����");
        set("age", 60);
        set("long",
"������Ƕ��������½����Ͻ����������幬�Ĺ���֮һ���ֳ�һ������ɫ
�ķ��ȣ���һ����ɫ�ĵ��ۡ�\n"
);
        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "beggar");
        set("reward_npc", 1);
        set("difficulty", 2); 
        
        set("combat_exp", 800000);        
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
        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "staff.banzijue" :),
        }) ); 
          
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
        
        set_skill("staff",150);            
        set_skill("gouyee", 100);
        set_skill("dagou-stick",120);
        set_skill("doggiesteps",140);
        set_skill("necromancy", 100);     
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        map_skill("staff","dagou-stick");
        map_skill("dodge","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("move","doggiesteps");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(1));
        carry_object(__DIR__"obj/s_staff")->wield();
        carry_object(__DIR__"obj/s_cloth")->wear();
} 
        
