//mouse@wenxin
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "��" + HIG "��" + HIC "��" NOR, ({ "baihua sword", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ�����������â�ķ���������\n"
);
                set("value", 18000);
                set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N��������ɫ��ʯ����佣���г��һ���������˵�$n��\n");
                set("unwield_msg", "$N�����н�$n������У�$n����ƬƬ�ɻ�������佣���С�\n");
        }
        ::init_sword(80);
        }
