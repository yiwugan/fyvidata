 inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是山庄里的后花园，空气中飘着一股鲜花的香味。这里虽然比不上富豪大
院里的万紫千红，但也布置得精致可人。园内有方池，缘池是座假山。廊边花木扶
疏，竹影参差。春天里桃花盛开，夏日池塘里荷花田田，秋天里菊花争艳，冬天则
是一片香雪海。园中见不到一根杂草，也许专门有人负责管理这里。
LONG
        );
        set("exits", ([ 
        "southeast" : __DIR__"jiashan",
        "south" : __DIR__"chitang",
        "southwest" : __DIR__"liangting",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
