// medicine.c

inherit ITEM;

void create()
{
        set_name("������",({"dieda"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ�ŵ����裬 ���Գԣ����飩���������Ӿ��� ��\n");
            set("unit","��");
            set("value", 2000);
        }
}

void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","chi");
}

int apply_medicine()
{
        int value = 20;
        int diff;

        if(this_player()->is_fighting())
            return notify_fail("ս���в�����ҩ����\n");
        diff = this_player()->query("max_sen")-this_player()->query("eff_sen");
        if(!(diff))    return notify_fail("��û�����ˣ�\n");
        if(value > diff) value = diff;
            
        message_vision("$N����һ�ŵ����裮\n",this_player());
        this_player()->add("eff_sen",value);
        destruct(this_object());
        return 1;
}