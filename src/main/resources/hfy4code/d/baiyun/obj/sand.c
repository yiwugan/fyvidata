 inherit ITEM;
void create()
{
    set_name("ɳ��", ({ "sand","shazi"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "Ƭ");
        set("long", "һƬ�ƲӲӵ�ɳ�ӡ����ƺ�����������������������裩��\n");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }       
