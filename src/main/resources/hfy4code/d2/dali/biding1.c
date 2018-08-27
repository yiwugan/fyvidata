inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "峭壁顶");
        set("long", @LONG
这是峭壁顶上的一块平地，四周长着一些老藤，西面是
一条很宽的裂缝，好象能爬（ｃｌｉｍｂ）下去。东面是一
个山谷。
LONG
        );
        set("coor/x",-700);
        set("coor/y",-900);
        set("coor/z",150);
        setup();
}

init()
{
 add_action("do_climb","climb");
 add_action("do_jump", "jump");
}

int do_climb(string arg)
{
 object me;

 if(!arg || arg != "down") 

  {
   write("你要往哪里爬？\n");
   return 1;
  }
 me = this_player();
 message_vision( "\n$N抓着藤条，沿着峭壁的西面慢慢地爬了下去。\n" , me);
 me->start_busy(4);
 call_out("fliping",4,me);
 me->stop_busy();
 return 1;
}

int fliping(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"shangu");
        message_vision("$N顺着峭壁爬了下来。\n", me);
        }
        return 1;
}


int do_jump(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "east") 
    {
     write("你要向哪边跳？？\n");
     return 1; 
    }
   mlvl = (int)me->query_skill("move",1);
//   write(mlvl);
   if(mlvl < 200)
    {
      message_vision("$N纵身向东面山谷里跳了过去，呼呼....\n不好！！！\n", me);
      me->set("sen",(int)me->query("sen")/2);
      me->set("eff_sen",(int)me->query("eff_sen")/2);
      me->set("kee",(int)me->query("kee")/2);
      me->set("eff_kee",(int)me->query("eff_kee")/2);
      me->set("gin",(int)me->query("gin")/2);
      me->set("eff_gin",(int)me->query("eff_gin")/2);
      me->start_busy(4);
      call_out("fliping1",4,me);
      me->stop_busy();
    }
   else{
      message_vision("$N纵身向东面跳了过去，你只觉得耳边风声忽忽作响。。。。\n\n", me);
      room = load_object(__DIR__"biding2");
      message_vision("你正好好跳到峭壁中间的一棵松树上，好险哪。。。\n", me);
      me->move(room);
   }
   return 1;
}
int fliping1(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"shangu");
        message_vision("$N顺着山谷摔了下来。\n", me);
        }
        return 1;
}