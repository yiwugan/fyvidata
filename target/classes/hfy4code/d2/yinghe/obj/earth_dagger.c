 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(YEL"ڤ��ذ��"NOR, ({ "earth dagger", "dagger" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "��ɫ�ĵ���ɢ���ű��˵�ɱ����\n");
                set("wield_msg", "$N�ӻ�������һ�����λε�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���뻳�С�\n");
                set("yinghe_weapon", 1);
        }
        ::init_dagger(90);
}    
