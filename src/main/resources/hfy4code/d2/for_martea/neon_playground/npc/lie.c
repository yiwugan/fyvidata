 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("����", ({ "li e" }) );
        set("gender", "����");
        set("age", 65);
        set("long",
"���ߴ��ż�Ϊ���µ�˿�����ӣ�����б���ű��������ǽ���ܳ�����������
���ݵ������ϣ������ҵ������ˣ��Ե����ǻ�����Ȼ�������������Ŀ����ӥ��
��֮ȴ��������η��\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({ 
        }) );
          
        set("attitude", "friendly");
        set("title",HIW"��Ἵ���"NOR);
        set("score", 0);
        set("class", "tieflag");
        set("reward_npc", 1);
        set("difficulty",10); 
        
        set("combat_exp", 3500000);        
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
                (: perform_action, "sword.hunranyijian" :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
          
        set_skill("doomforce", 150);
        set_skill("doomsteps",160);
        set_skill("doomstrike",150);
        set_skill("doomsword",140);
        
        map_skill("unarmed","doomstrike");
        map_skill("force", "doomforce");
        map_skill("dodge","doomsteps");
        map_skill("move","doomsteps");
        map_skill("parry","doomsword");
        map_skill("sword","doomsword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
       
