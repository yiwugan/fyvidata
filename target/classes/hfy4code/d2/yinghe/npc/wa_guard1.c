 inherit NPC;
#include <ansi.h>
void smart_fight();
void greeting(object me);
void create()
{
        set_name("������", ({"jiang yulin", "key guard", "guard"}) );
        set("gender", "����" );
        set("title", HIY"ӫ����ʿ"NOR);
        set("age", 23);
        set("long",
                "һ������������ӫ����ʿ��\n"
        );
        set("class","wudang");
    
    
    set("combat_exp", 3500000);
    set("score", 900);
        
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",40);
        set("per",26);
        set("attitude", "aggressive");
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
        
    set_skill("perception",200);
   set_skill("iron-cloth", 200);
        set_skill("unarmed", 200);
        set_skill("dragonstrike", 200);
        set_skill("force", 200);
        set_skill("lingxi-zhi", 150);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("five-steps",200);
        set_skill("taiji-sword",180);
        set_skill("move",400);
                
        map_skill("iron-cloth","jin-gang");
        map_skill("dodge","five-steps");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("force", "bolomiduo");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("dodge.bazhentu") :),    
        }) );
         
        setup();
    carry_object(__DIR__"obj/kuijia")->wear();
        
}        
