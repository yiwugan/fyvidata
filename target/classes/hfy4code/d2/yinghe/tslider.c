 // Room: tslider.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "铁滑索"); 
        set("long", @LONG
这是一块空地，目前什么都还没有修。
LONG);
        set("long_night", @LONG
这是一块空地，到了晚上就更不要指望看见什么。
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "northwest":__DIR__"downcave",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
