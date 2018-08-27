 inherit ITEM;
void create()
{
        set_name("闪躲术简介", ({ "dodge book", "dodgebook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "一本介绍基本闪躲术的书。\n");
                set("value", 0);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_sell",1);
                set("material", "paper");
                set("skill", ([
                        "name": "dodge",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 120,
                ]) );
        }
}    
