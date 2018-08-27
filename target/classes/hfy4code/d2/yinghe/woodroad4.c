 // Room: woodroad4.c --- neon
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "楠木走廊"); 
        set("long", @LONG
这是一条长长的楠木走廊，它横架于沙草之上。长廊的木料透出金亮明橙的楠
木本色。长廊到这里就到了尽头，似乎有一条小路往西南方向延伸。
LONG);
        
        set("indoors", "yinghe");
        set("exits",([
        "north":__DIR__"woodroad3",
        "southwest":__DIR__"dryroad",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/tan_tianhu" : 1,
        ]));
        setup();
} 
int valid_leave(object me, string dir){
        object obj;
        
        obj = present("tan tianhu", this_object());
        if(dir == "southwest" && objectp(obj)){
                if(me->query("attribute_mark") == "fire" && me->query_temp("yinghe_marks/rest")){
                        return 1;
                }
                message_vision(HIY"$N对$n断喝一声：站住！你既已行至此，大哥恐已遭不测，你还是纳命来吧！\n\n"NOR, obj, me);
                obj->kill_ob(me);
                return notify_fail("");         
        }
        return 1;
}
