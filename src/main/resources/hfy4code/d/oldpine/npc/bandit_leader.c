 // bandit_leader.c
inherit NPC; 
void create()
{
        set_name("土匪首领", ({ "bandit leader", "chief", "leader" }) );
        set("gender", "男性");
        set("age", 47);
        set("long",     "这家伙眼神凶恶，一双精光四射的眼珠正盯著你的脖子。\n");
        set("combat_exp", 50000);
        set("score", 7700);
        set("bellicosity", 3000);
        set("attitude", "friendly"); 
        set("max_force", 700);
        set("force", 1300);
        set("force_factor", 4); 
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "\n土匪首领阴恻恻地说道：这种三脚猫的功夫也敢上老云寨来撒野？！\n",
                "\n土匪首领说道：去你的，老子今天要剁下你的头来练练毒爪！\n",
                "\n土匪首领虎吼一声，欺身上前。\n"
        }) );
        set_skill("blade", 60);
        set_skill("parry", 70);
        set_skill("dodge", 70); 
        // Because the chief's 武功 is not done yet, set apply to replace it.
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 50); 
        setup();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        add_money("coin", 300);
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
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "bandit")
        {
                message_vision("$N看着你大声呼喊到：“兄弟们，肥羊入口！”\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                message_vision("$N对你阴笑道：兄弟今天又到哪里打家劫舍？\n", this_object() );
        }
        return;
}     