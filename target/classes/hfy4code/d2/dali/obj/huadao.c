//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW "�軨��" NOR, ({ "huadao" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50000);
                set("long", "����һ�ѷ����ı�������������Լ���Կ������軨��\n");
                set("material", "steel");
                set("wield_msg", "������ƬƬ�ɻ���$N�������Ѿ�����һ��$n��\n");
                set("unwield_msg", "һ���������$N��$n��������Ϣ�����뵶�ʡ�\n");
        }
        ::init_blade(45);
        
}