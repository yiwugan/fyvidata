 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("柳余根", ({ "liu yuhen"}) );
        set("gender", "男性" );
        set("title",HIB"玉面郎君"NOR);
        set("age", 30+random(10));
 
        set("long",
                "这人脸左面已被人削去了一半，伤口现在已干瘪收缩，把他的鼻子和眼睛都歪
歪斜斜的扯了过来，不是一个鼻子，是半个，也不是一双眼睛，是一只。他的
右眼已只剩下了一个又黑又深的洞，额角被人用，刀锋划了个大“十”字，双
手也被齐腕砍断了，在手腕上装着个寒光闪闪的铁钩。\n"
                );
        set("class","yinghe");
    set("combat_exp", 5500000);
    set("score", 900);
        
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",40);
        set("per",1);
        
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
            "柳余根喃喃地说：“我的心已经死了，谁也别想得到那生命的种子。”\n",
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
    carry_object(__DIR__"obj/seed");
    carry_object("/d/wudang/npc/obj/dingpa");    
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
        say("霍天青答哈哈一笑说道：好说，好说。\n"); 
}   
