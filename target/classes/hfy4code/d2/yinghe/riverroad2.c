 // Room: riverroad2.c --- neon
inherit ROOM; 
void create()
{
        set("short", "�ӹ�"); 
        set("long", @LONG
һ�������ڹȵ������������Ӱ���ʱ������Ư���ĸ�������������ˮ����ײ��
�������������졣Զ��һ���ٲ���ɽ�ϴ��£���ˮ��������������¡¡�ĺ���
���������
LONG); 
        set("outdoors","yinghe");
        set("exits",([
        "west":__DIR__"waterpath",
        "southeast":__DIR__"riverroad1",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
