// inn.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ǵ����Ψһ��һ�ҵ��̣���ӥ���̺ŵĴ���ֺš��ϰ�С���Ӿ�˵�ǲ�ӥ��
���ݡ��������Щ������ͨ�˺ͣ����հ�����ҵ����������Ҳ����쳣�����̹�����
������һ�飬����ģ����д��һЩС�֡�
LONG
        );
        
        set("exits", ([
                "west"          : __DIR__"sroad1",
        ]) );
        set("item_desc", ([
                "sign": @TEXT
�����Ǵ����̣�Ŀǰ�����ṩ�ķ����У�

pawn        �䵱���
value       ���ۻ��
sell        ���ϻ��
redeem      ��ػ��

TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/liuzi" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-790);
        set("coor/y",-800);
        set("coor/z",80);
        setup();
}