 // Room: rope_net.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "结绳大阵"); 
        set("long", @LONG
这是一块空地，目前什么都还没有修。
LONG);
        set("long_night", @LONG
这是一块空地，到了晚上就更不要指望看见什么。
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "south":__DIR__"trap",
        "northeast":__DIR__"flatfloor",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}     
