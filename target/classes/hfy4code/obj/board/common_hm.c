 // common_b.c
inherit BULLETIN_BOARD; 
void create()
{
    set_name("����", ({ "board" }) );
        set("location", "/d/xinjiang/heimiao");
        set("board_id", "common_hm");
        set("long",     "����ǰȥ������Զ����ԭ�����磬����ÿͶ�������ֻ��Ƭ�ԣ��廳������\n" );
        setup();
        set("capacity", 99);
        replace_program(BULLETIN_BOARD);
}     
