 //
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( BLU "建议收集墙" NOR, ({ "wall" }) );
        set("location", AREA_FY"sgate");
        set("board_id", "sgate_b");
        set("long",     "一堵便於张贴和涂鸦的城墙。\n" );
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
} 
