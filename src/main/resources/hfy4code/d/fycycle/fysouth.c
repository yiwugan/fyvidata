 inherit ROOM;
void create()
{
        set("short", "风云南");
        set("long", @LONG
这是风云城南边的市集。南北大道由此横贯。上穿白山黑水，直达松
花江。下接风云京都，再通江南海口。干线上商旅不绝。一条车痕向南方
和北方伸展。
LONG
        );
        set("exits", ([ 
  "north" : AREA_FY"sgate",
  "east"  : __DIR__"sroad4",
  "west"  : __DIR__"sroad3",
  "south" : AREA_FY"road0", 
]));
        set("objects", ([
        __DIR__"npc/xiaofan" : 1,
        "/d/fy/npc/wind_solider" : 1,
        ]) );
        
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-160);
        set("coor/z",0);
        
        setup();
}   
