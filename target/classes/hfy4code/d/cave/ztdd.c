 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "���е���");
        set("long", @LONG
�����Ǹ�ʮ��·�ڣ�����Ĳ����ǰ����ֱ��ͨ������������ģ�����ȴ��һ
�¸�ǽ��ס�ˡ����ǰ������������ɿ��Կ������ĵ�԰̳��������Բ��ֱ��������
����γɵ�Բ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"btdl",
                "south" : __DIR__"ntdl",
                "west" : __DIR__"zddm",
                "southeast" : __DIR__"ztddn",
        ]));
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-15);
        set("coor/z",-20);
        setup();
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "south" && !obj->query("vendetta/authority")){
                if (present("killer k", this_object()))
                {
                        another = present("killer k", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_k");
                        another->move(environment(obj));
                        message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
           }
        }       
        return 1;
}     
