 // Room: thunderstone.c --- neon
inherit ROOM; 
void create()
{
        set("short", "�׻���"); 
        set("long", @LONG
һ�������Ի��ĺ�ɫ��ʯأ����ɽ������ʯ����ɫ�󽹺ڣ�����������顣
��ʯ�����ƺ��������Ľ�ɫ��â��Ȼ���ں�ɫʯ����ڸ��¿���������ʯ�绢�ᣬ
��Χ���ݽ��ݣ��紵�����ʣ�����������������仢�Ĵ�˵��
LONG);  
        set("outdoors", "yinghe");
        
        set("exits",([
                "west":__DIR__"stonepath2",
                "north":__DIR__"firetunnel2/exit",
                "northeast":__DIR__"firetunnel",
        ]) ); 
        setup();
}      
