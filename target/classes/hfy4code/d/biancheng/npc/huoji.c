#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
        set_name("中年伙计",({"huo ji","huoji"}));
        set("title","绸缎庄");
        set("long","伙计显得没精打采的样子，只希望天快黑，他们在店里虽然是伙计，在家
里却是老板。\n");
        
        set("gender","男性");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",1000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_force",200+random(500));
        set("force",query("max_force"));
        set("force_factor",30);
        
        
        set("inquiry", ([
                
        ])); 
//      set("death_msg",CYN"\n$N说：“你的心真狠，连穷人都不放过。”\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"叫道：“来人啊，强盗上门抢劫啦！”\n", 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );  */
        set("chat_chance",1);
        set("chat_msg",({
           name()+"说：“客官尽管挑，尽管挑。。。”\n",
        }) );                   
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
}       
