inherit ROOM;
void create()
{
        set("short", "善人渡");
        set("long",@LONG 
澜沧江的一个渡口，江上横着一座铁索桥。但见桥下江水荡荡，
激起无数泡沫，如快马奔腾般从脚底飞过。
LONG
        );
        set("exits", ([
                "east" : __DIR__"shangu",
           ])); 
        set("no_magic",1);
        set("coor/x",-750);
        set("coor/y",-900);
        set("coor/z",90);
        setup();
}