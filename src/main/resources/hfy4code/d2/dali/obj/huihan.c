#include <armor.h>

inherit ITEM;
#include <ansi.h>
void create()
{
//        string *order=({"�Ϲ�ʮһ��","�Ϲ�ʮ����"});
        set_name(("�غ�"), ({ "huihan"}) );
        set("fromname",this_player()->query("name"));
        set_weight(100000);
        set("value", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
      
}

