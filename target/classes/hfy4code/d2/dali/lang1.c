inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
这里是寺内长长的一条走廊，两名小和尚侍立一旁。走廊一直向
西延伸，通向寺院深处。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "south" : __DIR__"zhuchi",
    "north" : __DIR__"banruo",
    "west" : __DIR__"lang2",
    "east" : __DIR__"liangong",
]));        
        set("objects", ([
                __DIR__"npc/monk5" : 2,
       ]) );
        set("outdoors", "dali");
        set("coor/x",-970);
        set("coor/y",-820);
        set("coor/z",150);
        setup();
}