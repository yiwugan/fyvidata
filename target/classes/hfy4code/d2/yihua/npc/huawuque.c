#include <ansi.h>
inherit NPC;

void create()
{
        set_name("花神", ({ "hua shen","hua","shen"}) );
set("long",
            "这是个极其神秘的男人,\n"+
            "其实原是什么门派已经无从稽考，而他的武功厉害程度，比\n东岳大帝也怕他几分，他玉树临风，风度翩翩.\n"+
            "因为用掌他在兵器榜却没有他的名字.\n");
        set("gender", "男性" );
        set("age", 318);
        set("combat_exp", 180000000);
        set("shen_type",1000);
        set("str", 180);
        set("dex", 180);
        set("con", 180);
        set("int", 180);

            set("sen", 1000000);
        set("max_sen", 1000000);
            set("kee", 3000000);
        set("max_kee", 3000000);
        set("gin", 50000);
    set("max_gin", 5000);
    set("force", 1000000);
    set("max_force", 20000);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move",200);
        set_skill("unarmed",200);

        set_skill("yihua-jiemu",200);
        set_skill("yifeng-jian",200);

 //       map_skill("unarmed", "jueqing-zhang");
//        map_skill("force", "mingyu-shengong");
 //       map_skill("dodge", "yihua-jiemu");
  //      map_skill("parry", "yihua-jiemu");
   //     map_skill("sword", "yifeng-jian");

        create_family("花神",2,"花仙子");
        set("chat_chance_combat", 50);
 //       set("chat_msg_combat", ({
  //              (: perform_action, "sword.yifeng" :),
   //                     }) );
        setup();
    carry_object("/d/yihua/obj/jinlvyi")->wear();
        carry_object("/obj/weapon/sword")->wield();
        add_money("gold",15);
        set("attitude", "friendly");
        set("chat_chance",20);
        set("chat_msg",({
        "花神说道：天下有情却无情，梦醒又如旧梦，悲喜欢笑渡一生！哎\n",
        "花神说道：杀我者杀，杀人者杀！\n",
        "花神自言自语道：天若有情天已老，人若有情人已愁！\n",
           }) );
       set("inquiry",([

       "花神" : "我的爱人离开我，你知道他在那里吗？\n",
           "小芳" : "她就是我的爱人，你是怎么知道她的？！\n",
           ]) );
       setup();
}

void init()
{
        object ob;

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
}
int accept_object(object me, object obj)
{
	if(obj->query("for_fang"))
	{
	me->set_temp("for_fang",1);
         command("say 难道。。。。唉！\n");
        command("recruit " + me->query("id") );
	return 1;
	}
	return 0;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("花神一见有人进来急忙说：" + RANK_D->query_respect(ob)
          +"，你是什么人怎么跑到这里来了速速离开!\n");
}
