 // FYteam
#include <ansi.h>
inherit ROOM; 
string stone();
void create()
{
        set("short", "玄冰幽窟");
        set("long", @LONG 
这里是一个巨大的空穴。四周一片银白，玄冰垂挂，寒气入骨。不远处有泉水
流动的声音，呜呜噎噎，如泣如诉。洞穴中有一个环型的石盘，上边却没有冰霜凝
结。 停留时久，冷气砭身，更兼莫名的恐惧涌上心头。
LONG); 
        set("item_desc", ([
                "石盘" : (: stone :),
                "stone" : (: stone :),  
        ]));
        set("indoors", "yinghe");
        setup(); 
} 
string stone(){
        object me;
        me = this_player();
        if(query("broken")) {
                tell_object(me, "一个从中裂开的环型石盘。\n");
        } else {
                tell_object(me, "一个环形的石盘，有一石把手连接在上，似乎可以推动。（ｐｕｓｈ）\n");
                add_action("do_push", "push");
        }
        return "";
} 
int do_push(string arg){
        object me, room;
        
        me = this_player();
        if(query("borken")){
                return 0;
        }
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("你正在忙！\n");
        }
   if(arg == "stone" || arg == "石盘"){
                message_vision(HIC"\n石盘忽然裂开，寒冷的泉水喷涌而出，一阵激流把$N卷入水中。\n\n"NOR, me);
                set("broken", 1);
                room = find_object(__DIR__"well");
                if(!objectp(room)){
                        room = load_object(__DIR__"well");
                }
                me->move(room);
        } else {
                return notify_fail("你要推什么？\n");
        }               
        return 1;
} 
void reset(){
        ::reset();
        if(query("broken")){
                delete("broken");
        }
        return;
}   
