// inn.c

inherit ROOM;

void create()
{
        set("short", "大理当铺");
        set("long", @LONG
这是大理城唯一的一家当铺，是鹰记商号的大理分号。老板小六子据说是卜鹰的
亲戚。大理城这些年来政通人和，百姓安居乐业，所以这里也红火异常。当铺挂有牌
（ｓｉｇｎ）一块，上面模糊的写着一些小字。
LONG
        );
        
        set("exits", ([
                "west"          : __DIR__"sroad1",
        ]) );
        set("item_desc", ([
                "sign": @TEXT
这里是大理当铺，目前我们提供的服务有：

pawn        典当货物。
value       估价货物。
sell        卖断货物。
redeem      赎回货物。

TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/liuzi" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-790);
        set("coor/y",-800);
        set("coor/z",80);
        setup();
}