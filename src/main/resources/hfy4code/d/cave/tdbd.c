 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "�춫����");
        set("long", @LONG
·��ʪ��ǽҲ��ʪ������û�л�ˮ�����������������
ˮ������������������������������İ��Ӻܶ�����ݺύ
��ˮ���ļ������������¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"twt",
  "east" : __DIR__"dbm",
]));
        set("indoors", "cave");
        set("coor/x",-40);
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
        
        if(dir == "east" && !obj->query("vendetta/authority")){
                if (present("killer g", this_object()))
                {
                        another = present("killer g", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>6) {
                        another = new(__DIR__"npc/killer_g");
                        another->move(environment(obj));
                   message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}      
