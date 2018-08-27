inherit ITEM;

void create()
{
        set_name("ÏãÂ¯", ({ "xianglu","ÏãÂ¯"}) );
        set_weight(500);
        set_max_encumbrance(80000);
//        set("no_get", 1);
        set("no_shown", 1);
        set("prep","in");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("long", "Ò»¸öÏãÂ¯¡£\n");
                set("value", 1);
        }
}

int is_container() { return 1; }