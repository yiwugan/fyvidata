 // Room: stonepath2.c --- neon
inherit ROOM; 
void create()
{
        set("short", "ܽ��ʯ��"); 
        set("long", @LONG
һ���ֵ���Ȼȫ����һ����ĥ�þ�Ө��͸��ܽ��ʯ�̳ɡ�
ܽ��ʯ�ʽ��ϸ�ۣ������ӯ�������紦�ӵ�Ƥ������������
�������㡣
LONG); 
        set("outdoors", "yinghe");
        
        set("exits",([
        "east":__DIR__"thunderstone",
        "west":__DIR__"stonepath",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}
