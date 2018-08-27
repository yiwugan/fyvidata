 // Room: firetunnel.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "离火洞"); 
        set("long", @LONG
这是一个灼浪腾腾的山洞，洞壁透出暗暗的红色火光。一股股热浪袭来，
你似乎快被烤焦。更有无名的震响如雷鸣般传来，令人晕头晕脑，不辨方向。
东面似乎有阵阵微风吹来，给人一丝希望。
LONG); 
        set("indoors","yinghe");
        set("exits",([
        "east":__DIR__"dryroad3",
        "west":__DIR__"firetunnel2",
        "southwest":__DIR__"thunderstone",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}   
