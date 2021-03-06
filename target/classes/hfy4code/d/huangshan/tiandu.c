 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "天都峰");
        set("long", @LONG
天都是三大主峰中最为险峻的一座，古称“群仙所都”，意为天上都会。现在
路边已有依山凿就的石级和铁索围护的登山道，但是仍然令人有“难于上青天”之
感。途中有一石屏风，刻有“天上玉屏”四字，由此处先四周眺望，浮云怪峰，山
泉松海，尽收眼底。
LONG
        );
        set("exits", ([ 
                "southdown"  : __DIR__"jiyu",
                "westdown" : __DIR__"yixian",
        ]));
        set("objects", ([
                __DIR__"npc/hong" : 1,
                __DIR__"npc/lu" :1,
        ]) );
    set("cloud", 0);
    set("outdoors", "huangshan");
        set("coor/x",-560);
    set("coor/y",-470);
        set("coor/z",40);
        setup();
} 
void init(){
        int i, dayTime;
        mixed *local;
        i = NATURE_D->get_season();
        local = NATURE_D->get_current_time();
        dayTime = local[5];
        if((i = 1 || i = 2 || i = 3) && (dayTime > 660 && dayTime < 900) && NATURE_D->get_weather() == "晴"
                        && !query("cloud")) {
                remove_call_out("cloud");
                call_out("cloud", random(40));
        }
} 
void cloud(){
        object *inv, *players;
        int i;
        inv = all_inventory();
    players = filter_array(inv, (: interactive($1) :));
        message("vision", HIW"突然间白云象海潮一般涌来，转眼四周都是白茫茫的雾。\n"NOR, players);
        for(i=0; i<sizeof(players); i++) {
                if (!players[i]->query("宿命B/黄山_云海")) {
                    players[i]->set("宿命B/黄山_云海",1+random(10));
                }
        }   
        set("cloud", 1);
}     
