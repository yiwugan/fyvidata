 // Room: rope_net.c --- by MapMaker
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
        "south":__DIR__"trap",
        "northeast":__DIR__"flatfloor",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}     
