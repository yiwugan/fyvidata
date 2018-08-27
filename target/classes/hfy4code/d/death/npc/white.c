 // ghost.c
inherit NPC; 
void create()
{
        set_name("���޳�", ({ "wuchang", "white wuchang" }) );
        set("age", 200);
        
        set("str", 24);
        set("cor", 26); 
        set("max_kee", 26000); 
        set("max_sen", 26000); 
        set("max_gin", 26000); 
set("combat_exp", 9999999+random(9999999)); 
        set_skill("huanhua-sword", 500);
        set_skill("sword", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("huanhua-steps", 500);
        map_skill("sword","huanhua-sword");
        map_skill("parry","huanhua-sword");
        map_skill("dodge","huanhua-steps");
        set("env/wimpy", 70);
        set_temp("apply/attack", 5000);
        set_temp("apply/armor", 5000);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jingtianyijian" :),
                (: perform_action, "dodge.hongyeluanfei" :),

        }) );
        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        setup();
        carry_object("/obj/weapon/sword")->wield(); 
} 
int is_ghost() { return 1; }     
