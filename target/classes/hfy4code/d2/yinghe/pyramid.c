 // Room: pyramid.c --- by MapMaker
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
        "west":__DIR__"cylinder",
        "southeast":__DIR__"slider",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}  
