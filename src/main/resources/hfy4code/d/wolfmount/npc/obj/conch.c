#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIC"七"HIB"彩"HIG"海"HIY"螺"NOR,({ "conch shell","conch","shell" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "wood");
                set("long", "一个流光四溢，七彩斑斓的海螺，你可以吹吹（ＢＬＯＷ）看。\n");
        }
        ::init_item();
} 
void init()
{
        add_action("do_blow", "blow");
} 
int do_blow(string arg)
{
        if( arg != "conch" && arg != "shell" && arg != "conch shell" ) return 0;
        if ( this_player()->query("force") < 50 )
        {
                message_vision("$N内力不足，不能吹"+ this_object()->name() + "。\n" , this_player() );
                return 1;
        }
        else if ( this_player()->query("force_factor") < 40 )
        {
                message_vision("$N鼓起腮帮子，粗着脖子吹起"+ this_object()->name() + "，但什么声响也没有。\n" , this_player() );
                return 1;
        }
        else
        {
                message_vision("$N轻轻吹了下" + this_object()->name() + "，顿时“嘟嘟”作响。。\n", this_player() );
                this_player()->add("force",-40);
                this_player()->start_busy(3);
                environment(this_player())->conch_notify();
                return 1;
        }       
}
