 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������������������ĳ��ȣ����滭��һЩ�����Ĺ��ʻ�������Ѿ
�ߡ��Ҷ�������ȥ����æ���Լ������顣�����Ȱ�Χ�ŵ���һ���ľ����µĻ�԰��
���˵Ļ������˷θ��������򱱵ľ�ͷ��һ����ͤ�������Ǽ�¥�����Ϻ�����д
�����������֡�
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"changlang3",
        "west" : __DIR__"panlongge",
        "north" : __DIR__"changlang1",
        ]) );
        
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}   
