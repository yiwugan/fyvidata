 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��������");
        set("long", @LONG
�������ߣ����ڱ�ֱ�������޷�������һ������Ѻ���
�������������кܶ���ѷ죬���ǵ�����һ�εε�ˮ�飬��
����·Ū��ʪʪ�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"twt",
  "west" : __DIR__"sbm",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
        set("coor/x",-50);
        set("coor/y",-0);
        set("coor/z",-20);
        setup();
} 
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "east" && !obj->query("vendetta/authority")){
                if (present("killer e", this_object()))
                {
                        another = present("killer e", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>6) {
                        another = new(__DIR__"npc/killer_e");
                        another->move(environment(obj));
                   message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}       
