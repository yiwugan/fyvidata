inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("��������", ({ "gqmx", "mx" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������Ĵ���С�ԡ�\n");
                set("unit", "��");
                set("value", 5000);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        
}
int finish_eat()
{
        set_name("�񻨴���", ({"wan"}));
        set("value",200);
        set("long", "һֻ���׶��񻨵ľ�̩�����룬������š�����������\n");
        return 1;
}