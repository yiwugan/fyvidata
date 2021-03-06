// duanyu.c

inherit NPC;
#include <ansi.h>
void create()
{
 set_name("段誉", ({ "duan yu","duan"}) );
 set("nickname", HIG "痴情公子"NOR);
 set("gender", "男性" );
 set("per", 45);
 set("agi",25);
 set("int",35);
 set("skill_public",1);

 create_family("大理", 1, "王子");
 set("long", "他是一个身穿锦衣的年轻男子。脸孔略尖，自有一股书生的呆气。 \n"
             "他为人友善随和。\n");
 set("chat_chance", 5);
 set("chat_msg", ({
      "段誉说道：也不知道王姑娘现在怎么样了？\n",
      "段誉说道：不知道大哥和二哥现在在什么地方？\n",}) );

 set("inquiry", ([
        "大理": "大理是个好地方，山清水秀，风景宜人。。\n",
        "王语嫣": "唉，她心里只有她表哥，从来就没把我放在眼里。",
        "拜师": "你要是能找到“仙女图”我就收你做徒弟。", ]) );
 set("attitude", "peaceful");
 set("chat_chance_combat", 90);
 set("chat_msg_combat", ({
    (: perform_action, "duan-yiyangzhi.liumai" :),
    (: perform_action, "dodge.piaoyi" :), }) );
 set_skill("move", 200);
 set_skill("unarmed", 200);
 set_skill("liumaishenjian", 150);
 set_skill("force", 280);
 set_skill("duan-yiyangzhi",220);
 set_skill("lingbo-steps", 150);
 set_skill("beiming-force", 150);
 set_skill("dodge", 200);
 set_skill("literate", 200);
 map_skill("duan-yiyangzhi", "liumaishenjian");
 map_skill("force", "beiming-force");
 map_skill("dodge", "lingbo-steps");
 map_skill("unarmed", "duan-yirangzhi");
 set("combat_exp", 10000000);
 setup();
 carry_object(__DIR__"obj/beiming-cloth")->wear();
 carry_object(__DIR__"obj/lingbo-boots")->wear();
 carry_object(__DIR__"obj/liumai-ring")->wear();
}

int recognize_apprentice(object ob)
{
 object xin;
if(ob->query("m_scusse/无量洞")&&ob->query("m_scusse/金瓶梅")) return 1;
else {

 if(ob->query("class") != "dali") 
  {
   message_vision("段誉说道：你不是大理人，我不能教你！\n", ob);
   return 0;
  }
 if(ob->query("gongxian") < 34560) 
  {
   message_vision("段誉说道：你的官职不够，还是先和别人学吧。\n", ob);
   return 0;
  }
 if( !ob->query("marks/duanyu") )
  {
   say("段誉说道：你先把这封信交给王姑娘，再帮我找回“仙女图”。
我愿意把我一身的功夫都教给你。\n");
   xin = new("/d/dali/obj/biaogexin");
   xin->set("names",ob->query("name"));
   xin->move(ob);
   return 1;
}}
 return 1;
}

int accept_object(object who, object ob)
{
 int bonus;
 if( ob->name() != "仙女图")
  {
   say("段誉说道：唉，我要的是仙女图....\n");
   return 0;
  }
    if(ob->query("names") != who->query("name")) 
    {
     write("段誉说道:这仙女图你从哪偷来的，我没收了！\n");
     return 0;
    }
    if(who->query("marks/duanyu_over")) 
    {
     write("段誉说道:这仙女图你从哪偷来的，我没收了！\n");
     return 0;
}
    who->set("marks/duanyu", 1);
    who->set("marks/duanyu_over", 1);
    say("段誉说道：太好了！我遗失的仙女图终于找到了....\n");
    if(!who->query("m_success/段誉"))
     {
      who->set("m_success/段誉",1);
      who->add("score",500);
      bonus = random(50);
      who->add("combat_exp", bonus);
      bonus = bonus + random(10);
      who->add("potential", bonus );
     }
    return 1;       
   }
