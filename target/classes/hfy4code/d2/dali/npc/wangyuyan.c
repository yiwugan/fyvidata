// duanyu.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("������", ({ "wang yuyan","wang"}) );
        set("nickname", HIG "���ɽ��"NOR);
        set("gender", "Ů��" );
        set("per", 45);
        set("agi",25);
        set("int",35);
        set("skill_public",1);
        
//        create_family("����", 1, "����");
        set("long",
                "������һ�����ɫ�ĳ�ȹ����ò��������������Ů�·���ֻ�����д���һ˿˿�����ˡ� \n"
                );
       set("chat_chance", 5);
        set("chat_msg", ({
                "������˵������������֪�����ʲôʱ����ܻ�����\n",
                "������˵�����ι��ӵ��Ƕ���һ�������֪��������ô���ˣ�\n",
        }) );

        set("inquiry", ([
                "���": "��֪�����ʲôʱ����ܻ�����\n",
                "����": "�����ι������˺ܺã�ֻ��������ֻ�б�硣����\n",
                "��ʦ": "��Ҫ�����ұ�����Ϣ���Ҿͽ��㡣\n",
                "��Ůͼ": "��Ůͼ�����ڶ��߲�Զ������ɽ���\n",
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
   message_vision("����۳˵�����㲻�Ǵ����ˣ��Ҳ��ܽ��㣡\n", ob);
   return 0;
  }
 if(ob->query("gongxian") < 34560) 
  {
   message_vision("����۳˵������Ĺ�ְ�����������Ⱥͱ���ѧ�ɡ�\n", ob);
   return 0;
  }
 if( !ob->query("marks/wangyuyan") ) 
  {
   say("������˵������Ҫ�����ұ�����Ϣ���Ҿͽ��㡣\n");
   return 0;
  }
 return 1;
}

int accept_object(object who, object ob)
{
 int bonus;
 if( ob->name() != "������")
  {
   say("������˵����������Ҫ����ʲô����....\n");
   return 0;
  }
  else
   {
    if(ob->query("names") != who->query("name")) 
    {
     write("����۳˵��:���������͵���ģ���û���ˣ�\n");
     return 1;
    }
    who->set("marks/wangyuyan", 1);
    say("������˵����̫���ˣ������б�����Ϣ��....\n");
    if(!who->query("m_success/������"))
     {
      who->set("m_success/������",1);
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
