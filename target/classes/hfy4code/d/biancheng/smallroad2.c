 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "小巷");
        set("long", @LONG
小巷不算很窄，刮风的时候灰砂满天，下雨的时候泥泞满路，左邻右舍都是贫苦
人家，流着鼻涕的小孩子整天在巷子里胡闹啼哭打架玩耍，鸡鸭猫狗拉的屎到处都有，
家家户户的门口都晒着小孩衣服和尿布。
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"smallroad1",
        "south" : __DIR__"smallroad3",
        "west"  : __DIR__"cabin2",
        ]));
        set("objects", ([
                __DIR__"npc/huwaigua":  1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1150);
        set("coor/y",160);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
