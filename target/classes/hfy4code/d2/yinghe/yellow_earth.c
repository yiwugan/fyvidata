 // Room: yellow_earth.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "��ɫ����"); 
        set("long", @LONG
����һ���ƲӲӵ����£���������£���������ɫ����������һ�档
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
