 //
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( BLU "�����ռ�ǽ" NOR, ({ "wall" }) );
        set("location", AREA_FY"sgate");
        set("board_id", "sgate_b");
        set("long",     "һ�±��������Ϳѻ�ĳ�ǽ��\n" );
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
} 
