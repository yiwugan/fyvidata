 // Room: dryroad3.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "���·"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "eastup":__DIR__"windmoutain",
        "north":__DIR__"dryroad6",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}   
