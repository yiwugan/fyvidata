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
        set_name(YEL"ڤ�鴸"NOR, ({ "earth hammer", "hammer" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "��ɫ�Ĵ���ɢ���ű��˵�ɱ����\n");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
                set("yinghe_weapon", 1);
        }
        ::init_hammer(90);
}       
