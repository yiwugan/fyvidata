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
        set_name(HIR"�һ�ӫ��"NOR, ({ "fire axe", "axe" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "�������������һ�ͼ�Ƶĸ���\n");
                set("wield_msg", "$N��������$n��������������Ȼ���������С�\n");
        set("unwield_msg", "$N�������е�$n��\n");
                set("attribute", "fire");
                set("yinghe_weapon", 1);
        }
        ::init_axe(90);
}       
