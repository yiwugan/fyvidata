 inherit NPC;
void create()
{
        set_name("��ʿ", ({ "hermit" }) );
        set("gender", "����" ); 
        set("attitude", "peaceful"); 
        set("long","����һ��С��ޡ�\n"); 
        set("combat_exp", 200000); 
        set("chat_chance", 50);
        set("chat_msg", ({ 
        }) ); 
        setup();
        add_money( "coin" , 50);
        carry_object("/obj/armor/cloth")->wear();
}      
