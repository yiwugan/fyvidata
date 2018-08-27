// medicine.c

inherit ITEM;

void create()
{
        set_name("���ϰ�ҩ",({"baiyao"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ�����ϰ�ҩ�������ã�����壩������ ��\n");
            set("unit","��");
            set("value", 2000);
        }
}

void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
}

int apply_medicine()
{
        int value = 20;
        int diff;

        if(this_player()->is_fighting())
            return notify_fail("ս���в�����ҩ����\n");
        diff = this_player()->query("max_kee")-this_player()->query("eff_kee");
        if(!(diff))    return notify_fail("��û�����ˣ�\n");
        if(value > diff) value = diff;
            
        message_vision("$N�����ϰ�ҩ���� ��\n",this_player());
        this_player()->add("eff_kee",value);
        destruct(this_object());
        return 1;
}