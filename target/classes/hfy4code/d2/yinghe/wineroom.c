 // Room: wineroom.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "�ƽ�"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "south":__DIR__"magicroom",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}     
