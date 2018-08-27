inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int give_him();
// int kill_him();
void create()
{
        set_name("华赫艮", ({ "hua hegen", "hua"}) );
//        set("nickname", "");
//        set("pursuer", 1);
        set("title","大理司徒");
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
"
这是个中年汉子，目下在大理国位居司徒。\n"
        );
        create_family("大理", 12, "弟子");
        set("chat_chance_combat", 20);
//        set("chat_msg_combat", ({
//                (: perform_action, "blade.liuyunxiyu" :)
//        }) );
        set("combat_exp", 1000000);
        set_skill("dodge", 110);
        set_skill("move",140);
        set_skill("force", 140);
        set_skill("sword", 110);
        set_skill("literate", 120);
        set_skill("unarmed",110);
//      set_skill("tianlong-shengong", 110);
        set_skill("duan-yiyangzhi", 110);
        map_skill("force", "tianlong-shengong");
        map_skill("unarmed", "duan-yiyangzhi");
//        map_skill("parry", "");        
// map_skill("parry","huanyu-blade");
//       map_skill("blade", "huanyu-blade");    
        set("inquiry", ([
                "茶花" : (: give_him :),
                "chahua" : (: give_him :)
        ]));
        setup();
     carry_object(__DIR__"obj/guanfu")->wear();
//  carry_object(__DIR__"obj/long-blade")->wield();

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
message_vision("$N说道：“大理皇宫正需要一些上等茶花．．。”\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N望了$n一眼，问道：你对养茶花感兴趣吗？．．。\n",this_object(),ob);
                        break;
        }
}
int give_him()
{
        object me , obj;
        me = this_player();
 
        if(me->query("gongxian") > 1000) 
           {
         message_vision("$N说道：你的官职太大啦，不要申请这么简单的任务！还是去做一些更难的吧。\n",this_object(), me);
         return 1;
            }
//      if( !query("given")) {
        obj = new("/questnew/huapen");
        message_vision("$N说道：既然你对养茶花感兴趣，我就把这项重要的工作交付给你了，
华赫艮给了$n一个精致花盆。\n",this_object(), me);
        obj->move(me);
//      set("given",1);
        return 1;
//      }
//      return 0;
}


int accept_object(object who, object ob)
{
  int  exp, pot, gong, score;
  exp = random(100)+10000;
  pot = exp / 5 + 100;
  gong = exp / 50 + 2;
  score = exp / 50 +5;
//   if(!(who->query("class") == "dali") )
// {
//   write("华赫艮说道:你不是大理弟子，这种来历不明的东西我不要！\n");
//     return 0;
// 115
//  }
  if(!(ob->query("pname") == who->query("id")) )
    {
     write("华赫艮说道:这茶花不是你种出来的，这种来历不明的东西我没收了！\n");
     return 1;
    }
  if(ob->query("name") == "[1;33m极品茶花[2;37;0m")
    {
     tell_object(who, "华赫艮说道：你为国家做出了贡献，给你应该得到奖励！\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
//      who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(gong) + "点对大理国的贡献点\n" NOR);
//      chinese_number(score) + "点综合评价。\n"
        return 1;
    }
  if(ob->query("name") == "[1;32m一品茶花[2;37;0m")
    {
     tell_object(who, "华赫艮说道：你为国家做出了贡献，给你应该得到奖励！\n");
        who->add("combat_exp",exp*3/4);
        who->add("potential",pot*3/4);
//      who->add("score",score*3/4);
        who->add("gongxian",gong*3/4);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp*3/4) + "点实战经验\n"+
        chinese_number(pot*3/4) + "点潜能\n"+
        chinese_number(gong*3/4) + "点对大理国的贡献点\n" NOR);
//        chinese_number(score*3/4) + "点综合评价。\n"
        return 1;
    }
  if(ob->query("name") == "[33m二品茶花[2;37;0m")
    {
     tell_object(who, "华赫艮说道：你为国家做出了贡献，给你应该得到奖励！\n");
//     command("say 你为国家做出了贡献，给你应该得到奖励！\n");
        who->add("combat_exp",exp/2);
        who->add("potential",pot/2);
//      who->add("score",score/2);
        who->add("gongxian",gong/2);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp/2) + "点实战经验\n"+
        chinese_number(pot/2) + "点潜能\n"+
        chinese_number(gong/2) + "点对大理国的贡献点\n" NOR);
//        chinese_number(score/2) + "点综合评价。\n"
        return 1;
    }
  if(ob->query("name") == "[1;37m三品茶花[2;37;0m")
    {
     tell_object(who, "华赫艮说道：你为国家做出了贡献，给你应该得到奖励！\n");
//     command("say 你为国家做出了贡献，给你应该得到奖励！\n");
        who->add("combat_exp",exp/4);
        who->add("potential",pot/4);
//      who->add("score",score/4);
        who->add("gongxian",gong/4);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp/4) + "点实战经验\n"+
        chinese_number(pot/4) + "点潜能\n"+
        chinese_number(gong/4) + "点对大理国的贡献点\n" NOR);
//        chinese_number(score/4) + "点综合评价。\n"
        return 1;
    }
  tell_object(who,"华赫艮说道：大理皇宫会需要这种烂茶花吗？\n");
  return 0;
}
