#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIG "С԰" NOR);
        set("long", @LONG
������������ǰ��һ��С԰���ʷ�軨ʢ���ļ��ڣ�԰�еĲ軨
���涷�ޣ����࿪�š�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"jiamingdian",
  "northup" : __DIR__"qinzhengdian",

]));
//        set("objects", ([
//                __DIR__"npc/master_20" : 1,
//       ]) );
        set("outdoors","dali");
        set("coor/x",-820);
        set("coor/y",-640);
        set("coor/z",80);
        setup();
}