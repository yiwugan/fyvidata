 // Room: monsterroom.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "ڤ����"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "west":__DIR__"magicroom",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
