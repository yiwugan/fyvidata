#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("仙女图", ({ "xiannv-tu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张微微发黄的字画：
画的上面画着一位神情自若的美丽仙女．．\n");
          }
    
}