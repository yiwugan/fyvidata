 inherit ROOM;
void create()
{
        set("short", "��ͤ");
        set("long", @LONG
ɽׯ����ͤ�����Ϊ���£��м�һʯ�������Ͽ��ź�ʮ�ţ���ʮ�ŵ�һ�����̣�
�оֻ�δ��ȥ��������ȥ��������԰�ľ�ɫ�����۵ף������Ŀ���������ͤ�Ķ�
����Ǹ����磬��������¥�����Ϻ�����д�����¥�����֡�
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"chitang",
        "south" : __DIR__"changlang1",
        "west" : __DIR__"wufenglou",
        "northeast" : __DIR__"houhuayuan1",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}    
