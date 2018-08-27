 inherit ROOM;
void create()
{
        set("short", "泥土路");
        set("long", @LONG
路的左右两边都是一望无际的庄稼地。顺此路再往前走，就是武
当山。顺眼望去，武当山并不高，也不是很雄伟。但满山松树，绿油
油的不时露出几个黄色的屋顶。给人一种宁静的感觉。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"xzroad3",
                "south" : __DIR__"gate",
                "west" : __DIR__"farm1",
                "east" : __DIR__"farm2",
        ]));
        set("NONPC",1);
        set("outdoors", "wudang");
        set("coor/x",100);
        set("coor/y",-70);
        set("coor/z",0);
        setup();
replace_program(ROOM); 
}   
