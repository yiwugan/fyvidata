#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(HIY"金黄异果"NOR, ({"golden fruit", "fruit"}) );
    set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个金黄的果子，异香扑鼻。\n");
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
        tell_object(this_player(), HIY"果子入口即化，一股充满异香的蜜汁流入你腹中，你顿感一股暖洋洋的
气流又走全身经脉。\n"NOR);
        this_player()->set_temp("attribute_mark", "wood");
        "/cmds/imm/full" -> main(this_player(), "");
        destruct(this_object());
        return 1;
} 
