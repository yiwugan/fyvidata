#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("茶花幼苗", ({ "youmiao"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                
set("long","带着几片叶子的花苗，也许你可以把它移植（ｚｈａｉ）到别处。\n");
                set("unit", "捆");
                set("base_unit", "根");
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
        return notify_fail("才"+chinese_number(query_amount())+
        "根茶花幼苗根本栽不活，要多几根呀．．．\n");
        if(!objectp(con=present("huapen", me1)))
           return notify_fail("你身上没有花盆。\n");
        tree1 = new(__DIR__"tree");
        if(tree1->move(this_player()))
        write("你小心翼翼的把花苗栽在花盆中。\n");
        inv = all_inventory(me1);        
           for(i=0; i<sizeof(inv);i++)
             if(inv[i]->query("id") == "huapen") {a1 = inv[i];};
        destruct(a1);
        destruct(this_object());
        return 1;
                        
}
