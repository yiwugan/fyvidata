//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG "������" NOR, ({ "longsword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("long", "����һ�ѷ����ı����������Ͽ���һ�����͵�������\n");
                set("material", "steel");
                set("wield_msg", "һ�����������$N�������Ѿ�����һ��$n��\n");
                set("unwield_msg", "$N���е�$n������Ϣ���������ƽ��ʡ�\n");
        }
        ::init_sword(45);
        
}