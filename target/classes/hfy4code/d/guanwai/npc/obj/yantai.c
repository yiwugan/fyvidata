 inherit ITEM;
void create()
{
        set_name("��̨", ({ "yan tai", "����̨", }) );
        set_weight(1300);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����ƴ�Сɫ����̣�����Ө�࣬�Աߵ�����������̨��\n");
                set("value", 10000);
                set("color", "��");
        }
        ::init_item();
}         
