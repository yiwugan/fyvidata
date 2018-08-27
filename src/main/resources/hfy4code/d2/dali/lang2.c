#include <room.h>
inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
这里是寺内长长的一条走廊，前面是几间大屋，全以松木搭成，极
门木柱，木料均不去皮，天然质朴，却与前面一路行来的金碧辉煌的殿
堂截然不同。北面有一个小门，没有方丈的允许任何人不得擅入。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "north" : __DIR__"jingge",
    "east" : __DIR__"lang1",
]));        
        set("outdoors", "dali");
        set("coor/x",-980);
        set("coor/y",-820);
        set("coor/z",150);
        setup();
        create_door("north", "石门", "south", DOOR_CLOSED);
}