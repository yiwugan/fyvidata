// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("郑州风云新闻", ({ "fynews_board" }) );
	set("location", "/d/wiz/hall");
        set("board_id", "fynews_b");
	set("long",
                "这是一个供管理人员发布新闻的留言板。\n" );
	setup();
	set("capacity", 88);
	replace_program(BULLETIN_BOARD);
}
