 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "北天东路");
        set("long", @LONG
石碑成群，有的破碎，有的躺倒，还有的被泥土淹没了一半。
由于地下潮湿，石碑都已经被青苔腐蚀了，上面刻的什么已经看
不清楚。一不小心就可能别石碑绊倒。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btdm",
  "south" : __DIR__"ztdd",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-10);
        set("coor/z",-20);
        setup();
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "north" && !obj->query("vendetta/authority")){
                if (present("killer j", this_object()))
                {
                        another = present("killer j", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_j");
                        another->move(environment(obj));
                   message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                        return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
        return 1;
}     
