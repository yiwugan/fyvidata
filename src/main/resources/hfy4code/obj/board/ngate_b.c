 //
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( CYN "��������ǽ" NOR, ({ "wall" }) );
        set("location", AREA_FY"ngate");
        set("board_id", "ngate_b");
        set("long",     "һ�±��������Ϳѻ�ĳ�ǽ��\n" );
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
} 
