 // Room: downcave.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "�ප"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "southeast":__DIR__"tslider",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}   
