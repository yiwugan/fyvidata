inherit ROOM;
void create()
{
        set("short", "���˶�");
        set("long",@LONG 
���׽���һ���ɿڣ����Ϻ���һ�������š��������½�ˮ������
����������ĭ��������ڰ�ӽŵ׷ɹ���
LONG
        );
        set("exits", ([
                "east" : __DIR__"shangu",
           ])); 
        set("no_magic",1);
        set("coor/x",-750);
        set("coor/y",-900);
        set("coor/z",90);
        setup();
}