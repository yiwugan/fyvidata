 // Room: firemountain2.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "�����"); 
        set("long", @LONG
����һ��յأ�Ŀǰʲô����û���ޡ�
LONG);
        set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "north":__DIR__"firecliff",
        "southeast":__DIR__"firemountain",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
