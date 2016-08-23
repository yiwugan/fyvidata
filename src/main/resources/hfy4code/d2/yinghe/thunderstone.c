 // Room: thunderstone.c --- neon
inherit ROOM; 
void create()
{
        set("short", "雷击岩"); 
        set("long", @LONG
一块形似卧虎的黑色巨石兀立在山顶。岩石表面色泽焦黑，纹理龟裂破碎。
岩石中央似乎有隐隐的金色光芒，然而在黑色石块的遮盖下看不分明。石如虎踞，
周围长草焦枯，风吹而呜咽，不由让人想起李广射虎的传说。
LONG);  
        set("outdoors", "yinghe");
        
        set("exits",([
                "west":__DIR__"stonepath2",
                "north":__DIR__"firetunnel2/exit",
                "northeast":__DIR__"firetunnel",
        ]) ); 
        setup();
}      
