 //TIE@FY3`
inherit NPC;
void create()
{
        set_name("轩辕三缺", ({ "san que" }) );
        set("gender", "男性" );
        set("age", 53);
        set("title","独眼单足");
        set("long", "轩辕三成的兄弟，武功高绝，为人心狠手辣。\n");
        set("combat_exp", 4000000);
        set("reward_npc", 1);
        set("fly_target",1);
        set("intellgent",1);
        set("difficulty", 5);
//      set("str", 27);
        set("force", 200);
//        set("attitude", "aggressive");
        set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 20);
        set("chat_chance", 20);
        set("chat_msg", ({
"轩辕三缺大笑道：想破我的“天昏地暗，七杀大阵”？\n",
"轩辕三缺笑道：萧十一郎若不是仗着他那把割鹿刀，怎能破我的七杀大阵？\n",
                (: random_move :),
         }) );
        set("inquiry", ([
                "萧十一郎" : "我刚刚从他的腿上割下一块肉，他跑了。\n",
                "xiao 11" : "我刚刚从他的腿上割下一块肉，他跑了。\n",
        ]) );
        setup();
    add_money("gold", 3);
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/qin")->wield();
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
                message_vision("$N冷冷的看着你：“肥羊入口，难道还想跑？老子杀了你！！！！！”\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                command("hug "+ob->query("id"));
                message_vision("$N对你阴笑道：兄弟今天又到哪里打家劫舍？\n", this_object() );
        }
        return;
}     
