//tenthousand-cash.c
#include <ansi.h>

inherit MONEY;

void create()
{
    set_name(HIR"һ��������Ʊ"NOR, ({"tenthousand-cash", "tenthousand-cash_money", "ttcash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("money_id", "million");
		set("long", "һ�����ֵһ�������ӵ���Ʊ��\n");
		set("unit", "��");
        set("base_value", 100000000);
		set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

