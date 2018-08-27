 inherit ROOM;
void create()
{
        set("short", "庭院");
        set("long", @LONG
这是一个长方形的小庭院，一道石壁把这里与外界隔开。青砖铺成的地上飘落
着几片树叶，当中是三个大鱼缸，几尾金鱼在里面悠然自得。院子的东西个有两个
小月门，南面是正堂。
LONG
        ); 
    set("exits", ([ /* sizeof() == 4 */
                "east" : __DIR__"menkou",
        ]) ); 
        set("indoors","murong");
        setup();
        replace_program(ROOM);
}       
