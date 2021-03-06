// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("竹筒酒", ({ "zhutong", "tong" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个稍做加工的竹筒，用来装酒，可以保持酒味芳香。看上去大概装得八、九升的酒。\n");
                set("unit", "个");
                set("value", 2000);
                set("max_liquid", 15);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "alcohol",
                "name": "茶花酒",
                "remaining": 15,
                "drunk_apply": 6,
        ]) );
}