#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("马鞭", ({"ma bian","ma"}) );
        set("gender", "男性" );
        set("nickname", RED"索魂鞭"NOR);
        set("title", "青龙会 刺客");
        set("long", "长长瘦瘦，整个人就是根鞭子，而手中的马鞭也是他的生命。\n");
        set("attitude", "friendly");
        set("age", 35);
        set("cor", 25);
        set("cps", 25);
        set("combat_exp", 1500000);
        set("class","yinshi");
        set("force", 2000);
            set("reward_npc", 1);
            set("difficulty", 2);
        set("max_force", 2000);
        set("force_factor", 60);
        set_temp("apply/armor", 100); 
        
        set_skill("whip", 150);
        set_skill("thunderwhip", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("fengyu-piaoxiang",200);
        set_skill("luoriquan",200);
        set_skill("unarmed",200);
        
        map_skill("move","fengyu-piaoxiang");
        map_skill("unarmed","luoriquan");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("whip", "thunderwhip");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("dodge.zonghengsihai") :),    
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "马鞭甩了甩手中长鞭，讥诮地望着你。\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/horsewhip")->wield();
        carry_object("/obj/armor/cloth")->wear();
        if (!random(5)) carry_object(__DIR__"obj/stone_1");
                else add_money("gold", random(4));
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() )
                return;
        if (!ob->query("vendetta/authority")){
            message_vision("$N嘿嘿道：够胆量！私闯青龙会的地头，拿命来吧！\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}  
