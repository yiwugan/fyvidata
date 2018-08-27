 // teapot.c
inherit ITEM;
inherit F_LIQUID; 
void create()
{
        set_name("茬子粥", ({ "cha zi zhou", "zhou" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗不知用什么做的粥，浓郁的香味引得你食欲倍增。\n");
                set("unit", "个");
                set("value", 30);
                set("max_liquid", 10);
        } 
        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "name": "茬子粥",
                "remaining": 10,
        ]) );
        ::init_item();
}       
