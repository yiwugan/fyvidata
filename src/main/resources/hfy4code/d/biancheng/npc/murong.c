#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
    set_name("慕容明珠",({"murong mingzhu","murong","mingzhu" }));
//    set("title","虬髯巨汉");
    set("long","一个英俊的少年，长身玉立，神采飞扬。束金冠，紫罗衫，腰悬着长剑，剑鞘上的
宝石闪闪生光，腰上还束着紫金带，剑穗上悬着龙眼般大的一粒夜明珠。\n");
        set("gender","男性");
        set("age",42);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
                set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8000000);  
    set("class", "tieflag");
    
  set_skill("dormancy",180);
    set_skill("unarmed", 220);
    set_skill("perception", 280);
    set_skill("move", 220);
    set_skill("sword", 130);
    set_skill("literate", 180);
    set_skill("force", 150);
    set_skill("parry", 200);
    set_skill("dodge", 200);
    set_skill("ill-quan", 200);
    set_skill("fy-sword", 160);
    set_skill("cloudsforce", 130);
    set_skill("tie-steps", 200);
        
    map_skill("unarmed", "ill-quan");
    map_skill("sword", "fy-sword");
    map_skill("force", "cloudsforce");
    map_skill("parry", "fy-sword");
    map_skill("dodge", "tie-steps"); 

        
        set("attitude", "friendly");               
        set("death_msg",CYN"\n$N在血泊中慨叹：“原来。。。钱。。。不是万能的。。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	  (: perform_action, "dodge.chansi" :),
             (: perform_action, "sword.fengqiyunyong" :),

        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "乐先生正色道：“洗澡最伤元气，那是万万洗不得的。”\n"
        }) );                                   
        
//           CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();   
          carry_object("/obj/weapon/sword")->wield();    
    
}
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("wanma/杀客人c",1);
        ::die();
}  
