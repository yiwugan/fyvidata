#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIM "御花园" NOR);
        set("long", @LONG
这里是大理皇宫的御花园，园内的茶花开得正艳。茶花是大理的
国花，而皇宫内的茶花更是名贵稀有，花匠养花之道天下手曲一指。
园中放着几盆新藕、甜瓜、枇杷、林擒等鲜果，椅上丢着几柄团扇，
看来皇帝临睡之前曾在这里乘凉。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"qulang2",
]));
        set("objects", ([
                __DIR__"npc/gongnv" : 2,
                __DIR__"npc/xtaijian" : 2,
       ]) );
        set("outdoors","dali");
        set("coor/x",-780);
        set("coor/y",-600);
        set("coor/z",80);
        setup();
}