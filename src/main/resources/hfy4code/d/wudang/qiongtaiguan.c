 inherit ROOM;
void create()
{
        set("short", "琼台观");
        set("long", @LONG
琼台观又分为琼台上观、中观和下观。上观叫“白玉龟台”，中
观叫“紫岳琼台”，下观叫“玉乐霄台”。在道关不远的峭壁上有一
石洞，名曰：太玄洞。
LONG
        );
        set("exits", ([
                "north" : __DIR__"dishuiyan",
                "south" : __DIR__"wall",
        ]));
        set("objects", ([
                __DIR__"npc/taoist5" : 1,
                __DIR__"npc/taoist_2" : 1,
        ]));
        set("outdoors", "wudang");
        set("coor/x",110);
        set("coor/y",-150);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}     
