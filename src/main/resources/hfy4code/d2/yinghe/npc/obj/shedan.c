#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(HIC"��ˮ���ߵ�"NOR, ({"hanshui shedan", "shedan"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ˮ���ߵ������������亮�ޱȡ�����ޱȡ�\n");
                set("lore",1);
                set("unit", "��");
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
        tell_object(this_player(), HIW"�����һ�������ž�������һȦ��������ڵ����С�\n"NOR);
        this_player()->set_temp("attribute_mark", "water");
        destruct(this_object());
        return 1;
}      
