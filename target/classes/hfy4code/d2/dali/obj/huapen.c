#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("精致花盆", ({ "huapen" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "wood");
                set("long", "一个非常精致的景泰蓝花盆，可以用来养花。\n");
                set("weapon_prop/karma",1);
        }
        ::init_hammer(5);
        
}
void init()
{
        if(environment(this_object())==this_player())
        if (!wizardp(this_player())) {
        set("no_get"," 还是不要乱动大理的东西为好! \n");
        set("no_drop","大理的东西怎么能随便乱丢呢! \n");
        set("no_give","大理的东西怎么能随便给人呢！\n");
       }
//      add_action("do_read","wa");
//      add_action("do_go","go");
}