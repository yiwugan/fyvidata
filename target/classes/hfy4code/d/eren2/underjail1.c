#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "地牢");
        set("long", @LONG
这是一个深深的地洞，洞壁潮湿而又光滑。你脚边是三具已经腐烂
的尸体发出刺鼻的气味，旁边似乎还有几只大黑鼠，正在黑暗中窥视着
你，仿佛在等着将你作为下一顿美餐。向上望去，一块大铁板盖住了唯
一的出口，铁板上有一个三寸见方的小孔，投下几丝昏暗的灯光。
LONG);
        set("indoors", "eren2");
        set("no_magic",1);
        set("item_desc", ([
                "铁板": "一块四五百斤重的铁板，从下面是不可能推开的，还是想法另找出路吧。\n",
                "tieban": "一块四五百斤重的铁板，从下面是不可能推开的，还是想法另找出路吧。\n",
        ]) );
        set("objects", ([
                __DIR__"npc/rat1" : 1,
                __DIR__"obj/drug_flower" : 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{       
        add_action("do_climb", "climb");
}  
int do_climb(string arg)
{
    object obj, me;
    int kar;
    
    if(!arg || arg=="") return notify_fail("你要往哪里爬？\n");
    me = this_player();
    if( arg == "wall" || arg == "洞壁" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("你的动作还没有完成，不能移动。\n");
        message_vision(YEL"$N使出吃奶的力量，顺着洞壁向上爬去。\n"NOR, me);
        message_vision(YEL"$N爬到洞口推了推铁板，铁板纹丝不动，看来除非是有人从上面打
开，只能另找出路了。\n"NOR,me);
        me->start_busy(1);
        return 1;
    }
    return notify_fail("你不可以爬"+arg+"！\n");
}             
