#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("柳金莲", ({"liu jinlian","liu"}) );
        set("gender", "女性" );
        set("nickname", HIM "母色狼"NOR);
        set("long", "这女人的一双脚简直象是两条小船，血盆大口似乎随时准备把你一口给吞下去。\n");
        set("attitude", "friendly");
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("age", 36);
        set("str", 25);
        set("cor", 30);
        set("cps", 30);
        set("combat_exp", 1000000);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set("chat_chance", 10);
        set("chat_msg", ({
        "柳金莲咧着大嘴磔磔怪笑：那些男人都是姑奶奶我的玩物，哈哈。。！\n",
        (: random_move :),

        }) );
        setup();
        carry_object(__DIR__"obj/redskirt")->wear();
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
   if (ob->query("gender") == "男性" && ob->query("combat_exp") > 1000000 )
        {
                message_vision("$N整个人突然向$n扑了过去：“我老公死了，就拿你来顶替吧。”\n", this_object(),ob );
                this_object()->kill_ob(ob);
        }
        return;
}     
