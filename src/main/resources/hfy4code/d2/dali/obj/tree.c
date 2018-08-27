#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("茶花苗", ({ "miao", "cha miao" }) );
        set("forzen",5);
set("no_give",1);
set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一盆茶花苗，你必须浇水（ｊｉａｏ）它才能成活。\n");
                set("unit", "盆");
                set("base_unit", "盆");
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
               return notify_fail("你身上没有茶花苗。\n");
            if(!objectp(con=present("pen pot", me)))
               return notify_fail("你身上没有喷壶。\n");
            if(!con->query("liquid"))
               return notify_fail( con->name() +"不是液体，不能用来浇花。\n");
            if(!con->query("liquid/remaining"))
               return notify_fail( con->name() + "是空的。\n");
            con->add("liquid/remaining", -10);
            message_vision("$N拿起" + con->name() + "将" +
            con->query("liquid/name")  + "浇在茶花苗上。\n",me);
            if((con->query("liquid/name") == "茶园井水") && !(random(5)))       
                {
                  tell_object(me,"花苗好象长高了一些！！\n");
                  add("forzen",-1);
                }
            else
                tell_object(me,"花苗好象没什么变化。\n");
                if( query("forzen") <= 0 )
                    {
/*        inv = all_inventory(me);        
           for(i=0; i<sizeof(inv);i++)
             if(inv[i]->query("id") == "miao") {a1 = inv[i];};
        destruct(a1);
*/                     tree2 = new(__DIR__"flower");
                     if(tree2->move(this_player()))
                     write("经过你的精心栽培，茶花成活了！！！\n");
                     destruct(this_object());
                     return 1;
                    }
          }


        return 1;
}
