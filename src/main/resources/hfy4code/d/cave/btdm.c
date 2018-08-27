 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "北天东门");
        set("long", @LONG
这里的洞顶突然降低许多，就好象一个天然的屋顶。屋顶
被一排密密的钟乳石支撑着，形成一面墙。而墙的中间又有一
丈多宽的空隙，刚好让条石横着铺过。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dbj",
  "south" : __DIR__"btdl",
]));
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-5);
        set("coor/z",-20);
        setup(); 
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "south" && !obj->query("vendetta/authority")){
                if (present("killer i", this_object()))
                {
                        another = present("killer i", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_i");
                        another->move(environment(obj));
                        message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                        return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
   return 1;
}      
