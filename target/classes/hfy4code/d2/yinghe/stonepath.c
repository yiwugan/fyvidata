 // Room: stonepath.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "���ʯ·"); 
        set("long", @LONG
�����·����������һ��Ũ��ҹɫ������������ǹ��ڽ�����ҫ��һ��
ѣ�δ�������ֻ���ú���̤���˱̺�����֮�ϡ�ϸϸһ���������羵�ĵ�
�澹�������ʯĥ�ɣ��ǹ����ӳ��һ����ϡ��Ӱ������������΢΢��Ц��
��������ɢ��ֱ�����Ĺǵı�����
LONG); 
        
        set("outdoors", "yinghe");
        set("exits",([
        "east":__DIR__"stonepath2",
        "northwest":__DIR__"bowroom",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}  
