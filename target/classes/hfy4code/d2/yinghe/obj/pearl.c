#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(WHT"��������"NOR, ({ "pearl" , "��������", "dream pearl"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��ӫ�׵�ɫ���顣\n");
                set("value", 10000);
        }
    ::init_item();
}   
