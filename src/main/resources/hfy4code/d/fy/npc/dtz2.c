 // dtz.c
inherit NPC; 
void create()
{
        set_name("登徒子", ({ "dtz" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "一个色迷迷的登徒子.\n"); 
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("chat_chance", 2);
        set("chat_msg", ({
                (:random_move :),
        "登徒子道：听说千面娘子帮当今朝廷破了一件大案。\n",
        "登徒子道：乙成仙的算卦纯粹是瞎闹，没有一回准的。\n",
        }) ); 
        set("inquiry", ([
                "大案" : "当年先皇的刺客被同党谋杀毁尸，千面娘子只用刺客的头骨就可以作出刺客的面具！\n",
                "case" : "当年先皇的刺客被同党谋杀毁尸，千面娘子只用刺客的头骨就可以作出刺客的面具！\n",
        ]) ); 
        setup();
        add_money("coin", 1);
        carry_object("/obj/armor/cloth")->wear();
        
}  
void die() {
        message_vision("haha i die.\n",this_object());
        destruct(this_object());
        message_vision("haha i die again.\n",this_object());
}      
