// teapot.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("���", ({ "pen pot", "pot" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����������������������\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 10);
        }
        set("liquid", ([
                "name": "����Ȫˮ",
                "drunk_apply": 6,
                "remaining": 15,
                "type": "alcohol",
        ]) );
}
