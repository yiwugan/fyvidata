 //written by Cheng Bao
// gangster.c 
inherit NPC;
void goaway();
void create()
{
        set_name("山西劫匪", ({ "gangster" }) );
        set("gender", "男性" );
        set("age", 27);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
这强盗满脸伤疤，虎背熊腰，一脸凶狠而霸道的样子。
LONG
);
        set("attitude", "heroism");
        set("bellicosity", 1500 ); 
        set("combat_exp", 10000); 
        set("chat_chance", 50);
        set("chat_msg", ({
                        (: goaway :),
        }) );  
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "强盗显是以劫为生，刀刀冲要害而来。\n",
              "强盗高喊：叫你人财两空。\n",
        }) ); 
        set("force",5000);
        set("force_factor",20);
        set_skill("unarmed", 100);
        set_skill("blade", 160);
        set_skill("dodge", 140);
        set_skill("parry", 150);
        set_skill("move",100);
        set_skill("demon-steps",100);
        set_skill("demon-blade",120);
        map_skill("dodge","demon-steps");
        map_skill("move","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        setup();
        add_money("coin", 10); 
        carry_object(__DIR__"obj/guiblade")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
void goaway()
{
        object ob;
        if (ob=present("biao tou",environment()) )
        {
                command("grin");
                kill_ob(ob);
                ob->kill_ob(this_object());
                return; 
        }
                
        message_vision("$N一声唿哨，消失得无影无踪！\n",this_object());
        destruct(this_object());
}  
