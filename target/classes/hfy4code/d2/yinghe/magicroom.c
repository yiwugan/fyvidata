 // Room: magicroom.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "����ʯ"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "east":__DIR__"monsterroom",
        "west":__DIR__"foodroom",
        "north":__DIR__"wineroom",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}  
