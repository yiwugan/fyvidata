#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("������", ({ "biaoge xin","xin" }) );
    set_weight(1);
    set("no_shown", 1);
//    set("no_give", 1);
//    set("no_drop", 1);
//        set("prep","in");
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���ţ��ŷ���д�ţ�
             ���̱���      ����\n");
          }
    
}