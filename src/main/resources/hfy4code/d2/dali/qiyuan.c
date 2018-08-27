#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������Ժ");
        set("long", @LONG
�����˿ᰮΧ�壬�����ֳ������ӣ�һ�����������˾������￪��һ
��������Ժ�������������Ƴ���û���������壬�ƹ������һ�߿��š�
    ��Է�����ĸ���䣬����̸���ܵĺõط���������ϱ�����������
�����һ�����ң���ÿ�����ҵ����ⶼ�������������ֵ�
���ӣ��ڷ�������������ϻ�����һ������ָ��(sign)��
LONG
        );
 set("item_desc", ([
    "sign" : @TEXT
                 ��ӭ����Է�����壡

��������������Χ��������壬����������Ĳ��裺
һ�����Һö��֣�Ȼ��ֱ���  sit black  ��  sit white  ������
����ʹ�� new ��ʼһ���µ���֣�new [-5] [-b(numbers)] [-h(numbers)]
    ���� -5  �����������壬��ѡ��Ϊ��Χ�壻
      �� -b  ָ���������̵Ĵ�С��
         -h  ָ�����ӵ���Ŀ��
�������磺
����Χ�� new
    �þ���Χ�壺new -h9
    ʮ���ʮ��������壺new -5 -b15
����ʹ�� play ��������
    ���� play d4 �ȵȡ�
�ġ�ʹ�� refresh �ۿ����̡�
�塢ʹ�� leave �뿪���̡�
����ʹ�� pass �������䡣
�ߡ�ʹ�� undo ���塣Ŀǰֻ�ṩ������Ļ��幦�ܡ�
TEXT
    ]));
        set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"wroad1",
    "west"  :  __DIR__"qiyuan2",
    "south"  :  __DIR__"qiyuan3",
    "east"  :  __DIR__"qiyuan4",
]));
        set("objects", ([
        __DIR__"npc/fan2" : 1,
        __DIR__"npc/whiteman" : 1,
        __DIR__"npc/blackman" : 1,
//        __DIR__"obj/cch" : 1,
        __DIR__"npc/obj/table" : 1,
                        ]) );
//        set("outdoors", "dali");
        set("coor/x",-850);
        set("coor/y",-760);
        set("coor/z",80);
        setup();
}

void reset()
{
        object *inv;
        object con, item,item1,item2;
        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) ) {
        item = new(__DIR__"npc/obj/bqi");
        item1 = new(__DIR__"npc/obj/wqi");
        item2 = new(__DIR__"npc/obj/qipan");
        item->move(con);
        item1->move(con);
        item2->move(con);
        }
}


int valid_leave(object me, string dir)
{
 object room;
 mapping exit;

 exit = environment(me)->query("exits");

 if ( dir == "east" || dir == "south" || dir == "west" )
  {
   if( !( room = find_object(exit[dir])) ) room =load_object(exit[dir]);
   if( room->query_temp("action")  ==  1 )
    return notify_fail("�Ǽ������Ѿ����˿�ʼ�����ˣ��������\n");
  }
 return ::valid_leave(me, dir);
}