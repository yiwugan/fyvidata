// duanyu.c

inherit NPC;
#include <ansi.h>
void create()
{
 set_name("����", ({ "duan yu","duan"}) );
 set("nickname", HIG "���鹫��"NOR);
 set("gender", "����" );
 set("per", 45);
 set("agi",25);
 set("int",35);
 set("skill_public",1);

 create_family("����", 1, "����");
 set("long", "����һ�������µ��������ӡ������Լ⣬����һ�������Ĵ����� \n"
             "��Ϊ��������͡�\n");
 set("chat_chance", 5);
 set("chat_msg", ({
      "����˵����Ҳ��֪��������������ô���ˣ�\n",
      "����˵������֪�����Ͷ���������ʲô�ط���\n",}) );

 set("inquiry", ([
        "����": "�����Ǹ��õط���ɽ��ˮ�㣬�羰���ˡ���\n",
        "������": "����������ֻ������磬������û���ҷ������",
        "��ʦ": "��Ҫ�����ҵ�����Ůͼ���Ҿ�������ͽ�ܡ�", ]) );
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
if(ob->query("m_scusse/������")&&ob->query("m_scusse/��ƿ÷")) return 1;
else {

 if(ob->query("class") != "dali") 
  {
   message_vision("����˵�����㲻�Ǵ����ˣ��Ҳ��ܽ��㣡\n", ob);
   return 0;
  }
 if(ob->query("gongxian") < 34560) 
  {
   message_vision("����˵������Ĺ�ְ�����������Ⱥͱ���ѧ�ɡ�\n", ob);
   return 0;
  }
 if( !ob->query("marks/duanyu") )
  {
   say("����˵�������Ȱ�����Ž���������ٰ����һء���Ůͼ����
��Ը�����һ��Ĺ��򶼽̸��㡣\n");
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
 if( ob->name() != "��Ůͼ")
  {
   say("����˵����������Ҫ������Ůͼ....\n");
   return 0;
  }
    if(ob->query("names") != who->query("name")) 
    {
     write("����˵��:����Ůͼ�����͵���ģ���û���ˣ�\n");
     return 0;
    }
    if(who->query("marks/duanyu_over")) 
    {
     write("����˵��:����Ůͼ�����͵���ģ���û���ˣ�\n");
     return 0;
}
    who->set("marks/duanyu", 1);
    who->set("marks/duanyu_over", 1);
    say("����˵����̫���ˣ�����ʧ����Ůͼ�����ҵ���....\n");
    if(!who->query("m_success/����"))
     {
      who->set("m_success/����",1);
      who->add("score",500);
      bonus = random(50);
      who->add("combat_exp", bonus);
      bonus = bonus + random(10);
      who->add("potential", bonus );
     }
    return 1;       
   }
