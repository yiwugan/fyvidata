 inherit ITEM;
void create()
{
    set_name("��ʯ̨", ({ "stone", "jade table","table", "ʯ̨" }) );
    set_weight(500);
    set_max_encumbrance(800000);
    set("no_get", 1);
    set("no_shown", 1);
        set("prep","on");
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("long", "һ����ʯ̨��\n");
            set("value", 1);
    }
        ::init_item();
} 
int is_container() { return 1; }   
