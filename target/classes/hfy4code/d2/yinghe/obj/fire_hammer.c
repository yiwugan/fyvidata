 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
inherit __DIR__"yinghe_weapon";  
void create() {
        set_name(HIR"�һ�ӫ��"NOR, ({ "fire hammer", "hammer" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "�������������һ�ͼ�ƵĴ���\n");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
                set("attribute", "fire");
                set("yinghe_weapon", 1);
        }
        ::init_hammer(90);
}   
