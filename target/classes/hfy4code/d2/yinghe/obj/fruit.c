#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(HIY"������"NOR, ({"golden fruit", "fruit"}) );
    set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ƵĹ��ӣ������˱ǡ�\n");
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
        tell_object(this_player(), HIY"������ڼ�����һ�ɳ����������֭�����㸹�У���ٸ�һ��ů�����
��������ȫ������\n"NOR);
        this_player()->set_temp("attribute_mark", "wood");
        "/cmds/imm/full" -> main(this_player(), "");
        destruct(this_object());
        return 1;
} 
