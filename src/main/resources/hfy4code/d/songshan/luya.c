 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "卢崖瀑布");
        set("long", @LONG
景色天成，大自然的妙手是任何能工巧匠难以企及的，瀑布不大
但是在绿树中透过的那一丝水光，那一抹彩虹却是让疲惫的游人休憩
的最好场所，略微有点高亢的水声激荡着人们的心，和北边的青童峰
遥相呼应，是嵩山最没有烟火气息的地方。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"zhongyue", 
  "north" : __DIR__"qingtong",
]));
        set("objects", ([
                __DIR__"npc/wuhua" : 1,
       ]) );
        set("outdoors", "songshan");
        set("coor/x",-180);
        set("coor/y",120);
        set("coor/z",0);
        setup();
        create_door("south", "小木门", "north", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "north" && ob=present("tian feng 14 lang", this_object()))
                if(!me->query_temp("marks/okey_to_see"))
                {
                ob->do_test(me);
                return notify_fail("");
                }
                return 1;
}     
