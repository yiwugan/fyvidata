 inherit NPC;
#include <ansi.h>
void smart_fight();
void greeting(object me);
void create()
{
        set_name("����Ԫ", ({"leng qingyuan", "water guard", "guard"}) );
        set("gender", "����" );
        set("age", 25);
                
        set("long",
                "��Į����ײ���˿�����飬�������ܵĺ����������䡣\n"
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
    carry_object(__DIR__"obj/kw_cloth")->wear();
        
}     
