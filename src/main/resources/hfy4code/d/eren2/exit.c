 // SILENCER@FY4 ALL RIGHTS RESERVED
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "洞口");
        set("long", @LONG
转过一块大石，面前忽然一亮，水柱便如倾盆大雨般劈头盖脸地打下，压得人
气都喘不过来。挣扎到洞口向外一看，这岩洞竟然是处在三叠瀑的中段，离地足有
十多丈高，下面是碧绿的潭水，洞外贴着石壁有一条小径向上通去。
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"exit3",
                "eastup" : __DIR__"oneway1",
                        ]));
        set("item_desc", ([
                "潭水": "潭水很深，也许跳下去能有机会。\n",
        ]) ); 
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_dive", "dive");
        add_action("do_dive", "jump");
        add_action("do_dive", "jumpdown");
        add_action("do_dive", "jumpto");
        add_action("do_dive", "charge");
        add_action("do_climb", "climb");
} 
int do_dive(string arg)
{
        object room;
        object me;
        me = this_player();
        call_out("jump_down",6,me);
        me->start_busy(3);
        message_vision(YEL"$N长长吸了口气，一闭眼，向瀑布下跳去。\n"NOR,me);
        tell_object(me,YEL"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n"NOR);
        tell_object(me,YEL"扑通一声，你一头扎进了潭水中。\n"NOR);
        return 1;
} 
int jump_down(object me)        {
        object room;
        if(!objectp(me)) return 1;
        if (me->is_ghost()) return 1;
        room=find_object(AREA_EREN"waterfall");
        if(!objectp(room)) 
                room = load_object(AREA_EREN"waterfall"); 
        me->move(room);
        message_vision(HIG"$N湿淋淋地从水里浮了起来爬上岸。\n"NOR,me);
        return 1;
}  
int do_climb(string arg)
{
        object obj;
        object me, room;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "山" || arg == "mountain" || arg == "down")
        {
                write("这个地方太险，大概爬不下去。\n");
                return 1;
        }
        else
        {
                write("你不可以这么爬。");
                return 1;
        }
}  
int valid_leave(object who, string dir){
        int i, room_full;
        object *inv, room;
   
        if (!userp(who))        return 1;
        if(dir == "eastup"){
                room=find_object(__DIR__"oneway1");
                if(!objectp(room)) 
                room = load_object(__DIR__"oneway1"); 
                inv = all_inventory(room);
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i])) room_full=1;
                }
                if (room_full) {
                        tell_object(who,"前方道路狭窄，只能容一人行走。\n");
                        return notify_fail("");
                }       
        }       
        return 1;
}       
