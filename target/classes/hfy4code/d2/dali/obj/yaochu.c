#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("��ҩ��", ({ "yaochu" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("long", "һ��ר��������ҩ�Ĳ�ҩ�������ƺ�������������(wa)Щҩ��(yaocai)��\n");
                set("weapon_prop/karma",1);
        }
        ::init_hammer(5);
        
}
void init()
{
        if(environment(this_object())==this_player())
        if (!wizardp(this_player())) {
        set("no_get"," ���ǲ�Ҫ�Ҷ�����Ķ���Ϊ��! \n");
        set("no_drop","����Ķ�����ô������Ҷ���! \n");
        set("no_give","����Ķ�����ô���������أ�\n");
       }
        add_action("do_read","wa");
        add_action("do_go","go");
}

int do_read(string arg)
{
object me;
mapping exits;
string *dirs;
string thisdir;
if(arg != "yaocai" && arg != "ҩ��") return 0;
me=this_player();
if (me->query("gongxian")>40000) return notify_fail("��Ĺ�ְ̫���ˣ������ٸ����ִֻ���!\n");
if(find_call_out("markit")== -1)
call_out("markit",random(2)+1,me);
if( !mapp(exits = environment(me)->query("exits")) ) 
{
tell_object(me,"ƾֱ�����������Χ����������һ���������ҩ�ģ�\n");
return 1;
}
        dirs = keys(exits);
        thisdir = dirs[random(sizeof(dirs))];
        set("thisdir",thisdir);
 if (me->query("sen") < 70) 
  {
   tell_object(me,"���Ѿ�û�������ˣ�\n");
   return 1;
  }
 if (me->query("kee") < 70) 
  {
   tell_object(me,"���Ѿ�û�������ˣ�\n");
   return 1;
  }
 if (me->query("gin") < 70) 
  {
   tell_object(me,"���Ѿ�û�������ˣ�\n");
   return 1;
  }
        tell_object(me,"����ҵ��ڼ���ͷ���۵���ͷ�󺹣���ʲôҲû�ҵ���
��������ȥ"+thisdir+"�ķ�������������\n");
         me->add("sen",-(random(50)+20));
         me->add("kee",-(random(50)+20));
         me->add("gin",-(random(50)+20));


        return 1;
}

int do_go(string arg)
{
        if(arg==query("thisdir"))
        this_player()->add_temp("going",1);
        return 0;
}
int markit(object me)
{
object yaocai;
if(me->query_temp("going") <= 10 || environment()!=me) return 1;
if(random(me->query("kar")/2))
{
yaocai = new(__DIR__"yaocai");
tell_object(me,"\n\n���ҩ������������Щʲô���ⶫ������ȥ����ҩ�ģ��������ԥ�ذ������ڻ��\n");
//gold->set_amount(10);
yaocai->move(me);
yaocai->set("pname",me->query("id"));
me->delete_temp("going");
//set("already",1);
}
return 1;
}
