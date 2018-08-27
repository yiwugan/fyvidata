inherit ROOM;

void create()
{
        set("short", "精舍");
        set("long", @LONG
精舍不大，布置得非常精致。靠墙放着个大书架，上面摆满了各种佛经，一张书
桌上铺着一幅仕女图，一位俊美青年男子坐在桌前，嘴里还嘀咕着什么。
LONG
        );
        set("exits", ([
                "eastup" : __DIR__"huayuan",
        ]));
        set("no_magic",1);
        set("NONPC",1);
        set("objects", ([
                __DIR__"npc/duanyu": 1,
        ]) );
        set("coor/x",-990);
        set("coor/y",-800);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}