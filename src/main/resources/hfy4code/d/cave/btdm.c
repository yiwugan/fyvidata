 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "���춫��");
        set("long", @LONG
����Ķ���ͻȻ������࣬�ͺ���һ����Ȼ���ݶ����ݶ�
��һ�����ܵ�����ʯ֧���ţ��γ�һ��ǽ����ǽ���м�����һ
�ɶ��Ŀ�϶���պ�����ʯ�����̹���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dbj",
  "south" : __DIR__"btdl",
]));
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-5);
        set("coor/z",-20);
        setup(); 
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "south" && !obj->query("vendetta/authority")){
                if (present("killer i", this_object()))
                {
                        another = present("killer i", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_i");
                        another->move(environment(obj));
                        message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
   return 1;
}      
