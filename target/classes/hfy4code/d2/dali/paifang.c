#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY "牌坊" NOR);
        set("long", @LONG
你来到了一座牌坊之前，牌坊上提着四个金笔大字「圣道广慈」。
夕阳照在黄瓦宫殿的琉璃瓦上，金碧辉煌，令人目为之炫。前面是一座
宫殿，宫门上写着「圣慈宫」三个大字。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__ "gnroad2",
  "west" : __DIR__ "yamen4",
]));
       set("objects", ([
       __DIR__"npc/weishi" : 2,
                       ]) );
        set("outdoors","dali");
        set("coor/x",-800);
        set("coor/y",-680);
        set("coor/z",80);
        setup();
//        replace_program(ROOM);
        
}

void init()
{
        add_action("do_open", "open");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "door" || arg == "宫门")
        {
        me = this_player();
        message_vision("$N把宫门打开。\n", me);
        if( !query("exits/north") ) 
        set("exits/north", __DIR__"shengcigong");
         }
        return 1;
}
int valid_leave(object me, string dir)
{
 object ob;
 string strr1="";

 if(wizardp(me)) return 1;

 if( !userp(me)) return 1;

 if( me->query("class") != "dali" && dir == "north" && ob=present("weishi", this_object()))
   return notify_fail(ob->name() + "把长剑一横喝道：大理皇宫重地，非大理族人不许进入！！\n");    

 if( me->query("class") == "dali" && (me->query("gongxian") < 5120) && dir == "north" && ob=present("weishi", this_object()))
   return notify_fail(ob->name() + "把把手一横说道：你的官衔不够，只有将军以上才能进大理皇宫。\n");    

 if( (me->query("class") == "dali") && (me->query("gongxian") > 5120) && dir == "north" && ob=present("weishi", this_object())) 
   {

   ob->ccommand(strr1);

   return 1;
  }
 return 1;
}
