inherit ROOM;
void create()
{
        set("short", "兵器铺");
        set("long", @LONG
这里是大理城的兵器铺。铺子里琳琅满目的摆满了各种兵器，由于
近些年来世道太平祥和，所以这里的生意并不十分火，一个身着彩缎的
老板，正带着一种的微笑招呼着过往的客人。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"eroad1",
]));
        set("objects", ([
        __DIR__"npc/bboss" : 1,
                        ]) );

        set("coor/x",-750);
        set("coor/y",-760);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}