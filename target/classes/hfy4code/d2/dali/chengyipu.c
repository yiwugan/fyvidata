inherit ROOM;
void create()
{
        set("short", "成衣铺");
        set("long", @LONG
大理的天气酷热潮湿，所以大理人都喜欢穿着些好看耐用的丝绸轻衫，
这里的老板娘更善长补衣做衣，做出来的衣服好看耐用，补出来的衣服又
牢固而且不难看。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"eroad2",
]));
        set("objects", ([
        __DIR__"npc/chengboss" : 1,
                        ]) );

        set("coor/x",-720);
        set("coor/y",-740);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}