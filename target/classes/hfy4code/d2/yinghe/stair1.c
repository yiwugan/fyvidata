 // Copyright (C) 2002, by neon. All rights reserved by Fengyun Workshop.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ʯ����");
        set("long", @LONG
һ���������ѵ�ʯ�׵�·��������Ľ�ʯ��ֹ�����������£�û��
�����ĺڰ��С�ʯ�ֲ�֪������ʲôʯ�����ɵģ�����ȥ�����������
�о���һ������������洵����
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"hall",
  "down" : __DIR__"stair2",
  ]));
        set("indoors", "yinghe");
        set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",-20);
        setup();
        replace_program(ROOM);
}      
