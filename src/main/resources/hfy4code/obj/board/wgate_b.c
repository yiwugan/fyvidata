 //
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( HIY "�ʰ񹫸�ǽ" NOR, ({ "wall" }) );
        set("location", AREA_FY"wgate");
        set("board_id", "wgate_b");
        set("long",     "һ�±��������Ϳѻ�ĳ�ǽ��\n" );
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
} 
