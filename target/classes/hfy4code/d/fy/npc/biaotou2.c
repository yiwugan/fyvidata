 inherit NPC;
void create()
{
        set_name("诸葛镖师", ({ "biaotou zhuge","biaotou"}) );
        set("gender", "男性" );
        set("age", 42);
        
        set("long", "这是一位金狮镖局的镖师。\n");
        set("combat_exp", 3200000);
        set("attitude", "friendly");
        set("class","assassin");        
        
        set("cps",40);
        set("str",36);
        
        set("max_force",1000);
        set("force",1000);
        set("force_factor",90);
        
        set_skill("unarmed", 150);
        set_skill("flame-strike",180);
        set_skill("dodge", 200);
        set_skill("move",200);
        set_skill("parry",200);
        set_skill("puti-steps",180);
        set_skill("move",200);
        
        map_skill("dodge","puti-steps");
        map_skill("unarmed","flame-strike");
        map_skill("move","puti-steps"); 
        switch (random(3)) {
                case 0: set("resistance/kee",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/sen",30);
                }
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "诸葛镖师打了个哈欠说，该睡觉了。\n",
        }) );
        
        setup();
        add_money("silver", 5);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        if (!random(2))
        carry_object(__DIR__"obj/hongbao"); 
}       
