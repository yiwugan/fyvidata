 // Room: snakehall.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "�߿�"); 
        set("long", @LONG
����·���һ���ֲ����߳���������£����������������������˸��ָ�����
�ߡ����ڵ���ʯ��ΪͿ�����߳����Һ�Ѿ���������������ɫ�����ֹŹֵ������
������������������������п�����ҡβ���������ŵ�������������ż�����Ӷ���
�������������ǵ����Ľ�Ц��
LONG); 
        set("indoors","yinghe");
        set("objects", ([
                __DIR__"npc/snake_c" : 2,
                __DIR__"npc/snake_k" : 2,
                __DIR__"npc/snake_b" : 1,
                __DIR__"npc/snake_r" : 1,
        ]));
        set("exits",([
                "enter" : __DIR__"pearlcurtain",
                "southwest":__DIR__"irongate4",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
