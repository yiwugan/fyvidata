#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("沈三娘",({"shen saniang","shen","saniang"}));
        set("title","人如玉，玉生香");
        set("long","这妇人长身玉立，满头秀发漆黑，一张瓜子脸却雪白如玉。她并不是那种令人一见
销魂的美女，但一举一动间都充满了一种成熟的妇人神韵。无论什么样的男人，只
要看见她立刻就会知道，你不但可以在她身上得到安慰和满足，也可以得到了解和
同情。\n");
        set("gender","女性");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
//                "乐先生正色道：“洗澡最伤元气，那是万万洗不得的。”\n"
           }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}    
