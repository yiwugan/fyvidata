 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit WHIP;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIG"�����"NOR, ({ "wood whip", "whip" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "��֪�ú�����ɵıޣ�����΢΢͸����â��\n");
                set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
                set("attribute", "wood");       
                set("yinghe_weapon", 1);
        }
        ::init_whip(90);
} 
