 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������������������ĳ��ȣ����滭��һЩ�����Ĺ��ʻ�������Ѿ
�ߡ��Ҷ�������ȥ����æ���Լ������顣�����Ȱ�Χ�ŵ���һ���ľ����µĻ�԰��
���˵Ļ������˷θ��������򱱵ľ�ͷ��һ����ɽ�������Ǽ�¥�����Ϻ�����д
���Ի��á����֡�
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"wohutang",
        "west" : __DIR__"changlang3",
        "north" : __DIR__"changlang5",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
