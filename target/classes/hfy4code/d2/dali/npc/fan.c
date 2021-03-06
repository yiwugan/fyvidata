// lmd@wenxin
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int give_him();

void create()
{
        set_name("范骅", ({ "fan hua", "fan"}) );
        set("title","大理司马");
        set("gender", "男性" );
        set("age", 46);
        set("agi",30);
        set("str", 22);
        set("per", 28);
        set("int",24);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 40);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"这是个中年汉子，目下在大理国位居司徒。\n"
        );
        create_family("大理", 12, "弟子");
        set("chat_chance_combat", 20);
        set("combat_exp", 1000000);
        set_skill("dodge", 110);
        set_skill("move",140);
        set_skill("force", 140);
        set_skill("sword", 110);
        set_skill("literate", 120);
        set_skill("unarmed",110);
        set_skill("duan-yiyangzhi", 110);
        map_skill("force", "tianlong-shengong");
        map_skill("unarmed", "duan-yiyangzhi");
        set("inquiry", ([
                "密函" : (: give_him :),
                "letter" : (: give_him :)
        ]));
        setup();
       carry_object(__DIR__"obj/guanfu")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N说道：“大理皇宫正需要一批义士．．。”\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N望了$n一眼，问道：这些的任务可能对你的前程很重要．．。\n",this_object(),ob);
                        break;
        }
}

int give_him()
{
        string *order1 = ({"/u/quicksand/desert6","/d/dali/quan5","/u/wudang/farm4","/u/quicksand/desert3","/u/quicksand/desert5","/u/wudang/farm5","/d/dali/quan6","/d/manglin/center2","/u/wudang/farm6","/d/manglin/center4","/d/dali/quan7","/u/wudang/farm7","/d/manglin/center1","/d/dali/quan2","/u/wudang/farm9","/d/dali/quan3"});
        string time11;
        object me , obj ,room1;
        int xintime,m,s;
        me = this_player();        
        if(me->query("class") != "dali") 
           {
         message_vision("$N说道：你不是大理官员，不能申请这样的任务！\n",this_object(), me);
         return 1;
            }
        if(me->query("gongxian") < 15000) 
           {
         message_vision("$N说道：你的官职不够，不能申请这么重要的任务！还是去做一些简单的吧。\n",this_object(), me);
         return 1;
            }
         if(me->query("gongxian") > 35000) 
           {
         message_vision("$N说道：你在大理的修练已经功德圆满了。\n",this_object(), me);
         return 1;
            }
        if(me->query("lettertime") > time()) 
           {
            tell_object(me,"范骅说道：你的上一封信还没送到，怎么还来问我要？！\n");
            return 1;
           }
        obj = new("/d/dali/obj/letter");
        xintime = 100+me->query("kar")*10+random(50);
        s = xintime % 60;             m = xintime / 60;
        room1 = load_object(order1[random(16)]);
        me->set("lettertime",time()+xintime);
        obj->set("pname",me->query("name"));
        time11 = "范骅说道：";
        time11 += room1->query("short");
        time11 += "有一封密函，一定要在"HIW;
        time11 += chinese_number(m) + "分";
        time11 += chinese_number(s) + "秒" ;
        time11 += NOR "内送交给" HIW ;
        time11 += obj->query("toname") + NOR"。我先送你去那里。\n";
        tell_object(me, time11);
        me->set("letter",time()+600+random(300));
        me->add("giveletter",1);        
        obj->move(me);
        me->move(room1);
        tell_object(me,"一个神秘蒙面人给了你一封密函。\n");
        me->set_temp("nofly",1);
        me->set_temp("noburn",1);
        return 1;
}

int accept_object(object who, object ob)
{
  int  exp, pot, gong, score;
  exp = random(100)+200;
  pot = exp / 5;
  gong = exp / 100 + 15 +random(10) ;
  score = exp / 100 + random(10) ;
  if(!(who->query("class") == "dali") )
    {
     write("范骅说道:你不是大理弟子，这种来历不明的东西我不要！\n");
     return 0;
    }
  if(ob->query("name") == "回函")
    {
     who->delete("lettertime");
     if(!(ob->query("pname") == who->query("name")) )
      {
       write("范骅说道:这种来历不明的东西我没收了！\n");
       return 1;
      }
     command("nod");     
     command("say 好! 为国家做出了贡献，应该得到奖励！\n");
        who->add("finletter",1);
        who->add("combat_exp",exp);
        who->add("potential",pot);
//        who->add("score",score);
        who->add("gongxian",gong);
        who->delete_temp("lettertime");
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(gong) + "点对大理国的贡献点\n" NOR);
//        chinese_number(score) + "点综合评价。\n"
        return 1;
    }
  tell_object(who,"范骅说道：这不是我想要的。\n");
  return 0;
}
