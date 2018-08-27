 // girl.c
inherit NPC; 
void create()
{
        set_name("С��", ({ "xiao cui", "cui", "xiao" }) );
        set("class","legend");
        set("gender", "Ů��" );
        set("age", 15);
        set("str", 10);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27); 
        set("attitude", "peaceful"); 
        set("max_force", 100);
        set("force", 100);
        set("force_factor", 10); 
        set("long",     "С������ѩɽׯ��Ѿ��������͵�Բ�԰��ĸ�㡣\n");  
        set("combat_exp", 10000); 
        set_skill("unarmed", 20);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("sword", 40);
        set_skill("force", 30);
        set_skill("literate", 70); 
        set_skill("qidaoforce", 40);
        set_skill("diesword",30);
        set_skill("meihua-shou", 40);
        set_skill("fall-steps", 10); 
        map_skill("unarmed", "meihua-shou");
        map_skill("sword","diesword");
        map_skill("parry", "deisword");
        map_skill("dodge", "fall-steps"); 
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action, "sword.caidiekuangwu" :),
        (: perform_action, "unarmed.meihai" :),  
            }) ); 
        setup(); 
        carry_object(__DIR__"obj/thin_sword")->wield();
        carry_object(__DIR__"obj/pink_cloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
} 
      
