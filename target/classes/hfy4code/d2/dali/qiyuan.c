#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大理棋院");
        set("long", @LONG
大理人酷爱围棋，当地又出产云子，一个精明的商人就在这里开了一
个大理棋院。有两个年轻伙计趁着没人正在下棋，掌柜的则在一边看着。
    棋苑共分四个大间，是手谈休栖的好地方。这里的南北和西三个方
向各有一间棋室，在每个棋室的门外都贴着请勿打扰棋局的
牌子，在房间中央的柱子上还贴着一张下棋指南(sign)。
LONG
        );
 set("item_desc", ([
    "sign" : @TEXT
                 欢迎到棋苑来下棋！

在这里您可以下围棋或五子棋，以下是下棋的步骤：
一、先找好对手，然后分别用  sit black  和  sit white  入座；
二、使用 new 开始一盘新的棋局：new [-5] [-b(numbers)] [-h(numbers)]
    其中 -5  代表下五子棋，不选即为下围棋；
      　 -b  指定所用棋盘的大小；
         -h  指定让子的数目；
　　例如：
　　围棋 new
    让九子围棋：new -h9
    十五乘十五的五子棋：new -5 -b15
三、使用 play 轮流走棋
    例如 play d4 等等。
四、使用 refresh 观看棋盘。
五、使用 leave 离开棋盘。
六、使用 pass 弃子认输。
七、使用 undo 悔棋。目前只提供五子棋的悔棋功能。
TEXT
    ]));
        set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"wroad1",
    "west"  :  __DIR__"qiyuan2",
    "south"  :  __DIR__"qiyuan3",
    "east"  :  __DIR__"qiyuan4",
]));
        set("objects", ([
        __DIR__"npc/fan2" : 1,
        __DIR__"npc/whiteman" : 1,
        __DIR__"npc/blackman" : 1,
//        __DIR__"obj/cch" : 1,
        __DIR__"npc/obj/table" : 1,
                        ]) );
//        set("outdoors", "dali");
        set("coor/x",-850);
        set("coor/y",-760);
        set("coor/z",80);
        setup();
}

void reset()
{
        object *inv;
        object con, item,item1,item2;
        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) ) {
        item = new(__DIR__"npc/obj/bqi");
        item1 = new(__DIR__"npc/obj/wqi");
        item2 = new(__DIR__"npc/obj/qipan");
        item->move(con);
        item1->move(con);
        item2->move(con);
        }
}


int valid_leave(object me, string dir)
{
 object room;
 mapping exit;

 exit = environment(me)->query("exits");

 if ( dir == "east" || dir == "south" || dir == "west" )
  {
   if( !( room = find_object(exit[dir])) ) room =load_object(exit[dir]);
   if( room->query_temp("action")  ==  1 )
    return notify_fail("那间棋室已经有人开始下棋了，请勿打扰\n");
  }
 return ::valid_leave(me, dir);
}