 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��԰��һСС�ĳ������������ˮ�����峺�������м���ʢ����˯�����ۺ죬
��ף���ƣ������ű��̵�Ҷ�ӣ�Ư����С�����ϣ�ɷ������ϲ����͸��˯���ķ�
϶��Լ�ɼ���β��ɫ������ˮ�����еػ����ζ�������������ֱ�����ͤ����ɽ��
���������ĳ�����������������
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"jiashan",
        "south" : __DIR__"houhuayuan2",
        "west" : __DIR__"liangting",
        "north" : __DIR__"houhuayuan1",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
