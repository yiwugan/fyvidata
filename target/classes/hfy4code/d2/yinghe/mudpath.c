 // Room: mudpath.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "冻土地"); 
        set("long", @LONG
这里依然在冰堡的寒气笼罩下。脚下时而是冻土，时而是泥浆。似乎这里是个
冰冻的沼泽，看来要格外小心才是。
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "south":__DIR__"icehall",
        "north":__DIR__"riverroad1",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
