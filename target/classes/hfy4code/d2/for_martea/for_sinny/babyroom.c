 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"风云宝宝屋"NOR);
        set("long", @LONG
好大的一间屋子。门前有一片草地，有一些小宝宝在地上玩耍。
屋子的门口站着一个慈祥的老婆婆，正在笑呵呵的看护着孩子们。屋
子里面有一张大桌子，是孩子们吃饭的地方。两边有很多小单间，是
这些风云的未来大虾们的卧室了。屋的一角还有几个摇篮，是小孩子
们睡的。墙上有张字画，写着几个难看的大字： 
                        泥 娃 娃 制 做 培 养 中 心
                                        
                                                
                                                萧梦寒 && 上官十一 赠
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south":__DIR__"clothroom",
]));
        set("objects", ([
        __DIR__"npc/popo" : 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",20);
        set("coor/y",-15);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
