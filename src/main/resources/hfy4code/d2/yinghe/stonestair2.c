 // Room: stonestair2.c --- by MapMaker
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
        set("type","street");
        set("exits",([
        "south":__DIR__"dragon_den",
        "north":__DIR__"stonestair1",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}      
