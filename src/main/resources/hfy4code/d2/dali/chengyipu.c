inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ȳ�ʪ�����Դ����˶�ϲ������Щ�ÿ����õ�˿��������
������ϰ�����Ƴ��������£����������·��ÿ����ã����������·���
�ι̶��Ҳ��ѿ���

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"eroad2",
]));
        set("objects", ([
        __DIR__"npc/chengboss" : 1,
                        ]) );

        set("coor/x",-720);
        set("coor/y",-740);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}