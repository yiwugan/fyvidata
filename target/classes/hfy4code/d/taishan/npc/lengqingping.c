 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("����Ƽ", ({ "leng qingping" }) );
        set("title",HIG "���㱤" NOR);
        set("gender", "Ů��");
        set("age", 22);
        set("long",
" һ�������仪������ȴ���Ǳ�����Ů���������ᣬ���Ӹ��·�
����ʤ�£��������ľ�ǿ�������ȫ��ͬ\n"
);
        set("inquiry", ([
               
        ]) );
       
        set("chat_chance", 1);
        set("chat_msg", ({
                "����Ƽ����̾��������û����ĥ�ң�������û����ĥ���ҡ���\n",
        }) );
       
        set("attitude", "friendly");
        set("score", 200);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 1); 
        
        set("combat_exp", 1400000);        
        set("int", 30);
        set("per",60);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
        set("str",30); 
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 80);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
        
        set("chat_chance_combat", 30);
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
                
        set_skill("qingfeng-sword",150);            
        set_skill("hanmei-force", 150);
        set_skill("anxiang-steps",120);
        set_skill("zhaixin-claw",120);
        set_skill("sword",120);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("sword","qingfeng-sword");
        map_skill("parry","qingfeng-sword");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
        
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
        
