 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIY"紫金枪"NOR, ({ "gold spear", "spear" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "墙上透出阵阵幽寒之气。\n");
                set("wield_msg", "$N握紧手中的$n。\n");
                set("unequip_msg", "$N放开手中的$n。\n");
                set("attribute", "gold");
                set("yinghe_weapon", 1);
        }
        ::init_spear(90);
}       
