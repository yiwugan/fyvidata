 // armor.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <armor.h>
inherit ARMOR; 
void create() {
        set_name("Ƥ��", ({ "armor", "leather armor" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "leather");
                set("value", 10);
                set("armor_prop/armor", 3);
                set("long","һ����ɵ�Ƥ�ף����滹�м���Ѫ����\n");
        }
        ::init_armor();
}    
