#include <weapon.h>
#include <ansi.h> 
inherit SWORD; 
void create()
{
        set_name(HIW"����"NOR, ({ "die sword", "sword" }) );
        set_weight(3000);
        set("class","legend");
        set("experience",3500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
                set("material", "iron");
                set("weapon_prop/sword",20);
                set("long",
                          "һ��������񡢷�����ƥ�ı��������淢��ӨӨ�Ϲ⡣\n");
        }
        init_sword(70, SECONDARY);
}   
