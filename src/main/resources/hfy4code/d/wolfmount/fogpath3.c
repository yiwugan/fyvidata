 inherit ROOM;
void create()
{
        set("short", "����ʯ��"); 
        set("long", @LONG
ɽ���������ƣ�С·���Ѷ��ϣ�һ�ԴԲ�֪����С����ɽ����ҡҷ����ֵ����
ʱ�ڣ�бб��ʯ�����仨�ͷס�̤���仨����ɳɳ��֮���ڼž���ɽ�����ƺ�����
����������Ҳ�����˸���ľҶ�Ͱٻ��ķҷ���������Զɽ��䡣
LONG); 
        set("type","road");
        set("exits",([
        "southup":__DIR__"fogpath4",
        "northdown":__DIR__"fogpath2",
        ]) );
        set("objects", ([
                __DIR__"obj/dropflower" : 2,
       ]) );
        set("coor/x",-650);
        set("coor/y",-760);
        set("coor/z",70);
       set("outdoors", "wolfmount"); 
        setup();
        replace_program(ROOM);
}   