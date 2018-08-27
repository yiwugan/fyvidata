inherit ROOM;

void create()
{
        set("short", "曼佗罗花店");
        set("long", @LONG
一进屋，满目都是茶花，玲琅满目，不乏珍奇异种。清新的花香沁人心裨。
经常有穿着各式服装的少数民族少女出入此店。引得不少轻浮少年站在街上向店
内张望。
LONG
        );
        set("exits", ([
                "west" : __DIR__"sroad2",
        ]));
        set("objects", ([
                __DIR__"npc/fan3": 1,
        ]) );
        set("outdoors", "dali");
        set("coor/x",-790);
        set("coor/y",-830);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}