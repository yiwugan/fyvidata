 //
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( RED "Ͷ�����ǽ" NOR, ({ "wall" }) );
        set("location", AREA_FY"egate");
        set("board_id", "egate_b");
        set("long",     "һ�±��������Ϳѻ�ĳ�ǽ��\n" );
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
} 
