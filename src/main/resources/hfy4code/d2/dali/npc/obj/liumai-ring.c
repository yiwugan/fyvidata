//liumai-ring
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIG "������ָ" NOR, ({ "liumai-ring"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������˸�������â�Ľ�ָ��\n");
                set("unit", "��");
                set("value", 100000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 5);
                set("wear_msg", "$N����ذ�һ��$n������ָ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n����ָ�ϳ���������\n");


        }
      
}