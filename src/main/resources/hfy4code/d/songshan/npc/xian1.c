 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        object armor;
        set_name("�޺���", ({ "wu hensheng"}) );
        set("gender", "����" );
        set("title",HIW"��������"NOR);
        set("nickname",HIR"�޼�����"NOR);
        set("age", 70+random(10));
        set("class","lama");        
        set("long",
                "һ��������������ò��Զ�������\n"
                );
        set("class","shaolin");
        set("combat_exp", 4600000);
        set("score", random(90000));
        set("reward_npc", 1);
        set("difficulty",5);
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",40);
        if (!random(3)) set("attitude","friendly");
        set("force",1500);
        set("max_force",1500);
        set("force_factor",100+random(60));
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);
                
        set("resistance/gin",random(80));
        set("resistance/kee",20);
        set("resistance/sen",20);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "�޺���������ǧɽ��ѩ����ɳ����Ϊ��ϯΪ�ң���ϡ�������ѱ档������\n",
                }) );
        
        set_skill("perception",200);
        set_skill("iron-cloth", 200);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("lingxi-zhi", 170);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("five-steps",180);
        set_skill("move",200);
        set_skill("dodge",200);
        
        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("force", "bolomiduo");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        
        add_temp("apply/iron-cloth", 200);
        
/*        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );*/ 
        setup();
        armor=new("/obj/armor/cloth");
        armor->set_name("һ����Ⱦ�İ���",({"cloth"}) );
        armor->move(this_object());
        armor->wear();
} 
/*
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        if (who->is_busy()) return;
        enemy = this_object()->query_enemy();
   i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie-bolt");
                return;
        }
        return;
} 
*/   
