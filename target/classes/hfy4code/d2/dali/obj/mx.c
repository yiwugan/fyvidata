inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("过桥米线", ({ "gqmx", "mx" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗有名的大理小吃。\n");
                set("unit", "碗");
                set("value", 5000);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        
}
int finish_eat()
{
        set_name("雕花大碗", ({"wan"}));
        set("value",200);
        set("long", "一只蓝底儿雕花的景泰蓝大碗，上面刻着“大理”字样。\n");
        return 1;
}