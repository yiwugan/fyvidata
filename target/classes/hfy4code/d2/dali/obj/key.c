#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("Կ��", ({ "key","Կ��" }) );
    set_weight(1);
    set("no_shown", 1);
//        set("prep","in");
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "steel");
            set("long", "һ�����ص�Կ�ס�\n");
          }
    
}