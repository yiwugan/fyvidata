 inherit ITEM;
void create()
{
        set_name("��÷�ķ�", ({ "book", "hanmei force", "hanmei" }));
        set_weight(600);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long",
                    "�鱾��ҳ���������ʹ�����һ��ѩ��ʢ���ĺ�÷��\n");
            set("value", 0);
            set("no_give", 1);
            set("no_drop", 1);
            set("no_sell",1);
            set("material", "paper");
            set("skill", ([
                    "name": "hanmei-force",
                    "exp_required": 5000,
                    "sen_cost": 65,
                    "difficulty": 40,
                    "max_skill": 60,
            ]) );
        }
}
