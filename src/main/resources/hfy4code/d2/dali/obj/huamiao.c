#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("�軨����", ({ "youmiao"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                
set("long","���ż�ƬҶ�ӵĻ��磬Ҳ������԰�����ֲ�������飩���𴦡�\n");
                set("unit", "��");
                set("base_unit", "��");
set("no_give",1);
set("no_drop",1);
                set("base_weight", 10000);
                set("base_value", 1);
        }
        set_amount(1);

        
}
void init()
{
  if(this_player()==environment())
  add_action("do_zhai","zhai");

}

int do_zhai()
{
        int i;        
        object tree1,me1;
        object con,*inv;
        object a1;

        me1 = this_player();
        if(query_amount() < 5)
        return notify_fail("��"+chinese_number(query_amount())+
        "���軨��������Բ��Ҫ�༸��ѽ������\n");
        if(!objectp(con=present("huapen", me1)))
           return notify_fail("������û�л��衣\n");
        tree1 = new(__DIR__"tree");
        if(tree1->move(this_player()))
        write("��С������İѻ������ڻ����С�\n");
        inv = all_inventory(me1);        
           for(i=0; i<sizeof(inv);i++)
             if(inv[i]->query("id") == "huapen") {a1 = inv[i];};
        destruct(a1);
        destruct(this_object());
        return 1;
                        
}
