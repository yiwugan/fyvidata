 // Room: riverroad1.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "ӫ�ӹȵ�"); 
        set("long", @LONG
ת�����֣���ǰ��Ȼ������ͷ����ӫ�Ӿ�Ȼ��һ����ֽǶ���ȵص�һ������
�ڶ��������ϡ�������߶���ռ��ƺ����Ѿ��������������۹����۲졣��Զ
���ߵͣ���Ҳʧȥ���������жϡ���Ϊ�Ĵ�����ӫӫ�Ĺ�â�����������Լ�������
Χ�����嶼û��Ӱ�ӡ�û���˹�����ڰ��Ľ��ޣ�ֻ��һ��������ĸо���
LONG); 
        //{{ --- by MapMaker
        set("indoors", "yinghe");
        set("exits",([
        "south":__DIR__"mudpath",
        "northeast":__DIR__"fountain",
        "northwest":__DIR__"riverroad2",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}       
