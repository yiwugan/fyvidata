#include <armor.h>
inherit MASK; 
void create()
{
        set_name("�����ɴ", ({ "jiaoxiao" , "jiaoxiao miansha", "miansha"}) );
        set_weight(4);
        if(clonep()) 
            set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long", "һ��ӯ����ˮ������ݴ�Զ����������֯�����������������һ���ں����������Ρ�\n");
        set("material", "cloth");
        set("��ˮ", 1);
        set("value", 30000);
        set("armor_prop/long", ({"��������һ��������ˮ����ɴ��������������Ŀ��\n"}) );
        set("armor_prop/use_under_water", 1);
    }
    ::init_mask();
}         
