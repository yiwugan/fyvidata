inherit ROOM;
void create()
{
        set("short", "杂货铺");
        set("long", @LONG
这里是大理城的杂货铺。专门经营一些人们日常用的生活用品，由于老板与人和善，
而且这里的东西便宜实惠，所以这里的生意一直还不错。靠墙的架子上摆著各种生活必
需用品，中间一张柜台，店主人正坐在柜台后面算帐。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"eroad2",
]));
        set("objects", ([
        __DIR__"npc/zhboss" : 1,
                        ]) );

        set("coor/x",-720);
        set("coor/y",-760);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}