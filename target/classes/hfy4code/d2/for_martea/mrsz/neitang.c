 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������ú�������ã���ׯ�˳Է��ò�֮�ء����ú��Ǻܴ󣬷�����������
��ľ������������һ���ò裬���ż��̵��ġ������ǳ�����������Ʈ�������㡣
�������ͨ����Ժ��һ�����ȡ�
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"zhengtang",   
        "west" : __DIR__"chufang",
        "north" : __DIR__"changlang3",  
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
