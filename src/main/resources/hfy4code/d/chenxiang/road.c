 inherit ROOM;
void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的荒野地，山势到了这里突然间变的叠叠起起，连绵不断
再往北行则是去大沙漠的荒凉小路，往西北方向远远眺望则是五岳之一的华山
界内，陡峭的山峦直插云霄，巍峨壮丽。
LONG
        );
    set("exits", ([ 
        "north" : __DIR__"roadp",
                "southup" : __DIR__"chenxiang3",
        "northwest" : AREA_HUASHAN"road1",
        "northeast" : "/d2/shanxi/road",
        ]));
        set("outdoors", "chenxiang"); 
        set("coor/x",-510);
        set("coor/y",-430);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}    
