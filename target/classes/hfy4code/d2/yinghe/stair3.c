 // Copyright (C) 2002, by neon. All rights reserved by Fengyun Workshop.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        object con,item; 
        set("short", "玄石阶梯");
        set("long", @LONG
黑黝黝的阶石蜿蜒向下，没入沉沉的黑暗中。越往下走，吹来的阴风
越刺骨。虽然有风在吹，你仍然感觉周围的黑暗中凝结着一股死气。
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"stair2",
                "down" : __DIR__"riverbank",
        ]));
    set("indoors", "yinghe");
    set("objects", ([
                __DIR__"obj/stair" : 1,
    ]) );
        set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",-100);
        setup();
        con = present("阶石",this_object());
        
}  
int valid_leave(object np, string dir)
{
        np->start_busy(1);      
        tell_object(np, "你觉得背后冷飕飕的，好像有什么东西在跟着你。\n\n");
        return 1; 
}  
