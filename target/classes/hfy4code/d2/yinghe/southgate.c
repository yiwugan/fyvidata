 // Room: southgate.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��������"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "south":__DIR__"pheonix_den",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}      
