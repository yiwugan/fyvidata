 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "天外天");
        set("long", @LONG
一个巨大的岩洞展现在眼前，岩洞的顶极其的高，几乎
一眼望不到顶。上面垂下来的钟乳石也有几丈长，如果不仔
细看，真的不敢相信这是在地下。在昏暗的灯光中，钟乳石
的影子晃来晃去，就象一棵棵小树。一阵阵的阴风不知道从
什么地方吹来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"td",
  "south" : __DIR__"qszl",
  "east"  : __DIR__"tdbd",
  "west"  : __DIR__"tsbd",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
        set("coor/x",-45);
        set("coor/y",-0);
        set("coor/z",-20);
        setup();
}   
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "east" && !obj->query("vendetta/authority")){
                if (present("killer f", this_object()))
                {
                        another = present("killer f", this_object());
                   return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>6) {
                        another = new(__DIR__"npc/killer_f");
                        another->move(environment(obj));
                        message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                        return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
        return 1;
} 
