 inherit NPC;
//inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("尤葛",({"you ge","zhanggui"}));
        set("title","山西七义");
        set("long","附近有间客栈叫“有间客栈”，里面有个掌柜，就是这个“尤葛”掌柜。\n");
        set("gender","男性");
        set("age",33);
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("str",30);
        /*set("vendor_goods", ([
        
        
           
               "/d/fy/npc/obj/baozi1":30,
               "/d/fy/npc/obj/baozi2":30,
               "/d/fy/npc/obj/baozi3":30,
               "/d/guanwai/npc/obj/wineskin":30,
                "/d/xinjiang/npc/obj/baozi":30, 
        ]) );*/
         set("class","beggar");
         
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 1);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",180);
                        
        set_skill("qidaoforce", 150);
        set_skill("doggiesteps",200);
        set_skill("dragonstrike",200);
        set_skill("dagou-stick",180);
        
        map_skill("unarmed","dragonstrike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","doggiesteps");
        map_skill("move","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("staff","dagou-stick");
        
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
            (: perform_action, "unarmed.xianglongwuhui" :),
            }) ); 
        //set("chat_chance_combat", 1);
        set("chat_chance",1);
        set("chat_msg",({
                "尤葛低头在算帐，但不知道是掌柜的帐目，还是杀人的数目了。\n",
                 // (: random_move :),
        }) );
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
        //carry_object(__DIR__"obj/fanqi")->wield();  
} /*
void init()
{       
   
        add_action("do_vendor_list", "list");
} 

void reset()
{
        set("vendor_goods", ([
              "/d/fy/npc/obj/baozi1":30,
           
               "/d/fy/npc/obj/baozi2":30,
               "/d/fy/npc/obj/baozi3":30,
  "/d/guanwai/npc/obj/wineskin":30,
                "/d/xinjiang/npc/obj/baozi":30, 
        ]) );
} */