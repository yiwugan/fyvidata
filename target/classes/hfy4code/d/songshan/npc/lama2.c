 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("��ʤ��", ({ "jin bo"}) );
        set("gender", "����" );
        set("title",HIY"�������"NOR);
        set("age", 70+random(10));
        set("class","lama");        
        set("long",
                "���ø�ɮ���˴ξ��ڵ�������,��ͼһͳ���֡�\n"
                );
        set("class","lama");
        set("combat_exp", 4000000);
        set("score", 900);
        set("reward_npc", 1);
        set("difficulty",5);
        set("cor",40);
        set("cps",30);
        set("str",40);
        
        set("force",1000);
        set("max_force",1000);
        set("force_factor",110);
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);
                
        set("no_busy",4);
        set("resistance/kee",50);
        set("resistance/gin",random(80));
        set("resistance/sen",50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ʤ��˵���ٺ٣���ʵ���ֻ����С�ӣ������ֵ����������ܸĳɡ��ƺ�����
�ǿ�������˼��\n",
                }) );
        
        set_skill("iron-cloth", 200);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("yue-strike", 170);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("jin-gang",200);
        set_skill("perception",200);
        
        map_skill("iron-cloth","jin-gang");
        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "yue-strike");
        map_skill("force", "bolomiduo");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) ); 
        setup();
        carry_object(__DIR__"obj/lamacloth1")->wear();
        carry_object(__DIR__"obj/ring2")->wear();
        
} 
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {       who->cast_spell("ni");
                        return;
                }               
        }
        return;
}  
void win_enemy(object loser)
{
        say("��ʤ�Ĺ���һЦ˵������˵����˵��\n"); 
} 
void lose_enemy( object winner)
{
        object gweapon;
        say("\n��ʤ�Ĵ�ʧɫ��������������������\n\n");
        message_vision(CYN"$N��Ц��˵��������û������߱����ˣ���\n",this_object());
        this_object()->kill_ob(winner);
} 
void die()
{
        object me;
        if(objectp(me=query_temp("last_damage_from") ))
        if(!me->query("marks/��ɮ2") && me->query("class")=="legend")
        {
                me->set("marks/��ɮ2",1);
        }
        ::die();
} 
