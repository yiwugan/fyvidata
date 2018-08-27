 // Room: stonepath.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "青金石路"); 
        set("long", @LONG
这里的路面上流动着一层浓如夜色的深蓝，点点星光在脚下闪耀，一阵
眩晕传来，你只觉得好象踏在了碧海青天之上。细细一看，这光洁如镜的地
面竟似是青金石磨成，星光深处倒映着一个依稀镜影，正望定了你微微的笑，
空气中弥散着直沁入心骨的冰凉。
LONG); 
        
        set("outdoors", "yinghe");
        set("exits",([
        "east":__DIR__"stonepath2",
        "northwest":__DIR__"bowroom",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}  
