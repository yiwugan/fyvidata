 // TIE @ FY3
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("南瓜", ({ "pumpkin" }) );
    set_weight(4000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一个圆圆的，硬邦邦的大南瓜\n");
        set("unit", "个");
        set("value", 15);
        set("food_remaining", 3);
        set("food_supply", 300);
    }
    ::init_item();
}
int digest(object me)
{
    if(objectp(me)) me->set_temp("can_pass_wall",1);
    return 1;
}
int do_eat(string arg)
{
    int foo;
    foo=::do_eat(arg);
    if (!foo) return 0;
    remove_call_out("digest");
    call_out("digest",random(20)+5,this_player());
    return 1;
}      
