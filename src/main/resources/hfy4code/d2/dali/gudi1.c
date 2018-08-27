inherit ROOM;
void create()
{
        set("short", "无量山洞");
        set("long",@LONG 
这是一间石室，石室中放着一个石桌，桌前有凳，桌上竖着一面铜镜，镜旁
放着些梳子……，看来竟是闺阁所居。铜镜上生了铜绿，桌上也是尘土寸积，不
知已有多少年没人来此了。屋子正中放着一个白玉女子塑像，雕刻的栩栩如生，
如仙女一般。像前有一大一小两个蒲团供人跪拜用。

                         洞中无日月，人间至乐也！
        
LONG
        );
        set("exits", ([
                "east" : __DIR__"gudi2",
                "south" : __DIR__"gudi3",
           ]));
        set("item_desc", ([
        "塑像": "　“磕首千遍，供我驱策，遵行我命，百死无悔”　　（ＫＮＥＥ）吧……\n\n",
        "xiang": "　“磕首千遍，供我驱策，遵行我命，百死无悔”　　（ＫＮＥＥ）吧……\n\n",
        ]) ); 
        set("no_magic",1);
        set("coor/x",-700);
        set("coor/y",-890);
        set("coor/z",90);
        setup();
}

init() 
{
        add_action("do_knee","knee");
}

int do_knee()
{
 object me,con,tu;

 me=this_player();
 message_vision("$N走到蒲团前，虔诚的膜拜下去。\n",me);
        if (me->query("xvt_over"))
              return notify_fail("你忽然发现有什么东西掉了出来。\n");
 if(!random(10))
   if(!objectp(con=present("xiannv-tu", me)))
    {
     message_vision("$N忽然发现有什么东西掉了出来，赶紧收入怀中。\n",me);
     tu = new(__DIR__"obj/tu");
    tu->set("names",me->query("name"));
     this_player()->set("xvt_over",1);
     tu->move(me);
    }
 return 1;
}
