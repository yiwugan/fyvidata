 // msword.c
#include <weapon.h> 
inherit SWORD; 
void create()
{
        set_name("���ǽ�", ({ "7*sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѽ����������߿鱦ʯ�ı�����\n");
                set("value", 20000);
                set("real", 1);
                set("fake_7sword",1);
                set("material", "blacksteel");
                set("rigidity", 700);
                set("wield_msg", "$N��ج��Ƥ�����г��һ�����������$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���������ج��Ƥ���ʡ�\n");
        }
        ::init_sword(40);
}