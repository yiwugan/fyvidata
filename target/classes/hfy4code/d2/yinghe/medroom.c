 // Room: medroom.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "�յ�"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "south":__DIR__"weaponroom",
        "north":__DIR__"foodroom",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
