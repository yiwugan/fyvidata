 // Copyright (C) 2002, by neon. All rights reserved by Fengyun Workshop.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        object con,item; 
        set("short", "��ʯ����");
        set("long", @LONG
������Ľ�ʯ�������£�û������ĺڰ��С�Խ�����ߣ�����������
Խ�̹ǡ���Ȼ�з��ڴ�������Ȼ�о���Χ�ĺڰ���������һ��������
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"stair2",
                "down" : __DIR__"riverbank",
        ]));
    set("indoors", "yinghe");
    set("objects", ([
                __DIR__"obj/stair" : 1,
    ]) );
        set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",-100);
        setup();
        con = present("��ʯ",this_object());
        
}  
int valid_leave(object np, string dir)
{
        np->start_busy(1);      
        tell_object(np, "����ñ������쬵ģ�������ʲô�����ڸ����㡣\n\n");
        return 1; 
}  
