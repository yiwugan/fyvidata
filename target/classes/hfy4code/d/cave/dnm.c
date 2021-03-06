 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "东南门");
        set("long", @LONG
几垛刚刚烧好的砖坯堆放在这里，还有新鲜的沙石和泥土，
似乎正要进行一个大规模的工程。路边被凿了个大洞，直通下
面的地下河，洞上有个架子，上面有个木桶，似乎是用来吊水
的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zl",
  "east" : __DIR__"tdnd",
]));
        set("indoors", "cave");
        set("coor/x",-34);
        set("coor/y",-24);
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
                if (present("killer o", this_object()))
                {
                        another = present("killer o", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_o");
                   another->move(environment(obj));
                        message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                        return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
        return 1;
}
