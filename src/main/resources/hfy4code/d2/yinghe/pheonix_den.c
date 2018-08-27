 // Room: pheonix_den.c --- by MapMaker
#include <ansi.h>
inherit ROOM;  
void create()
{
        set("short", "火凤巢"); 
        set("long", @LONG
这是一座火焰状的石台，边缘卷起，中心凹陷。石台中铺了很多红色的羽毛。
几只火红的小凤凰正用好奇的眼光打量你。
LONG);
        set("long_night", @LONG
这是一座火焰状的石台，边缘卷起，中心凹陷。红色火光明灭闪动，给人一种
宁静温暖的气氛。几只小火凤正在铺满厚厚羽毛的石台上安睡。
LONG); 
        //{{ --- by MapMaker 
        set("exits",([
                "south":__DIR__"firetunnel3",
                "north":__DIR__"southgate",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/pheonix_bb1" : 1,
                __DIR__"npc/pheonix" : 1,
        ]));
        set("outdoors", "yinghe");
        setup();
} 
int valid_leave(object obj, string dir){
        object fh;
        
        fh = present("red pheonix", this_object());
        if((dir == "north" || dir == "south") && obj->query_temp("yinghe_marks/wake_pheonix")){
                if(objectp(fh)){
                        message_vision(HIY"\n$N展翅拦住$n的去路。\n"NOR, fh, obj);
                        return notify_fail("");
                } else {
                        return 1;
                }
        }
        return 1;
}   
