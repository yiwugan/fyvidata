inherit ITEM;

void create()
{
        set_name("����", ({ "desk","����"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ź���,������һ����¯��\n");
                set("value", 1);
        }
}

int is_container() { return 1; }