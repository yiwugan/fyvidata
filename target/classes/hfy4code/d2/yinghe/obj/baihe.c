 inherit ITEM;
inherit F_FOOD; 
void create(){
        set_name("百合", ({"lily", "lily root" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一些干百合。\n");
                set("unit", "些");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 6);
        }
    ::init_item();
}  
