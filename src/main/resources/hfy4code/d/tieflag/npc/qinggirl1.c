 inherit NPC;
void create()
{       
        object armor;
        set_name("持剑的青衣少女", ({ "sword girl" }) );
        set("long", "一个身材苗条，身着青衣的少女。\n");
        set("age", 16);
        set("per",20);
        set("cps",40);
        set("gender", "女性");
        set("attitude", "friendly");
        set("combat_exp", 1800000);  
        
        set_skill("ill-quan",150);
        set_skill("unarmed",150);
        set_skill("force",150);
        set_skill("cloudsforce",150);
        set_skill("dodge",150);
        set_skill("parry",130);
        set_skill("tie-steps",150);
        set_skill("sword",100);
        set_skill("fy-sword",120);
        
        set("max_force",500);
        set("force",500);
        set("force_factor",20);
        
        map_skill("force","cloudsforce");
        map_skill("dodge","tie-steps");
        map_skill("unarmed","ill-quan");                         
        map_skill("sword","fy-sword");
        map_skill("parry","fy-sword");
        map_skill("move","tie-steps");
        
        set("no_busy",4);
        set("resistance/kee",10);
        
        create_family("常春岛", 4, "弟子");
        setup();
        
        armor=new(__DIR__"obj/corclot");
        armor->set_name("青衣裙",({"cloth"}) );
        armor->move(this_object());
        armor->wear();
        carry_object("/obj/weapon/sword")->wield(); 
}       
