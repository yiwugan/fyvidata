inherit ROOM;
void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
�����Ǵ���ǵ��ӻ��̡�ר�ž�ӪһЩ�����ճ��õ�������Ʒ�������ϰ����˺��ƣ�
��������Ķ�������ʵ�ݣ��������������һֱ��������ǽ�ļ����ϰ������������
����Ʒ���м�һ�Ź�̨�������������ڹ�̨�������ʡ�

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"eroad2",
]));
        set("objects", ([
        __DIR__"npc/zhboss" : 1,
                        ]) );

        set("coor/x",-720);
        set("coor/y",-760);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}