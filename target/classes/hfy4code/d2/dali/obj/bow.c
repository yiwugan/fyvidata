inherit ITEM;

void create()
{
        set_name("家常饭碗", ({ "bow", "rice bow" }) );
        set("no_shown", 1);
        set("no_get",1);
        set_weight(500);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "in");
                set("long", "一个青花瓷碗，大理制造的一种常见器皿。\n");
                set("unit", "个");
                set("value", 100);
        }
}

int is_container() { return 1; }
