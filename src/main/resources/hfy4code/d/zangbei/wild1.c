 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽ��");
        set("long", @LONG
����ɽ����´��ɽ��������羰���������������Ķ���ɽ�����ɸ󡣾�˵ɽ
�ﻹס��һ���ˣ�����˰�������ס�ĵط�������������һƬ���ǡ��ڲ�ͬ�ļ���
�У��������в�ͬ�Ļ�ʢ����������ס�ڻ�������ʢ���Ǹ��ط���
LONG
        );
        set("exits", ([ 
                "east" : AREA_EREN"yuzhu",
                "west" : __DIR__"wild2",
//�����ϲ���·��
//                "north": __DIR__"erlang",
            //    "south": __DIR__"mroom",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",-1030);
        set("coor/y",150);
        set("coor/z",0);
        setup();
        
}    
