#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("��Ůͼ", ({ "xiannv-tu" }) );
    set_weight(1);
    set("no_shown", 1);
//        set("prep","in");
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ��΢΢���Ƶ��ֻ���
�������滭��һλ����������������Ů����\n");
          }
    
}