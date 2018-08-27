#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "地下暗道");
        set("long", @LONG
周围一片漆黑，冰冷的水足有半腰深，耳边阵阵阴风，吹得你毛骨悚
然。又好象有爬行动物的悉悉索索的声音，愈发的显得幽深恐怖。水流带
着你不知要通向何处。你的双手胡乱地摸索着，心中充满了恐惧，有个救
命稻草也好呀。你不禁懊恼身边为什么没带些照明的东西．．．
LONG
        );
        set("no_magic",1);
        set("coor/x",170);
        set("coor/y",-90);
        set("coor/z",-20);
        setup();
} 
void init()
{
        add_action("do_search", "search");
} 
int do_search(string arg)
{
        object me, room, book,frog; 
        me = this_player(); 
        switch (random(5)) {
                case 0:
                        tell_object(me,"你在黑暗中四处搜索，却什么都没有发现。\n");
                        break;
                case 1:
                        tell_object(me,RED "你在黑暗中四处搜索，突然你感觉到有什么东西在你后脖子上咬了一口。\n"NOR);
                        message_vision(YEL "$N在黑暗中发出一声惊叫。  啊....啊啊啊......\n"NOR, me);
                        me->receive_damage("kee",50);
                        break;
                case 2:
                        tell_object(me, RED"你一不小心滑到了深水里，只觉得一股很大的力量把你吸去。\n"NOR );
                        tell_object(me,YEL"你想叫但叫不出声......水从你的嘴里灌入。\n"NOR);
                        message("vision", "在黑暗中你听到扑通一声，只见"+me->name()+"的身影在旁边一闪就不见了。\n" , environment(me),me);
                        me->receive_damage("sen",30);
                   me->move(__DIR__"well");
                        message("vision",me->name() + "突然从水下钻了出来。\n", environment(me),me);
                        break;
                case 3:
                        if(!me->query("m_success/武当掌门的秘密")) { 
                                tell_object(me,"你在黑暗中毫无目的地四处摸索，突然你感觉到你似乎摸到了个圆的东西。\n");
                                tell_object(me,"你赶快捡起来揣到了怀里。\n", environment(me),me);
                                message("vision","在黑暗中你听到一阵悉悉索索的声音，"+me->name()+"似乎往怀里揣了些东西。\n", environment(me),me);
                                book = new(__DIR__"obj/head");
                                book->move(me);
                                me->set("m_success/武当掌门的秘密",1);
                                me->add("score",1000);
                        }
                        else {
                                tell_object(me,RED "你在黑暗中四处搜索，突然你感觉到有什么东西在你后脖子上咬了一口。\n"NOR);
                                message_vision(YEL "$N在黑暗中发出一声惊叫。  啊....啊啊啊......\n"NOR, me);
                                me->receive_damage("kee",50);
                        }
                        break;
                case 4:
                        if(!me->query_temp("well_frog")) { 
                                tell_object(me,"你在黑暗中毫无目的地四处摸索，突然你感觉到你似乎摸到了个滑腻腻的小动物。\n");
                                if (me->query("combat_exp")>4000000) {
                                        tell_object(me,"你赶快抓起来揣到了怀里。\n", environment(me),me);
                                        message("vision","在黑暗中你听到一阵悉悉索索的声音，"+me->name()+"似乎往怀里揣了些东西。\n", environment(me),me);
                                        frog = new(__DIR__"obj/frog");
                                        me->set_temp("well_frog",1);
                                        frog->move(me);
                                } else 
                                        tell_object(me,"你一个没抓紧，那个东西从手里跳了出去。\n");
                        }       
                        else {
                                tell_object(me,RED "你在黑暗中四处搜索，突然你感觉到有什么东西在你后脖子上咬了一口。\n"NOR);
                                message_vision(YEL "$N在黑暗中发出一声惊叫。  啊....啊啊啊......\n"NOR, me);
                                me->receive_damage("kee",50);
                        }
                        break;
                }
        return 1;
} 
void light_notify(object obj, int i)
{
        object *inv, me, room;
        int j;
        
        me = this_player();
        switch (i) { 
        case 0:
        message("vision","黑暗中传来咔咔几声打火摺子的声音。\n" , environment(me), me);
        tell_object(me, obj->name() + "似乎被水浸湿，打不着了。\n");
        break;
        case 1:
        message_vision(obj->name() + "发出的光照亮了地道。\n\n" , me);
        room = find_object(__DIR__"ltunnel");
        if(!objectp(room)) room=load_object(__DIR__"ltunnel");
        inv = all_inventory(this_object());
        for(j=0; j<sizeof(inv); j++) {
        inv[j]->move(room);
        }
        break;
        }
}   
