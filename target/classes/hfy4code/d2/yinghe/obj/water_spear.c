 // Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIC"��������ǹ"NOR, ({ "ice spear", "spear" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "ǹ��͸����������\n");
                set("wield_msg", "$N�ս����е�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
                set("attribute", "water");
                set("yinghe_weapon", 1);
        }
        ::init_spear(90);
}     
