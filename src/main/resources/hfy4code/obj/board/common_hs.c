 // common_b.c
inherit BULLETIN_BOARD; 
void create()
{
    set_name("�����", ({ "board" }) );
        set("location", AREA_HUANGSHAN"lingtang");
        set("board_id", "common_hs");
        set("long",     "����Ϊ�������������԰塣\n" );
        setup();
        set("capacity", 99);
        replace_program(BULLETIN_BOARD);
}     
