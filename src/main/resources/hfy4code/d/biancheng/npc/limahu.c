#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
inherit F_VENDOR; 

void create()
{
        set_name("李马虎",({"li mahu","li","mahu"}));
        set("title","杂货铺老板");
        set("long","他姓李，别人都叫他李马虎。是个很乐观的中年人，圆圆的脸，无论看到谁都是笑眯
眯的。\n");
        set("gender","女性");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
                set("vendor_goods", ([
                          "/obj/weapon/dagger":10,
                          "/d/quicksand/npc/obj/roundblade":10,
                          "/d/wudang/obj/sword2":10,
                          "/d/fy/npc/obj/knife.c":10,
                          "d/taoyuan/obj/liandao":10,
                          "d/taoyuan/obj/hook":10,                                                   
        ]) );

        
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
        set("combat_exp",1000000);  
        set("attitude", "friendly");
        
        
      //  set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "李马虎笑眯眯地道：“女人用鸡蛋清洗脸，越洗越年轻的。”\n",
        }) );                   
        
//           CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}     
void init()
{
        add_action("do_vendor_list", "list");
}  
