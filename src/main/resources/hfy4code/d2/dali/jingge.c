#include <room.h>
inherit ROOM;
void create()
{
  set("short","�ؾ���");
  set("long",@LONG
����ֻ���飬��ʽ�����ľ��飮����������һ���Ϻ������������š�
LONG
  );
  set("exits",([
         "south":__DIR__"lang2.c",
               ]));
          set("objects", ([
                __DIR__"npc/kurong" : 1, //�����³��� ���ٴ�ʦ(Ku rong)
       ]) );
        set("outdoors", "dali");
        set("coor/x",-980);
        set("coor/y",-810);
        set("coor/z",150);
        setup();
        create_door("south", "ʯ��", "north", DOOR_CLOSED);
}