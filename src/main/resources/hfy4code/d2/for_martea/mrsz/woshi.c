 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���˯��ʮ�ֿ�����������ׯ������Ϣ�����ˡ�������Ĺ��ߺܰ���������
������һ�����˵�������һ�ſ������Ĵ������ű��죬���˲��������˯����ͷ
һ�����һ��Ů�ӵĻ������������ѹʵ�ׯ�������ˡ�
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"zhengtang",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}       
