 // Room: thundercity.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "����ɽׯ"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "west":__DIR__"irongate4",
        "south":__DIR__"irongate",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}   
