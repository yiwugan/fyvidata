 inherit ROOM;
void create()
{
        set("short", "��ɽ");
        set("long", @LONG
����һ����ʯ��᾵ļ�ɽ���������źܶ���СС�Ķ���ʯ����ɽ���кܶ��
����һ��΢�紵�����׶�Ѩ�������쬡��������������кܶ�׶������ϵĶ���ʯ
��������ʵʵ����֪���ǲ������˿�����Ƕ��ȥ�ġ���ɽ�������Ǹ�������������
ɽ����һ��¥�����Ϻ�����д���ܺ��������֡�
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"qihexuan",
        "south" : __DIR__"changlang5",
        "west" : __DIR__"chitang",
        "northwest" : __DIR__"houhuayuan1",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
