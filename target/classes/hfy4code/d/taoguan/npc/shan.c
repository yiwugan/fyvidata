 inherit NPC;
#include <ansi.h>
void  smart_fight( object who); 
void create()
{
        set_name("ɽ����", ({ "taoist shan" }) );
        set("nickname",HIY "����" NOR);
        set("gender", "����");
        set("age", 60);
        set("long",
"ɽ�����Ƕ��������½����Ͻ����������幬�Ĺ���֮һ���ֳ�һ������ɫ
�ķ��ȡ�\n"
);
        set("attitude", "friendly");
        set("combat_exp", 800000);
        set("score", 2000); 
        set("class", "beggar");
        set("reward_npc", 1);
        set("difficulty", 2); 
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",40);
//      set("pursuer", 1); 
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40); 
        set("atman", 150);
        set("max_atman", 150); 
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight(this_object()) :),  
        }) ); 
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("gouyee", 100);
        set_skill("staff",150);
        set_skill("dagou-stick",100);
        set_skill("doggiesteps",140);
        set_skill("taoism", 100);
        set_skill("necromancy", 100); 
        set_skill("dragonstrike",100);    
        map_skill("unarmed","dragonstrike");
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        map_skill("staff","dagou-stick");
        map_skill("dodge","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("move","doggiesteps");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("silver", 30);
        carry_object(__DIR__"obj/s_staff")->wield();
        carry_object(__DIR__"obj/s_cloth")->wear();
} 
 
void smart_fight(object who)
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1) {
                who->perform_action("staff.tianxiawugou");
                return;
        }       
   while(i--) {
                if(enemy[i] && living(enemy[i])&& random(100)>50 ) {
                        who->perform_action("staff.banzijue");
        }
        }
        return;
} 
