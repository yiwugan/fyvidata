 // Room: woodroad4.c --- neon
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�ľ����"); 
        set("long", @LONG
����һ���������ľ���ȣ��������ɳ��֮�ϡ����ȵ�ľ��͸���������ȵ��
ľ��ɫ�����ȵ�����͵��˾�ͷ���ƺ���һ��С·�����Ϸ������졣
LONG);
        
        set("indoors", "yinghe");
        set("exits",([
        "north":__DIR__"woodroad3",
        "southwest":__DIR__"dryroad",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/tan_tianhu" : 1,
        ]));
        setup();
} 
int valid_leave(object me, string dir){
        object obj;
        
        obj = present("tan tianhu", this_object());
        if(dir == "southwest" && objectp(obj)){
                if(me->query("attribute_mark") == "fire" && me->query_temp("yinghe_marks/rest")){
                        return 1;
                }
                message_vision(HIY"$N��$n�Ϻ�һ����վס������������ˣ��������ⲻ�⣬�㻹���������ɣ�\n\n"NOR, obj, me);
                obj->kill_ob(me);
                return notify_fail("");         
        }
        return 1;
}
