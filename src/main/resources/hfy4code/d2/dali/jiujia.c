inherit ROOM;
void create()
{
        set("short", "ӭ���Ƽ�");
        set("long", @LONG
�����Ǵ������С�������ľƼҡ���������˶�Ҫ������Ʒ��һ�´������ɫ��ʳ��
��������İ����������Ρ�������Ʈ����������ζ���㲻����θ�ڴ󿪣�һ��������
��æ��æ����к��ſ��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"eroad1",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) ); 
        set("valid_startroom", 1);

        set("coor/x",-750);
        set("coor/y",-740);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}