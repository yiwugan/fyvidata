 // Room: yellow_earth.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "黄色土地"); 
        set("long", @LONG
这是一个黄灿灿的土坡，它延伸而下，构成了五色土金字塔的一面。
LONG);
        set("type","street");
        set("exits",([
        "eastup":__DIR__"earthtemple",
        "west":__DIR__"sandtower",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/yan_tieshan" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}       
