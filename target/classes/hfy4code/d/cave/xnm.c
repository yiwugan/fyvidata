 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "������");
        set("long", @LONG
��·�õ�ʯͷ������ɢ�ҵضѷ��ţ�����һЩ��ɢ�Ĺ��ߡ�
���ϵĵط��и��󶴣�һ�����Ǹո��ٳ����ġ��ƺ����������
�������ﲻ������Ӵ����������š�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"txnd",
  "east" : __DIR__"zl",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
        set("coor/x",-37);
        set("coor/y",-24);
        set("coor/z",-20);
        setup(); 
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "east" && !obj->query("vendetta/authority")){
                if (present("killer p", this_object()))
                {
                        another = present("killer p", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_p");
                        another->move(environment(obj));
                   message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}      
