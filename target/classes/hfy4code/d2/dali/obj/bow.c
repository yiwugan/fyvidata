inherit ITEM;

void create()
{
        set_name("�ҳ�����", ({ "bow", "rice bow" }) );
        set("no_shown", 1);
        set("no_get",1);
        set_weight(500);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "in");
                set("long", "һ���໨���룬���������һ�ֳ�������\n");
                set("unit", "��");
                set("value", 100);
        }
}

int is_container() { return 1; }
