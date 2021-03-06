// duanyu.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("王语嫣", ({ "wang yuyan","wang"}) );
        set("nickname", HIG "神仙姐姐"NOR);
        set("gender", "女性" );
        set("per", 45);
        set("agi",25);
        set("int",35);
        set("skill_public",1);
        
//        create_family("大理", 1, "王子");
        set("long",
                "她穿着一身翠绿色的长裙，容貌极其美丽，若仙女下凡，只是眼中带着一丝丝的忧伤。 \n"
                );
       set("chat_chance", 5);
        set("chat_msg", ({
                "王语嫣说道：哎。。不知道表哥什么时候才能回来？\n",
                "王语嫣说道：段公子到是对我一往情深，不知他现在怎么样了？\n",
        }) );

        set("inquiry", ([
                "表哥": "不知道表哥什么时候才能回来？\n",
                "段誉": "唉，段公子他人很好，只是我心里只有表哥。。。\n",
                "拜师": "你要是有我表哥的消息，我就教你。\n",
                "仙女图": "仙女图好象在东边不远的无量山洞里。\n",
        ]) );
        set("attitude", "peaceful");
//        set("chat_chance_combat", 90);
        set_skill("move", 300);
        set_skill("literate", 300);
        set("combat_exp", 10000000);
        setup();
        carry_object(__DIR__"obj/lvcloth")->wear();
}

int recognize_apprentice(object ob)
{
 object xin;

 if(ob->query("class") != "dali") 
  {
   message_vision("王语鄢说道：你不是大理人，我不能教你！\n", ob);
   return 0;
  }
 if(ob->query("gongxian") < 34560) 
  {
   message_vision("王语鄢说道：你的官职不够，还是先和别人学吧。\n", ob);
   return 0;
  }
 if( !ob->query("marks/wangyuyan") ) 
  {
   say("王语嫣说道：你要是有我表哥的消息，我就教你。\n");
   return 0;
  }
 return 1;
}

int accept_object(object who, object ob)
{
 int bonus;
 if( ob->name() != "表哥的信")
  {
   say("王语嫣说道：唉，我要这有什么用呢....\n");
   return 0;
  }
  else
   {
    if(ob->query("names") != who->query("name")) 
    {
     write("王语鄢说道:这信你从哪偷来的，我没收了！\n");
     return 1;
    }
    who->set("marks/wangyuyan", 1);
    say("王语嫣说道：太好了！终于有表哥的消息了....\n");
    if(!who->query("m_success/王语嫣"))
     {
      who->set("m_success/王语嫣",1);
      who->add("score",500);
      bonus = random(50);
      who->add("combat_exp", bonus);
      bonus = bonus + random(10);
      who->add("potential", bonus );
     }
    return 1;       
   }
 return 0;
}
