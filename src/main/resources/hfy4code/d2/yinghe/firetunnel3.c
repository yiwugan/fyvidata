 // Room: firetunnel3.c --- by mingyue
inherit ROOM; 
void create()
{
        set("short", "艮火洞"); 
        set("long", @LONG
在一股灼人的热浪中，你被淹没于一片红色的光晕里，石质的地面似乎已将熔
化，地上几条裂隙喷吐着狰狞的暗红光芒，热流不断从你的脚踝涌上。
LONG);
        set("long_night", @LONG
在一股灼人的热浪中，你被淹没于一片红色的光晕里，石质的地面似乎已将熔
化，地上几条裂隙喷吐着狰狞的暗红光芒，热流不断从你的脚踝涌上。
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "south":__DIR__"firetunnel2/entry",
        "north":__DIR__"pheonix_den",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
