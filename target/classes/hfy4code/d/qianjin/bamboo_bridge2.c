 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����Ͻ���Ǿޱ��ľ�㡢��÷����ȸ�������������ɡ����ڡ�������֡�������
���桢�ٺϡ������ޡ������ޡ����ؽ�����֦ĵ�����࣬����ö�١�������֮ʱ����
���������Զ�����ߣ���ֲ������ݡ�һ��δл��һ���ֿ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"bamboo_bridge1",
  "southwest" : __DIR__"bamboo_bridge3",
]));
        set("outdoors","fengyun");
        set("coor/x",-50);
        set("coor/y",-40);
        set("coor/z",0);
        set("coor/x",-50);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
