 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("�϶���", ({ "yan duhe"}) );
        set("gender", "����" );
        set("title",HIR"�Ϸ��ܹ�"NOR);
        set("age", 60+random(10));
                
        set("long",
                "���Ǹ��ߴ�������ˣ���������ֱͦ�������뷢Ҳ����ڵģ�ֻ��������\n�������Ѻܶ࣬���\n��ֻ���ڿ���������ʱ���Ż�������������ˡ�\n"
                );
        set("class","yinghe");
        set("combat_exp", 5500000);
        set("score", 900);
        
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",40);
        set("per",15);
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",100);
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);
                
        set("no_busy",6);
        
        set("resistance/kee",30);
        set("resistance/gin",30+random(40));
        set("resistance/sen",30);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "�϶��������Ž�����ֻ�����Լ����ֱȽ������䣬�������䣮������Ҳ����ġ�\n",
                }) );
        
        set_skill("perception",200);
        set_skill("iron-cloth", 200);
        set_skill("unarmed", 200);
        set_skill("dragonstrike", 200);
        set_skill("force", 200);
        set_skill("lingxi-zhi", 150);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("jin-gang",150);
        set_skill("move",400);
                
        map_skill("iron-cloth","jin-gang");
        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("force", "bolomiduo");
        
        add_temp("apply/iron-cloth", 200);
         
        setup();
        set("max_kee", 500000);
        set("eff_kee", 9000);
        
        carry_object(__DIR__"obj/lan_cloth")->wear();
        
} 
/*
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
}*/  
void win_enemy(object loser)
{
        say("����������һЦ˵������˵����˵��\n"); 
}        
