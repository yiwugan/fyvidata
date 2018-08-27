 // dagger.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <weapon.h>
#include <ansi.h>
inherit DAGGER; 
void create() {
        set_name(HIY"红绸剑器"NOR, ({ "dagger" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把以红绸相系，可飞舞十尺的金色短剑。\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N从从腰间解下一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n缠於腰间。\n");
        }
        ::init_dagger(55);
}   

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        int pro;
        dam = (int) me->query_skill("dodge");
        victim->receive_damage("sen",dam/2,me);
        return HIY "$N握着"+name()+HIY"翩翩起舞，$n"+HIY"看得心神荡漾。。。\n" NOR;
}  
