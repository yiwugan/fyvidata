#include <room.h>
inherit ROOM;
void create()
{
  set("short","����Ժ");
  set("long",@LONG
��ӵ������֮���Ϊ�������ɵľ������������Ǵ���ʼ�����
��������ҵĶ��Ǵ�����ϵĻ��塣
LONG
  );
  set("exits",([
         "north":__DIR__"lang1.c",
               ]));
          set("objects", ([
                __DIR__"npc/benyin" : 1, //�����·��� ����(Ben yin)
       ]) );
//  set("valid_startroom", 1);
//        set("outdoors", "dali");
        set("coor/x",-970);
        set("coor/y",-830);
        set("coor/z",150);
        setup();
}
