 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���춫·");
        set("long", @LONG
ʯ����Ⱥ���е����飬�е��ɵ������еı�������û��һ�롣
���ڵ��³�ʪ��ʯ�����Ѿ�����̦��ʴ�ˣ�����̵�ʲô�Ѿ���
�������һ��С�ľͿ��ܱ�ʯ������
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
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_j");
                        another->move(environment(obj));
                   message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}     
