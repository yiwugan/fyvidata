 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("�̵��ڶ�", ({ "pan deng"}) );
        set("gender", "����" );
        set("title",HIY"�������"NOR);
        set("age", 70+random(10));
        set("class","lama");        
        set("long",
                "���ø�ɮ���˴ξ��ڵ�������,��ͼһͳ���֡�\n"
                );
        set("class","lama");
        set("combat_exp", 4500000);
        set("score", 900);
        set("reward_npc", 1);
        set("difficulty",5);
        set("fle",50);
        set("cor",40);
        set("cps",40);
        set("str",40);
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",110);
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);
                
        set("no_busy",5);
        set("resistance/kee",50);
        set("resistance/gin",20+random(40));
        set("resistance/sen",50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "�̵��ڶ�˵���ٺ٣���ʵ���ֻ����С�ӣ������ֵ����������ܸĳɡ��ƺ�����
�ǿ�������˼��\n",
                }) );
        
        set_skill("iron-cloth", 200);
        set_skill("unarmed", 200);
        set_skill("dragonstrike", 200);
        set_skill("force", 200);
        set_skill("dragonstrike", 200);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("jin-gang",150);
        set_skill("perception",200);
        
        map_skill("iron-cloth","jin-gang");
        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "dragonstrike");
        map_skill("force", "bolomiduo");
        
        add_temp("apply/iron-cloth", 200);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) ); 
        setup();
        carry_object(__DIR__"obj/lamacloth1")->wear();
        carry_object(__DIR__"obj/ring1")->wear();
        
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
        say("�̵��ڶ�����һЦ˵������˵����˵��\n"); 
} 
void lose_enemy( object winner)
{
        object gweapon;
        say("\n�̵��ڶ���ʧɫ���������������������һ��ǻ�ȥ�ɡ�\n\n");
        if (winner->query("class")=="legend" && winner->query_temp("marks/tie_ask"))
        if (!winner->query("marks/��ɮ3")) {
                winner->set("marks/��ɮ3",1);
        }
} 
void die()
{
        object me;
        if(objectp(me=query_temp("last_damage_from") ))
        if(!me->query("marks/��ɮ1") && me->query("class")=="legend")
        {
                me->set("marks/��ɮ1",1);
        }
        ::die();
}
