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
        set_name(YEL"ڤ���"NOR, ({ "earth whip", "whip" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "iron");
                set("long", "����ɢ���ű��˵�ɱ����\n");
                set("wield_msg", "$N$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
                set("yinghe_weapon", 1);
        }
        ::init_whip(90);
}    
