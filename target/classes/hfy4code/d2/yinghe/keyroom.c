 // Room: keyroom.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��ˮ��"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
        "north":__DIR__"westgate",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}     
