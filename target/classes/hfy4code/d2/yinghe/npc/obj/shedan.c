#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(HIC"寒水蛇蛇胆"NOR, ({"hanshui shedan", "shedan"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个寒水蛇蛇胆，拿在手中其寒无比。珍贵无比。\n");
                set("lore",1);
                set("unit", "个");
                set("value", 50000);
                        set("food_remaining", 10);
                set("food_supply", 60);
        }
    ::init_item();
} 
void init(){
        if(environment() == this_player()){
                add_action("do_eat", "eat");
        }
} 
int do_eat(){
        ::do_eat();
        tell_object(this_player(), HIW"你觉得一阵寒气沿着经脉游走一圈，最后汇聚在丹田中。\n"NOR);
        this_player()->set_temp("attribute_mark", "water");
        destruct(this_object());
        return 1;
}      
