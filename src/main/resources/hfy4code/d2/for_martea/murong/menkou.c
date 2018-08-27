 inherit ROOM;
void create()
{
        set("short", "门洞");
        set("long", @LONG
站在此处向里看迎面是一石壁，向外则是碧绿的草坪。门洞内摆着一个长条木
凳旁边是一个小小的竹凳，西边是一间小门房，大约是看门人休息的地方。        
LONG
        ); 
    set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"murong",
                "west" : __DIR__"mroom",
                "northwest" : __DIR__"yard1",
                "northeast" : __DIR__"yard2",
        ]) ); 
        set("outdoors","murong"); 
        setup();
        replace_program(ROOM);
}    
