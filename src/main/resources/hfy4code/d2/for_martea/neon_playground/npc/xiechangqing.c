 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("л����", ({ "xie changqing" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"һ�������Ӣ�������꣬�������ڲ����ţ�Ӣ���������ϣ�Ҳ����һ��
����֮ɫ����\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "л�����૵������һ����ᣬ�Ҳ��ܾ�����������Ϣ����ȥ��
����������������ˣ���ʹ����������֮�£�����˭�ᴫ����ȥ������������
�˶���Ϊ�Լ�����ɡ���
����\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIG"���"NOR);
        set("nickname", HIG"��Ӣ��"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",20);
        set("class","tiexue");
        
        set("combat_exp", 2500000);        
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
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
        set_skill("fall-steps",150);
        set_skill("meihua-shou",150);
        set_skill("diesword",140);
        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","diesword");
        map_skill("sword","diesword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
        
