 inherit NPC;
#include <ansi.h> 
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
        set("difficulty", 2); 
        
        set("combat_exp", 3000000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",50); 
        set("force", 2000);
        set("max_force",2000);
        set("force_factor", 60);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.mantianhuayu" :),
                (: perform_action, "throwing.tanzhijinghun" :),
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
        set_skill("zhaixin-claw",160);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("throwing","tanzhi-shentong");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(1));
        carry_object(__DIR__"obj/n_stone")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
        
