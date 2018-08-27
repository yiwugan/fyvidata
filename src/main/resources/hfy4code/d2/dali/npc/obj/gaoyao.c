// medicine.c

inherit ITEM;

void create()
{
        set_name("狗皮膏药",({"gaoyao"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "一张狗皮膏药， 可以敷（ｆｕ）在患处，用来增加气血 。\n");
            set("unit","张");
            set("value", 1000);
        }
}

void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","fu");
}

int apply_medicine()
{
        int value = 10;
        int diff;

        if(this_player()->is_fighting())
            return notify_fail("战斗中不能用药！！\n");
        diff = this_player()->query("max_sen")-this_player()->query("eff_sen");
        if(!(diff))    return notify_fail("你没有受伤！\n");
        if(value > diff) value = diff;
            
        message_vision("$N将狗皮膏药敷在患处．\n",this_player());
        this_player()->add("eff_kee",value);
        destruct(this_object());
        return 1;
}