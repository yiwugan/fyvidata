 // Room: flatfloor.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "�Ի�̨"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "east":__DIR__"foodroom",
        "southwest":__DIR__"rope_net",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
