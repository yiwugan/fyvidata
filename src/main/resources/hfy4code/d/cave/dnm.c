 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "������");
        set("long", @LONG
����ո��պõ�ש���ѷ�������������ʵ�ɳʯ��������
�ƺ���Ҫ����һ�����ģ�Ĺ��̡�·�߱����˸��󶴣�ֱͨ��
��ĵ��ºӣ������и����ӣ������и�ľͰ���ƺ���������ˮ
�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zl",
  "east" : __DIR__"tdnd",
]));
        set("indoors", "cave");
        set("coor/x",-34);
        set("coor/y",-24);
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
                if (present("killer o", this_object()))
                {
                        another = present("killer o", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_o");
                   another->move(environment(obj));
                        message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}
