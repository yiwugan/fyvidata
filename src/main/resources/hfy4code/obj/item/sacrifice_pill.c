#include <ansi.h>
inherit ITEM;
void generate_name();
void create()
{
        set_name(HIR"����"NOR, ({"sacrifice pill" }));
        set_weight(1);
        set("unit", "��");
        set("long", "һ�����������Ƴɵ��W��ĵ�ҩ������ʩ[��ʶ��ͨ]ʱʹ��.\n");
        set("value", 100000);
        ::init_item();
}       
