 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������������������ĳ��ȣ����滭��һЩ�����Ĺ��ʻ�������Ѿ
�ߡ��Ҷ�������ȥ����æ���Լ������顣�����Ȱ�Χ�ŵ���һ���ľ����µĻ�԰��
���˵Ļ������˷θ������ȶ���������������¥�������³��ȱ��Ǻ�԰�ˡ�
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"changlang4",
        "south" : __DIR__"neitang",
        "west" : __DIR__"changlang2",
        "north" : __DIR__"houhuayuan2",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
