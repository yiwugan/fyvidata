 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("奠基石", ({ "奠基石" , "shitai","stone"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "斩蟒台的奠基石中间有个黑幽幽的空洞。\n");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }      
