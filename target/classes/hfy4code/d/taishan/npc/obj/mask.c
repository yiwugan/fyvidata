#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(BLK"黄金面具"NOR, ({ "black mask","mask" }) );
        set_weight(1000);
        set("long","一个制作精美的黑色面具，戴上它，永远不会有人知道你是谁，除非你死了。\n");
        set("unit", "个");
        set("value", 10000);
        set("material", "cloth");
        set("armor_type", "mask");
        set("fakegender", "男性");
        set("armor_prop/id", ({"tiansun"}));
        set("armor_prop/name", ({"天孙"}));
        set("armor_prop/short", ({WHT"天宗 "NOR+HIY"天孙"NOR+"(tiansun)"}) );
}
