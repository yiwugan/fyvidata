 inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
������ɽׯ��ĺ�԰��������Ʈ��һ���ʻ�����ζ��������Ȼ�Ȳ��ϸ�����
Ժ�������ǧ�죬��Ҳ���õþ��¿��ˡ�԰���з��أ�Ե��������ɽ���ȱ߻�ľ��
�裬��Ӱ�β�������һ�ʢ�������ճ�����ɻ����������ջ����ޣ�������
��һƬ��ѩ����԰�м�����һ���Ӳݣ�Ҳ��ר�����˸���������
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"changlang5",
        "south" : __DIR__"changlang3",
        "west" : __DIR__"changlang1",
        "north" : __DIR__"chitang",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}   
