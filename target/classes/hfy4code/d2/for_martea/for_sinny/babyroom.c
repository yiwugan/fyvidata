 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"���Ʊ�����"NOR);
        set("long", @LONG
�ô��һ�����ӡ���ǰ��һƬ�ݵأ���һЩС�����ڵ�����ˣ��
���ӵ��ſ�վ��һ������������ţ�����Ц�ǺǵĿ����ź����ǡ���
��������һ�Ŵ����ӣ��Ǻ����ǳԷ��ĵط��������кܶ�С���䣬��
��Щ���Ƶ�δ����Ϻ�ǵ������ˡ��ݵ�һ�ǻ��м���ҡ������С����
��˯�ġ�ǽ�������ֻ���д�ż����ѿ��Ĵ��֣� 
                        �� �� �� �� �� �� �� �� ��
                                        
                                                
                                                ���κ� && �Ϲ�ʮһ ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south":__DIR__"clothroom",
]));
        set("objects", ([
        __DIR__"npc/popo" : 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",20);
        set("coor/y",-15);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
