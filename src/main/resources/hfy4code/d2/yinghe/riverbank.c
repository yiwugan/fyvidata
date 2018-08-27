 // Copyright (C) 2002, by neon. All rights reserved by Fengyun Workshop.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM; 
void create()
{
        object con,item; 
    set("short", HIC"ӫ��"NOR);
    set("long", @LONG
��Ѩ���������Ǿ�ͷ����Χ���ޱߵĿտ���ž���ǰ��ˮ�����ԣ����ǲ�֪��
���Զ�ĺ��档�ڰ�����ȥ�����ĵĺӵ�����ƺ���ӫ�⸡����
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"stair3",
        ]));
    set("indoors", "yinghe");
    set("item_desc", ([
        "river": "��ɫ��ˮ��ƽ���޲���ˮɫԽ��Խ�͸���İ�����ɫ�����ƺ�������ӫ�⸡����
���ƺ�����Ǳ��ȥ���������壩\n",
                "ӫ��" : "��ɫ��ˮ��ƽ���޲���ˮɫԽ��Խ�͸���İ�����ɫ�����ƺ�������ӫ�⸡����
���ƺ�����Ǳ��ȥ���������壩\n",
    ]));
    set("objects", ([
                __DIR__"obj/stair" : 1,
        __DIR__"npc/old_man" : 1,
    ]) );
        
    set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",-100);
        setup();
        
} 
void init(){
        add_action("do_dive", "dive");
} 
int do_dive(){
        object oldman, me, room;
   
        me = this_player();
        oldman = present("wu ming", this_object());
        if(objectp(oldman)){
                if(me->query_temp("marks/yinghe_prepared")){
                        message_vision("$N��$n����������б�������������ȥ��ʶһ����\n", oldman, me);
                        message_vision(HIB"$N����΢̧��һ��΢΢������������$nȫ��\n"NOR, oldman, me);
                        me->delete_temp("marks/yinghe_prepared");
                        message_vision("$N��ˮ��Ѹ�����³�ȥ��\n", me);
                        tell_object(me, "\n��Ȼ�����������ѹ�����ᣬ�����β��ɵü���������ȥ��\n\n");
                        room = find_object(__DIR__"center");
                        if(!objectp(room)){
                                room = load_object(__DIR__"center");
                        }
                        me->move(room);
                        return 1;
                } else {
                        message_vision("$N��$n��������һ��δ֪�����磬�㻹�ǲ�Ҫ�Ҵ�������׼���������ɡ�\n", oldman,me);
                }
        }
        message_vision("\n$N���λ�δ����ˮ�棬һ�ɷ�������$N������\n", me);
        return 1;
}       
