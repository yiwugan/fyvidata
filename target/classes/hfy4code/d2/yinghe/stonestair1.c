 // Room: stonestair1.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "����ʯ��"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "west":__DIR__"stonecave",
        "south":__DIR__"stonestair2",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}       
