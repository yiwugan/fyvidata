 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��������");
        set("long", @LONG
����ĵ��Ʊ������ǵͶ��ˣ�·���ϵ��ѷ��ж���һ����
Сˮ���ڼ������������š�ˮ�����������Ƶ���̦��ʹ����·
��ʪ���ޱȡ�һ��С�ľͻỬһ�ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sbj",
  "south" : __DIR__"btxl",
]));
        set("objects", ([
        __DIR__"obj/lichen": 1,
                        ]) );
        set("indoors", "cave");
        set("coor/x",-60);
        set("coor/y",-10);
        set("coor/z",-20);
        setup(); 
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "north" && !obj->query("vendetta/authority")){
                if (present("killer c", this_object()))
                {
                        another = present("killer c", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>6) {
                        another = new(__DIR__"npc/killer_c");
                        another->move(environment(obj));
                        message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                   return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
}      
