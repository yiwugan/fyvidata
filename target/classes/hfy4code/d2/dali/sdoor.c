#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HBMAG "大理南门" NOR);
        set("long", @LONG
此间是大理国都大理城的南门，大理城实名阳苜咩城，南诏于初
建来，经历代而至当今的段氏的“大理国”，皆以此城为都。城墙由
石块和土垒成，高二丈五，厚达二丈。城下三两个盔甲鲜明的军士瞪
大了眼睛观察着来来往往的行人，偶尔盘问几个形迹可疑份子。

LONG
        );
        set("exits", ([ 
  "north" : __DIR__"sroad2",
  "south" : __DIR__"shanroad",
]));

//        set("objects", ([
//        __DIR__"npc/trader" : 3,
//                        
//  ]));
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-850);
        set("coor/z",80);
        setup();
        replace_program(ROOM);


}