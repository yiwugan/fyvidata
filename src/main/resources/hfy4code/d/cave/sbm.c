 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "������");
        set("long", @LONG
һ��ʯ���ţ����泤������̦���������֡����ŵ��ұ�
��һ������ʯ��������̼��д��һЩ��ֵķ��š��Ų�����
�ߣ���΢��һЩ������Ҫ�����ſ���ͨ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"tsbd",
  "west" : __DIR__"sbj",
]));
        set("objects", ([
     __DIR__"obj/stone": 1,
                        ]) );
        set("indoors", "cave");
        set("coor/x",-55);
        set("coor/y",-0);
        set("coor/z",-20);
        setup();
} 
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "west" && !obj->query("vendetta/authority")){
                if (present("killer d", this_object()))
                {
                        another = present("killer d", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>6) {
                        another = new(__DIR__"npc/killer_d");
                        another->move(environment(obj));
                        message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                   return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}
