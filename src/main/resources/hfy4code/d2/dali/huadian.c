inherit ROOM;

void create()
{
        set("short", "��٢�޻���");
        set("long", @LONG
һ���ݣ���Ŀ���ǲ軨��������Ŀ�������������֡����µĻ����������ԡ�
�����д��Ÿ�ʽ��װ������������Ů����˵ꡣ���ò����ḡ����վ�ڽ������
��������
LONG
        );
        set("exits", ([
                "west" : __DIR__"sroad2",
        ]));
        set("objects", ([
                __DIR__"npc/fan3": 1,
        ]) );
        set("outdoors", "dali");
        set("coor/x",-790);
        set("coor/y",-830);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}