#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HBMAG "大理东门" NOR);
        set("long", @LONG
阳苜咩城，或简称苜咩城，这是大理国的都城。自南朝初创，历
经陈氏“长大和国”、赵氏“大天兴国”、杨氏“大义宁国”诸代而
至当今的段氏的“大理国”，均以此城为都。此处乃是东城门，以梅
"溪为护河，城墙建在溪南，由石块和土垒成，高二丈五，厚达二丈，
门上有重楼，驻有了哨。青石官道从城里直向西延伸，另有一条黄土
大路向东通去。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"ting",
  "west" : __DIR__"eroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-700);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);


}