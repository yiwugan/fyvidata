 // Room: dryroad2.c --- by MapMaker
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
        set("type","indoors");
        set("exits",([
        "east":__DIR__"dryroad",
        "west":__DIR__"dryroad3",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
