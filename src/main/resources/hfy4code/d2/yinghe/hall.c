 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "风云天骄门");
        set("long", @LONG
这是一座古老而神圣的大理石门，大约建于百年前。门上斑斑点点，风化不
堪。传说中是玉皇大帝临凡佳奖天下儿女英雄的地方，凡是被佳奖的英雄都成为
不死之身。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"kezhan",
        ]));
        set("item_desc", ([
                "door" : "大理石门紧闭着，门上斑斑点点，风化不堪。不知道门后通向何处。（ｐｕｓｈ）\n",
                "大理石门" : "大理石门紧闭着，门上斑斑点点，风化不堪。不知道门后通向何处。（ｐｕｓｈ）\n",
                "门" : "大理石门紧闭着，门上斑斑点点，风化不堪。不知道门后通向何处。（ｐｕｓｈ）\n",
        ]));
    set("outdoors", "fycity");
    set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",0);
        setup();
} 
void init(){
        add_action("do_push", "push");
} 
int do_push(string arg){
        object me, room;
        me = this_player();
        if(arg == "door" || arg == "大理石门" || arg == "门"){
                if(query("exits/down")){
                        return notify_fail("大门是开着的。\n");
                }
                if(me->query("combat_exp") > 4000000 && me->query_str() > 45){
                        message_vision("$N运力与双臂，双掌紧贴大理石门，$N脚下的石阶忽然摇动起来，缓缓向两边裂开。\n", me);
                   message_vision(WHT"\n一阵阵冷风从下面吹来。\n"NOR, me);
                        room = find_object("/d/yinghe/stair1");
                        if(!objectp(room)){
                                room = load_object("/d/yinghe/stair1");
                        }
                        set("exits/down", "/d/yinghe/stair1");
                        call_out("close_path", 4);
                } else {
                        message_vision("大理石门纹丝不动。\n", me);
                        tell_object(me, "你也许经验或气力不够。\n");
                }
                return 1;
        }
        return 0;
} 
void close_path(){
    object room;
    if( query("exits/down") ) {
        message("vision","大门在你面前缓缓关闭。\n",this_object() );
        delete("exits/down");
        }
        return;
}      
