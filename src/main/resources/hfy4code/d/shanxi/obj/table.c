 inherit ITEM;
void create()
{
        set_name("石桌", ({ "table", "石桌", "桌","桌子","desk"}) );
        set_weight(5000);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("prep", "on");
            set("unit", "张");
            set("long", "一张用石头雕刻的桌子。\n");
            set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }      
