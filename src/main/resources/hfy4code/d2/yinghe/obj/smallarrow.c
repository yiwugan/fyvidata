#include <ansi.h>
#include <weapon.h>
inherit THROWING; 
void create()
{
        set_name("�����", ({ "small arrow", "arrow" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��С�ɵļ�ͷ���̶̵ļ�������Ƕ��һС����ʯ��\n");
                set("unit", "��");
                set("base_value", 1000);
                set("base_weight", 800);
        set("base_unit", "��");
        set("material", "metal");
    }
        set_amount(10);
        ::init_throwing(10);
}    
