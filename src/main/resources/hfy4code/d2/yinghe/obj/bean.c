 inherit ITEM;
void create(){
        string *order=({"�춹", "�̶�", "�ƶ�", "�ڶ�", "����", "�Ӷ�"});
        set_name(order[random(6)], ({"bean", "dou zi" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һЩ���ӡ�\n");
                set("unit", "Щ");
                set("value", 10);
        }
    ::init_item();
}
