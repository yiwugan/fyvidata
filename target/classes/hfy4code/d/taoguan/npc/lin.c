 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("�ֵ���", ({ "taoist lin" }) );
        set("nickname",HIG "���" NOR);
        set("gender", "����");
        set("age", 65);
        set("long",
"�ֵ����Ƕ��������½����Ͻ����������幬�Ĺ���֮һ��\n"
);
        set("attitude", "friendly");
        set("combat_exp", 550000);
        set("score", 2000); 
        set("class", "yinshi"); 
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
//      set("pursuer", 1);
        set("reward_npc", 1);
        set("difficulty", 1);  
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 30); 
        set("atman", 150);
        set("max_atman", 150); 
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 30); 
        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "whip.tianleiyiji" :),
        }) ); 
        set_skill("flame-strike",100);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("gouyee", 100);
        set_skill("whip",100);
        set_skill("thunderwhip",100);
        set_skill("zuixian-steps",140);
        set_skill("cursism", 100);
        set_skill("necromancy", 100);     
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        map_skill("whip","thunderwhip");
        map_skill("dodge","zuixian-steps");
        map_skill("parry","xuanyuan-axe");
        map_skill("move","zuixian-steps");
        map_skill("unarmed","flame-strike");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("coin", 30);
        carry_object(__DIR__"obj/l_whip")->wield();
        carry_object(__DIR__"obj/l_cloth")->wear();
}  
  
