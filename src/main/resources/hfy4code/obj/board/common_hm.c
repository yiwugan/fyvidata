 // common_b.c
inherit BULLETIN_BOARD; 
void create()
{
    set_name("废墟", ({ "board" }) );
        set("location", "/d/xinjiang/heimiao");
        set("board_id", "common_hm");
        set("long",     "再往前去，就是远离中原的他乡，许多旅客都会留下只字片言，缅怀故土。\n" );
        setup();
        set("capacity", 99);
        replace_program(BULLETIN_BOARD);
}     
