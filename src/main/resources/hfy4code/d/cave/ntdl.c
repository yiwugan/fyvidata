 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "���춫·");
        set("long", @LONG
��Ȼ�ǵ��£������Ȼ����һЩ��ɫ���ԡ�·�߳���һ�ַ�
ľ�ǲݵ�ֲ������Ǿ޴��Ģ��������������ɫ�Ĺ�â������
һ���ر������ӵ�ֲ�Ҳ�ǻ���ɫ�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ztdd",
  "south" : __DIR__"ntdm",
]));
        set("coor/x",-30);
        set("coor/y",-20);
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
        
        if(dir == "south" && !obj->query("vendetta/authority")){
                if (present("killer l", this_object()))
                {
                        another = present("killer l", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_l");
                        another->move(environment(obj));
                        message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                   return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}     
