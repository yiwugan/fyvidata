// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��Ͳ��", ({ "zhutong", "tong" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ӹ�����Ͳ������װ�ƣ����Ա��־�ζ���㡣����ȥ���װ�ðˡ������ľơ�\n");
                set("unit", "��");
                set("value", 2000);
                set("max_liquid", 15);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "alcohol",
                "name": "�軨��",
                "remaining": 15,
                "drunk_apply": 6,
        ]) );
}