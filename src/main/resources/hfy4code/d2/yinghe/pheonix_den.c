 // Room: pheonix_den.c --- by MapMaker
#include <ansi.h>
inherit ROOM;  
void create()
{
        set("short", "��ﳲ"); 
        set("long", @LONG
����һ������״��ʯ̨����Ե�������İ��ݡ�ʯ̨�����˺ܶ��ɫ����ë��
��ֻ����С������ú�����۹�����㡣
LONG);
        set("long_night", @LONG
����һ������״��ʯ̨����Ե�������İ��ݡ���ɫ�����������������һ��
������ů�����ա���ֻС����������������ë��ʯ̨�ϰ�˯��
LONG); 
        //{{ --- by MapMaker 
        set("exits",([
                "south":__DIR__"firetunnel3",
                "north":__DIR__"southgate",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/pheonix_bb1" : 1,
                __DIR__"npc/pheonix" : 1,
        ]));
        set("outdoors", "yinghe");
        setup();
} 
int valid_leave(object obj, string dir){
        object fh;
        
        fh = present("red pheonix", this_object());
        if((dir == "north" || dir == "south") && obj->query_temp("yinghe_marks/wake_pheonix")){
                if(objectp(fh)){
                        message_vision(HIY"\n$Nչ����ס$n��ȥ·��\n"NOR, fh, obj);
                        return notify_fail("");
                } else {
                        return 1;
                }
        }
        return 1;
}   
