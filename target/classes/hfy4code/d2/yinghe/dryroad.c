 // Room: dryroad.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "黄沙路"); 
        set("long", @LONG
这是一条蜿蜒的黄沙小径。它向西通往一座险峻的山岭，东北方向是一条长长的
木廊。每当风起，这里往往黄沙满天，寸步难行。
LONG);
        
        set("outdoors", "yinghe");
        set("exits",([
        "westup":__DIR__"windmoutain",
        "northeast":__DIR__"woodroad4",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
