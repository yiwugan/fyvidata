 // Room: dragon_den.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "������"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "south":__DIR__"slop",
        "north":__DIR__"stonestair2",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}       
