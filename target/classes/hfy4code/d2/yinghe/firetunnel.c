 // Room: firetunnel.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "���"); 
        set("long", @LONG
����һ���������ڵ�ɽ��������͸�������ĺ�ɫ��⡣һ�ɹ�����Ϯ����
���ƺ��챻���������������������������㴫����������ͷ���ԣ����淽��
�����ƺ�������΢�紵��������һ˿ϣ����
LONG); 
        set("indoors","yinghe");
        set("exits",([
        "east":__DIR__"dryroad3",
        "west":__DIR__"firetunnel2",
        "southwest":__DIR__"thunderstone",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}   
