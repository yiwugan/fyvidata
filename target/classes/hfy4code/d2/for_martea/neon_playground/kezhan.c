 inherit ROOM;
void create()
{
        set("short", "���¿�ջ");
        set("long", @LONG
ɽ����һ��СС�Ŀ�ջ������ľ����ʣ�����ľ���š��ſ�������
�ı�Ƿ·���΢Ц���۾����������������Ƕ��Ǵ�����Ҵ��߹�������
�Ӽ��ſ��߹�����ƽ����
    Ҳ�����˼�����������˵����ջҲ�����һ���ɡ�
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([ 
        "north" : __DIR__"grassland",
        "west" : __DIR__"hall",
        ]));
        set("indoors", __DIR__"neon_playground");
        set("coor/x", 0);
        set("coor/y",30000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
