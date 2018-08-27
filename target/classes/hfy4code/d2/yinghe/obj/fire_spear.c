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
        set_name(HIR"烈火荧枪"NOR, ({ "fire sword", "sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 1);
                set("material", "iron");
                set("long", "这是上面有着烈火图纹的枪。\n");
                set("wield_msg", "$N把$n紧紧地握在手中。\n");
                set("unequip_msg", "$N松开了手中的$n。\n");
                set("attribute", "fire");
                set("yinghe_weapon", 1);
        }
        ::init_spear(90);
}       
