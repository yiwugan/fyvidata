 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit AXE;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIG"叠翠斧"NOR, ({ "wood axe", "axe" }) );
        set_weight(60000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "不知用何物造成的斧，斧身微微透着绿芒。\n");
                set("wield_msg", "$N从腰间抽出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间。\n");
                set("attribute", "wood");
                set("yinghe_weapon", 1);
        }
        ::init_axe(90);
}    
