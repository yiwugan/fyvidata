 // Tie@fengyun
inherit ROOM;
void create()
{
        set("short", "阴暗石巷");
        set("long", @LONG
东云路往前几步，有一条阴暗的石巷，巷里散发着一种奇怪的霉腐味道。又夹
杂着一丝血腥，和干净宽敞的东云大路格格不入。又脏又臭的小河沟顺着巷侧缓缓
流淌，上面还漂着染满着黑血的绷带。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : AREA_FY"ecloud1",
  "north" : __DIR__"stone2",
]));
        set("objects", ([
        __DIR__"npc/scavenger" : 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",15);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
