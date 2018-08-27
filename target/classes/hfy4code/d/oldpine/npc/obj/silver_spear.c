#include <weapon.h>
#include <ansi.h>
inherit SPEAR; 
void create()
{
        set_name(HIW"银白色的长枪"NOR, ({ "silver spear" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把银光闪闪的长枪，份量大约有十来斤左右。\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入地下。\n");
        }
        ::init_spear(55);
}    
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_sen");
        victim->receive_damage("sen",dam/10,me);
        return HIW"长枪枪尖上发出一道白光，犹如闪电般击中$n，令$n抚心顿首不能动弹！\n" NOR;
}   