 inherit ROOM;
void create()
{
        set("short", "厨房");
        set("long", @LONG
厨房里的光线很暗，乍一进来除了灶台下跳动着的暗红的火苗，几乎什么也看
不见。这里虽然不大，但是锅碗瓢盆、油盐酱醋，倒很奇全。而且不脏不乱，十分
干净整齐。整个屋里飘动着浓郁的葱香和淡淡的炊烟。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"neitang",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
