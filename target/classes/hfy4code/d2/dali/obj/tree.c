#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("�軨��", ({ "miao", "cha miao" }) );
        set("forzen",5);
set("no_give",1);
set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��軨�磬����뽽ˮ�����������ܳɻ\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 50000);
                set("base_value", 1);
        }
        set_amount(1);

}
void init()
{
  if(this_player()==environment())
  add_action("do_jiao","jiao");

}


int do_jiao()
{
        object me,jade,tree2;
        object con;
        me = this_player();
        if(!query("have"))
          {
            if(!objectp(con=present("miao", me)))
               return notify_fail("������û�в軨�硣\n");
            if(!objectp(con=present("pen pot", me)))
               return notify_fail("������û�������\n");
            if(!con->query("liquid"))
               return notify_fail( con->name() +"����Һ�壬��������������\n");
            if(!con->query("liquid/remaining"))
               return notify_fail( con->name() + "�ǿյġ�\n");
            con->add("liquid/remaining", -10);
            message_vision("$N����" + con->name() + "��" +
            con->query("liquid/name")  + "���ڲ軨���ϡ�\n",me);
            if((con->query("liquid/name") == "��԰��ˮ") && !(random(5)))       
                {
                  tell_object(me,"������󳤸���һЩ����\n");
                  add("forzen",-1);
                }
            else
                tell_object(me,"�������ûʲô�仯��\n");
                if( query("forzen") <= 0 )
                    {
/*        inv = all_inventory(me);        
           for(i=0; i<sizeof(inv);i++)
             if(inv[i]->query("id") == "miao") {a1 = inv[i];};
        destruct(a1);
*/                     tree2 = new(__DIR__"flower");
                     if(tree2->move(this_player()))
                     write("������ľ������࣬�軨�ɻ��ˣ�����\n");
                     destruct(this_object());
                     return 1;
                    }
          }


        return 1;
}
