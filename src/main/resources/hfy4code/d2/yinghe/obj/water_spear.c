 // Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIC"玄冰凝魄枪"NOR, ({ "ice spear", "spear" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "枪上透着阵阵寒气。\n");
                set("wield_msg", "$N握紧手中的$n。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
                set("attribute", "water");
                set("yinghe_weapon", 1);
        }
        ::init_spear(90);
}     
