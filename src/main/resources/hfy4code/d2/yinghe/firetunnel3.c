 // Room: firetunnel3.c --- by mingyue
inherit ROOM; 
void create()
{
        set("short", "�޻�"); 
        set("long", @LONG
��һ�����˵������У��㱻��û��һƬ��ɫ�Ĺ����ʯ�ʵĵ����ƺ��ѽ���
�������ϼ�����϶�����������İ����â���������ϴ���Ľ���ӿ�ϡ�
LONG);
        set("long_night", @LONG
��һ�����˵������У��㱻��û��һƬ��ɫ�Ĺ����ʯ�ʵĵ����ƺ��ѽ���
�������ϼ�����϶�����������İ����â���������ϴ���Ľ���ӿ�ϡ�
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "south":__DIR__"firetunnel2/entry",
        "north":__DIR__"pheonix_den",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
