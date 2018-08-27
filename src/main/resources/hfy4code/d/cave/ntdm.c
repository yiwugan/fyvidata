 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "���춫��");
        set("long", @LONG
һ�˶�ߵ���Ģ��һ��Ƭ������ֲ��ı�Ƥ��Ӳ�������ر�
�Ĵֲڡ�����·�������Ǵ�Ģ���п������ģ�·����Ȼ������
���Կ�������·һ�����˺ܴ�Ĺ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ntdl",
  "south" : __DIR__"dnj",
]));
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-22);
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
        
        message_vision( HIM "·�����ˣ���Ģ��Ʈ���ŵ�����������ϡ�������\n\n"NOR,obj);
        if(!obj->query_condition("mag_mushroom") && random(obj->query_skill("perception",1))<50){
                obj->apply_condition("mag_mushroom",random(20)+10);
                message_vision(HIM"$N���ɵ�������һ������\n"NOR,obj);
        } else  message_vision( HIW"$N�����Ķ�����æ��ס������\n"NOR,obj);
        if(dir == "north" && !obj->query("vendetta/authority")){
                if (present("killer m", this_object()))
                {
                   another = present("killer m", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>7) {
                        another = new(__DIR__"npc/killer_m");
                        another->move(environment(obj));
                        message_vision(HIB"·�ߺ�Ӱһ��!\n"NOR, obj);   
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽�������ᣬ��������\n");
                }
        }       
        return 1;
} 
