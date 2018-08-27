// teapot.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("喷壶", ({ "pen pot", "pot" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个铁喷壶，可以用来浇花。\n");
                set("unit", "个");
                set("value", 100);
                set("max_liquid", 10);
        }
        set("liquid", ([
                "name": "蝴蝶泉水",
                "drunk_apply": 6,
                "remaining": 15,
                "type": "alcohol",
        ]) );
}
