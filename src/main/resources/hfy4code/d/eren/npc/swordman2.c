#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("title","川中八义");
        set("long", "川中八义之首，风骨棱棱，气宇轩昂。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4800000);
        
        set("str",40);  
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",110); 
        set("reward_npc", 1);
        set("difficulty", 5); 
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30); 
        set("inquiry", ([
                "燕南天" : "燕大侠是第一个敢闯入恶人谷的正道中人。\n",
                "恶人谷" : "十大恶人散的散，死的死，恶人谷现在太平多了。\n",
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "杨平道：“燕大侠武功虽高，还不足深佩，小弟最佩服的乃是他的干云
豪气，凛然大义，当真令我愧煞。“\n",
                
        }) );
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,170,1,"/d/eren2/npc/obj/","fighter_u","dragonstrike");
   set_name("杨平",({"yang ping"}));
        set("force_factor",50);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        
}       
