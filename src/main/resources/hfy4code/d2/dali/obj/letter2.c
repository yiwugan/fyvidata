#include <armor.h>
inherit ITEM;
#include <ansi.h>

void diu()
{
 message_vision("$N����һ���������ܺ��Ѿ������ˣ���������������\n",this_player());
 this_player()->delete_temp("lettertime") ;
 destruct(this_object());
}

void create()
{
        string st11;
        string *order=({"�Ϲ�ʮһ��","�Ϲ�ʮ����","�Ϲ�ʮ����","����","������",
"�����","���ͽ","����","��ʵ����","Ī����","��������","���촸","���","����ī��",
"������","�鱦��","����","��ҩ���ϰ�","���ִ����","������","������","�˺�����","é������",
"����","����","�����"});
        set_name(("�ܺ�"), ({ "letter"}) );
        st11=order[random(26)];
        set("toname",st11);
        set("long", HIW"                "+ st11 + HIC"    ����\n"NOR); 
        set_weight(1000);
        set("value", 10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
//        setup();
        call_out("diu", 800, 1);  
}