 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "神水密藏处");
        set("long", @LONG
白水宫至宝－－神水存放之处，相传神水无色无味，既可抹于刀剑
也可以下入水中，中者立毙，头顶中裂，骨骼粉碎。因为此物毒绝天下，
有伤天理，所以即便白水弟子，也不能擅入此地，只有获得宫主特许，
才能取走数滴。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"guayu",
]));
        set("coor/x",-500);
        set("coor/y",-390);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
} 
