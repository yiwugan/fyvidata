 // CYNGIRL.C
inherit NPC;
#include <ansi.h>
void create()
{       
        object armor;
        set_name("贴身丫鬟", ({ "maid" }) );
        set("nickname",HIR "帝王谷" NOR);
        set("long", "身材苗条，身着小红裙，帝王谷老妇人的贴身丫鬟。\n");
        set("age", 16);
        set("per",20);
        set("cps",40);
        set("gender", "女性");
        set("attitude", "friendly");
        set("combat_exp", 3500000);  
        
        set_skill("ill-quan",150);
        set_skill("unarmed",200);
        set_skill("force",150);
        set_skill("cloudsforce",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("tie-steps",150);
        set_skill("sword",150);
        set_skill("fy-sword",150);
        
        set("force_factor",40);
        set("max_force",1000);
        set("force",1000);
        
        map_skill("force","cloudsforce");
        map_skill("dodge","tie-steps");
        map_skill("unarmed","ill-quan");                         
        map_skill("sword","fy-sword");
        map_skill("parry","fy-sword");
        map_skill("move","tie-steps");
        
        set("no_busy",4); 
        set("resistance/kee",20);
        set("resistance/gin",20);
        set("resistance/sen",20); 
        setup();
        
        armor=new("/obj/armor/cloth");
        armor->set_name(RED"小红裙"NOR,({"skirt"}) );
        armor->move(this_object());
        armor->wear();
        carry_object("/obj/weapon/sword")->wield(); 
}    
