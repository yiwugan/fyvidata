inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ���ǵı����̡�������������Ŀ�İ����˸��ֱ���������
��Щ��������̫ƽ��ͣ�������������Ⲣ��ʮ�ֻ�һ�����Ųʶе�
�ϰ壬������һ�ֵ�΢Ц�к��Ź����Ŀ��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"eroad1",
]));
        set("objects", ([
        __DIR__"npc/bboss" : 1,
                        ]) );

        set("coor/x",-750);
        set("coor/y",-760);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}