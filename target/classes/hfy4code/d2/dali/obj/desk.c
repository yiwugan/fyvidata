inherit ITEM;

void create()
{
        set_name("供桌", ({ "desk","供桌"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张供桌,上面有一个香炉。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }