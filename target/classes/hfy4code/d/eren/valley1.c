 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "山村口");
        set("long", @LONG
过了石碑，道路转为平坦，传说中凶神恶煞云集的“恶人谷”原来竟是个普普
通通的山村模样，一栋栋房屋，一片片草坪，在阳光的照耀下，显得那么安静、平
和。路旁有个茶摊，一个满脸慈祥的老妇人坐在树荫下，正在招呼着过往的人。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"road5",
     //   "east" : __DIR__"vroad1",
        "northeast" : __DIR__"groad1",
        ]));
        set("objects", ([
                __DIR__"npc/teawoman": 1,
                
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1240);
        set("coor/y",2020);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}    
