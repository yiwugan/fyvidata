#include <armor.h>
inherit ITEM;
#include <ansi.h>
void diu();
void create()
{
        string st11;
        string *order=({"�Ϲ�ʮһ��","�Ϲ�ʮ����","�Ϲ�ʮ����","����","������","һ��","һ��",
"�����","���ͽ","����","Ī����","��������","���","����ī��","һ��",
"������","�鱦��","����","��ҩ���ϰ�","���ִ����","������","������","�˺�����","é������",
"����","����","�����","�ĺ�","��ƥ","�����","��Ѫ�̿�","½С��","���ϴ�","����","������"});
        set_name(("�ܺ�"), ({ "letter"}) );
        st11=order[random(35)];
        set("toname",st11);
        set("long", HIW"����(song)"+ st11 + "����\n"NOR);
        set_weight(1000);
        set("value", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
//        setup();
        call_out("diu", 90, 1);  
}
void diu()
{
 if (!random((int)(this_player()->query("kar")/2)))
  {
   message_vision("$N����һ���������ܺ��Ѿ������ˣ�������������������\n",this_player());
   this_player()->delete("lettertime") ;
   this_player()->delete_temp("nofaly") ;
   this_player()->delete("noburn") ;
   destruct(this_object());
   return;
  }
}
void init()
{
  add_action("do_song","song");
}

int do_song(string arg)
{
         object me,obj,silk,ob;
         me=this_player();
         ob=present("letter",me);
         if (!arg||!obj = present(arg, environment(me)))
	 return notify_fail("��Ҫ���Ÿ�˭��\n");
   if (userp(obj)) 
		return notify_fail("��KAO������û���\n"); 
         if(ob->query("pname") != me->query("name")) 
   {
    obj->ccommand("say �ⲻ����ģ�û�ա�");
    destruct(this_object());
    return 1;
   }
  if(me->query("letter") < time())
   {
    obj->ccommand("say �������ˣ��������ˣ�");
    return 1;
   }
  if(ob->query("toname") == obj->query("name"))
  {
   obj->ccommand("say ��л��λԶ�����ܺ����������Ǹ���Ļغ�,�м�Ҫ���ܺã���\n");
   me->set_temp("nofly",0);
   silk = new("/d/dali/obj/huihan");
   silk->set("pname",me->query("name"));
   silk->move(me);
   destruct(present("letter",me));
   return 1;
  }
   obj->ccommand("say �ⲻ������Ҫ�ġ�");
   return 1;
}
