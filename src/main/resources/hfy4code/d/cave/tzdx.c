 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "���е���");
        set("long", @LONG
�����Ǹ�����·�ڣ�����Ĳ��ֱ��ͨ������������ģ�
������Ϳ��Կ������ĵ�԰̳���ڰ����ʱ�򻹿��Կ����Ӷ�
��Բ��ֱ��������Բ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btxl",
  "south" : __DIR__"ntxl",
  "east" : __DIR__"zdxm",
]));
        set("indoors", "cave");
        set("coor/x",-60);
        set("coor/y",-30);
        set("coor/z",-20); 
        setup();
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "north" && !obj->query("vendetta/authority")){
                if (present("killer a", this_object()))
                {
                        another = present("killer a", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_a");
                        another->move(environment(obj));
                        message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
   }       
        return 1;
}     
