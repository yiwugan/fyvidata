 inherit ROOM;
void create()
{
        set("short", "Ľ��ɽׯ");
        set("long", @LONG
��Դ��һ�ǲ�֪��ʱ������һ��ׯ԰��������������϶���һ������ѩͤ����
�����豭��С��ͭ���������⡣��ǰ��������ֻ�߹��˵ľ�ëʯʨ���Ŷ��Ҷ�д��
��Ľ��ɽׯ���ĸ����֡�ǽ����Լ�ɼ�����¥�߸󣬻���������һ����֪������ͨ
�����˼ң��ɴ�ʱ��ǰȴ�������壬���Ž��գ����ܾ����ĵġ�
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
//      "south" : __DIR__"road3",
        "north" : __DIR__"dayuan",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}
