 inherit NPC;
void create()
{
        set_name("隐士", ({ "hermit" }) );
        set("gender", "男性" ); 
        set("attitude", "peaceful"); 
        set("long","这是一个小喽罗。\n"); 
        set("combat_exp", 200000); 
        set("chat_chance", 50);
        set("chat_msg", ({ 
        }) ); 
        setup();
        add_money( "coin" , 50);
        carry_object("/obj/armor/cloth")->wear();
}      
