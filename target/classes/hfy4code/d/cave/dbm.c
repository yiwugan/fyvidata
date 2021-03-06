 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "东北门");
        set("long", @LONG
这里其实是一个从岩壁上打出来的洞，再往东边就是天
外天的东北角。耳边的阴风特别大，呼呼作响。风向很乱，
根本没有办法知道到底是从什么地方吹来的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tdbd",
  "east" : __DIR__"dbj",
]));
        set("indoors", "cave");
        set("coor/x",-35);
        set("coor/y",0);
        set("coor/z",-20);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        setup();
} 
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "west" && !obj->query("vendetta/authority")){
                if (present("killer h", this_object()))
                {
                        another = present("killer h", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_h");
                        another->move(environment(obj));
                   message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                        return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
        return 1;
}   
