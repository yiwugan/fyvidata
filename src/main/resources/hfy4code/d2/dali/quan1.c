inherit ROOM;

void create()
{
        set("short", "密林之中");
        set("long", @LONG
一片茂密的热带树林。树叶遮住了太阳，眼前朦朦胧胧的，看
不清方向，员处传来流水声。
LONG
        );
        set("exits", ([
                "north" : __DIR__"ting",
                "south" : __DIR__"quan2",
                "east" : __DIR__"quan1",
                "west" : __DIR__"quan3",
        ]));
      if(!random(4)) set("exits/west" , __DIR__"quan1");
        set("outdoors", "dali");
        set("coor/x",-620);
        set("coor/y",-780);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}