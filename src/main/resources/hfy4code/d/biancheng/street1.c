 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "北街");
        set("long", @LONG
一条南北向的小街横贯在小镇的东侧，不长，仅数百尺。小街的一端，是无边
无际的荒原；小街的另一端，也是无边无际的荒原。走在街上，四周满是戒备的眼
光，边远的小镇，没有官府，没有豪门，人与人的一切恩怨，唯一解决途径便是出
鞘的刀和身上的血。        
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"silkshop",
        "north": __DIR__"street2",
        "south": __DIR__"road2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
