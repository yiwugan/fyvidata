 // Room: mudpath.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "������"); 
        set("long", @LONG
������Ȼ�ڱ����ĺ��������¡�����ʱ���Ƕ�����ʱ�����ཬ���ƺ������Ǹ�
���������󣬿���Ҫ����С�Ĳ��ǡ�
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
