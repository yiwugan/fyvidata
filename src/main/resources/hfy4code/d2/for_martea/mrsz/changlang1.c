 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������������������ĳ��ȣ����滭��һЩ�����Ĺ��ʻ�������Ѿ
�ߡ��Ҷ�������ȥ����æ���Լ������顣�����Ȱ�Χ�ŵ���һ���ľ����µĻ�԰��
���˵Ļ������˷θ��������򱱵ľ�ͷ��һ����ͤ�������³��ȱ��Ǻ�԰�ˡ�
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"houhuayuan2",
        "south" : __DIR__"changlang2",
        "north" : __DIR__"liangting",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}      
