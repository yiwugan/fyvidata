 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("青石", ({ "青石" , "rock","stone"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "数块精致的雕花楼梯，青石下镂空光滑。\n");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }      
