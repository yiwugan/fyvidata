 inherit ITEM;
void create()
{
    set_name("玉石台", ({ "stone", "jade table","table", "石台" }) );
    set_weight(500);
    set_max_encumbrance(800000);
    set("no_get", 1);
    set("no_shown", 1);
        set("prep","on");
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("long", "一个玉石台。\n");
            set("value", 1);
    }
        ::init_item();
} 
int is_container() { return 1; }   
