inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("锦绣鱼丝", ({ "jxys", "ys" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘名厨烹调的上好大菜。\n");
                set("unit", "盘");
                set("value", 1500);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
       
}
int finish_eat()
{
        set_name("盘子", ({"panzi"}));
        set("value",200);
        set("long", "一只蓝底儿雕花的景泰蓝大盘子，上面刻着“大理”字样。\n");
        return 1;
}
