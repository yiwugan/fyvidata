 inherit ROOM;
void create()
{
        set("short", "九曲黄河墙");
        set("long", @LONG
两条夹墙随山势起伏，迥转曲折。高大厚重，使来者走进山门马
上感到一种神秘威严和深邃遥远。传说玄帝幼时在此读书，寓人生修
读过程曲折艰辛。
LONG
        );
        set("exits", ([
                "north" : __DIR__"qiongtaiguan",
                "southup" : __DIR__"sansongting",
        ]));
        set("outdoors", "wudang");
        set("coor/x",110);
        set("coor/y",-160);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}      
