#include <ansi.h>
inherit NPC; 
void create()
{
//      string *name = ({"坎","力","雷","畅"});
//      set_name("铁"+name[random(sizeof(name))], ({"fighter wolf"}) );
        set_name("铁畅",({"fighter wolf"}));
        set("gender", "男性" );
        set("nickname", HIR"狼山铁卫"NOR);
        set("long", "这是一个精力旺盛的狼山卫士，负责狼山的守卫，巡视。\n");
        set("attitude", "friendly");
/*      set("max_gin", 400);
        set("max_kee", 400);
        set("max_sen", 400); */
        set("age", 18+random(10));
        set("str", 20+random(10));
        set("cor", 20);
        set("cps", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
                "狼山铁卫舔了舔嘴唇：好久没有吃到烤野兔肉了！\n",
        }) );
        set("combat_exp", random(80000)+100000);
        create_family("狼山", 1, "第四代弟子");
        set_skill("blade", 50+random(20));
        set_skill("parry", 50+random(20));
        set_skill("dodge", 50+random(20));
        set_skill("move", 50+random(20));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/wolfblade")->wield();
        add_money("silver", random(100));
} 
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
           call_out("greeting", 2, ob);
        }
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;
   
        if (ob->query("class") != "wolfmount")
        {
        message_vision("$N傲然道：我们狼山男儿，个个都是铁打的汉子！\n",this_object());
                return;
        }
        else
        {
        message_vision("$N向$n一拱手道：这位同门辛苦了，下山又宰了不少肥羊吧? \n", this_object(), ob);
                return;
        }
} 
int accept_object(object me, object obj)
{       
        object npc;
        npc = this_object();
        if( obj->query("name") == "烤野兔肉" )
        {
                command("say 好！好！多谢你！\n");
                command("whisper "+me->query("id")+" 狼山比较危险，随便走走就下山吧．\n");
                me->set_temp("marks/狼山游客",1);
                return 1;       
        }
        else
        {
                command("shake "+me->query("id"));
                return 0;
        }
        return 1;
}       
