inherit ROOM;
// #include <command.h>
#include <ansi.h>
void create()
{
        set("short", "峭壁");
        set("long", @LONG
到了这里就是移花宫范围之内了.凡是进入移花宫
范围之内的人都得服从移花宫的每一项规定.不然
后果就是"死".
LONG
        );
        set("outdoors", "yihua");
        set("exits", ([
                "northup"    : "d/yihua/juebi",
        ]));
        set("coor/x",-165);
	set("coor/y",165);
	set("coor/z",30);
        set("objects", ([
                __DIR__"npc/yingke" : 1,              
       ]) );
        setup();
}
void init()
{
   add_action("do_jump", "jump");
}

int do_jump(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "对面") 
    {
     write("你要向哪边跳？？");
     return 0; 
    }
   mlvl = (int)me->query_skill("move",1);
   if(mlvl < 180)
    {
      message_vision("$N纵身向东面跳了过去，呼呼....\n不好！！！没跳到！！！\n", me);
    me->unconcious();
      me->set("sen",(int)me->query("sen")/2);
      me->set("eff_sen",(int)me->query("eff_sen")/2);
      me->set("kee",(int)me->query("kee")/2);
      me->set("eff_kee",(int)me->query("eff_kee")/2);
      me->set("gin",(int)me->query("gin")/2);
      me->set("eff_gin",(int)me->query("eff_gin")/2);
      me->unconcious();
      me->start_busy(4);
      call_out("fliping",4,me);
      me->stop_busy();
    }
   else{
      message_vision("$N纵身向东面跳了过去，你只觉得耳边风声忽忽作响。。。。\n\n", me);
      room = load_object(__DIR__"feiyun");
      message_vision("你只刚好跳到对面峭壁的边上，好险哪。。。\n", me);
      me->move(room);
   }
   return 1;
}
int fliping(object me)
{
	if( !me->is_ghost()) {
        me->move("/d/shaolin/neiyuan");
        message_vision("$N顺着山谷摔了下来。\n", me);
        me->unconcious();
	}
        return 1;
}
