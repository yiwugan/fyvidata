 // Room: earthtemple.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��ɫ����̳");
        set("long", @LONG
����һ��������״����̳�Ķ�����������һ����ɫ�����أ�������һ����ʯӢ
��̨����̳����ֱ��԰ף��죬�ƣ�����ɫ�����������ɡ����̳����������ɫ��
�У��������£�һ�ֳ���ׯ��֮����Ȼ������
LONG);
//as earth people gets weapons first, they also
//face more puzzles to solve and npcs to fight
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
                "eastdown":__DIR__"black_earth",
                "westdown":__DIR__"yellow_earth",
                "southdown":__DIR__"red_earth",
                "northdown":__DIR__"white_earth",
        ]) );
        //}}
        set("item_desc", ([
                "������" : "��ɫ�������ƺ�����ת������������\n",
                "jade" : "��ɫ�������ƺ�����ת������������\n",
        ]));
        set("objects", ([
                __DIR__"obj/altar" : 1,
                __DIR__"obj/red" : 1,
                __DIR__"obj/black" : 1,
                __DIR__"obj/white" : 1,
                __DIR__"obj/yellow" :1,
        ]));
        setup();
        replace_program(ROOM);
}
