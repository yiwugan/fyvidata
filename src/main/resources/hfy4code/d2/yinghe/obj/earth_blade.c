 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(YEL"ڤ�鵶"NOR, ({ "earth blade", "blade" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "��ɫ�ĵ���ɢ���ű��˵�ɱ����\n");
                set("wield_msg", "$N���һ�����λε�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
                set("yinghe_weapon", 1);
        }
        ::init_blade(90);
} 
