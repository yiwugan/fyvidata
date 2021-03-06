 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "天东南道");
        set("long", @LONG
几辆小土车随便地放在路边，有的还装满了湿湿的泥土，似
乎要被运送到别的地方。还有一些不知道名字的工具都堆放在这
里，似乎全部是用来开山的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dnm",
  "east" : __DIR__"dnj",
]));
        set("objects", ([
        __DIR__"obj/dolly": 2,
                        ]) );
        set("indoors", "cave");
        set("coor/x",-32);
        set("coor/y",-24);
        set("coor/z",-20);
        setup(); 
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "west" && !obj->query("vendetta/authority")){
                if (present("killer n", this_object()))
                {
                        another = present("killer n", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_n");
                        another->move(environment(obj));
                        message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                   return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
        return 1;
}     
