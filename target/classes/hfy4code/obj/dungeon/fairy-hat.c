 // silencer
#include <armor.h>
#include <ansi.h> 
inherit HEAD; 
void create()
{
        set_name(HIG"������ñ"NOR, ({ "wizard hat","hat"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/personality", -10);
                set("armor_prop/dodge",100);
                set("armor_prop/spells",100);
                set("wear_msg", "$N����ذ�$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
                set("no_drop",1);
        }
        ::init_head(20);
}  
int query_autoload() { return 1; }     
