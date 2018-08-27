// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "天龙寺后殿");
        set("long", @LONG
这里是天龙寺众僧参禅之处，地上只摆着六个蒲团。两个老僧正在
诵经，有一个小和尚在旁边听着。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"dadian",
  "west" : __DIR__"huayuan",
  "south" : __DIR__"banruo",
]));
        set("objects", ([
                __DIR__"npc/benguan" : 1,  //天龙寺高僧 本观(Ben guan)
                __DIR__"npc/benxiang" : 1,  //天龙寺高僧 本相(Ben xiang)
                __DIR__"npc/monk2" : 1,
       ]) );
//        set("outdoors", "dali");
        set("coor/x",-970);
        set("coor/y",-800);
        set("coor/z",150);
        setup();
}