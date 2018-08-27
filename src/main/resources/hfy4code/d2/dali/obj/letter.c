#include <armor.h>
inherit ITEM;
#include <ansi.h>
void diu();
void create()
{
        string st11;
        string *order=({"南宫十一郎","南宫十三郎","南宫十四郎","吴青","蓝胡子","一已","一争",
"大胡子","忏悔徒","楚楚","莫不屈","中年书生","渔夫","文人墨客","一那",
"马老四","珠宝商","冷红儿","中药店老板","武林大豪杰","风四娘","王若钢","人和老人","茅大先生",
"城卫","胭松","班察那","心湖","地匹","莲风儿","冷血刺客","陆小凤","常老大","香香","方灵玉"});
        set_name(("密函"), ({ "letter"}) );
        st11=order[random(35)];
        set("toname",st11);
        set("long", HIW"请送(song)"+ st11 + "亲启\n"NOR);
        set_weight(1000);
        set("value", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
        }
//        setup();
        call_out("diu", 90, 1);  
}
void diu()
{
 if (!random((int)(this_player()->query("kar")/2)))
  {
   message_vision("$N向怀里一摸，发现密函已经不见了，哎！！运气真差。。。。\n",this_player());
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
	 return notify_fail("你要把信给谁？\n");
   if (userp(obj)) 
		return notify_fail("我KAO！你有没搞错？\n"); 
         if(ob->query("pname") != me->query("name")) 
   {
    obj->ccommand("say 这不是你的，没收。");
    destruct(this_object());
    return 1;
   }
  if(me->query("letter") < time())
   {
    obj->ccommand("say 哎，晚了，你来晚了！");
    return 1;
   }
  if(ob->query("toname") == obj->query("name"))
  {
   obj->ccommand("say 感谢这位远道把密函送来，这是给你的回函,切记要保管好！！\n");
   me->set_temp("nofly",0);
   silk = new("/d/dali/obj/huihan");
   silk->set("pname",me->query("name"));
   silk->move(me);
   destruct(present("letter",me));
   return 1;
  }
   obj->ccommand("say 这不是我想要的。");
   return 1;
}
