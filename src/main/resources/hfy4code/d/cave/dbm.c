 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "������");
        set("long", @LONG
������ʵ��һ�����ұ��ϴ�����Ķ����������߾�����
����Ķ����ǡ����ߵ������ر�󣬺������졣������ң�
����û�а취֪�������Ǵ�ʲô�ط������ġ�
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
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_h");
                        another->move(environment(obj));
                   message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}   
