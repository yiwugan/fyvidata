 // Room: dryroad6.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "����ɽ"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "south":__DIR__"dryroad3",
        "north":__DIR__"firemountain",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
