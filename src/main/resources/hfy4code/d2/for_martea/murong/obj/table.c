 inherit ITEM;
void create()
{
    set_name("木桌", ({ "table" , "木桌"}) );
    set_weight(500);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
            set("prep", "on");
        set("unit", "个");
        set("long", "一个木桌，看起来相当结实。\n");
        set("value", 1);
    }
    ::init_item();
} 
int is_container() { return 1; }       
