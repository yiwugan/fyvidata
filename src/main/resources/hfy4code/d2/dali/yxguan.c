//lmd@wenxin
inherit ROOM;

void create()
{
        object con,item;

        set("short", "玉虚观");
        set("long", @LONG
香烟缭绕的玉虚观，不像其他的京中大寺，这里却是小巧
玲珑，正中是三宝金身，桌上摆满了供品。几个香客正在虔诚
的膜拜。
                         肃静

       皓                                    御

       首                                    静

       揽                                    清

       月                                    修 

LONG
        );
        set("exits", ([ 
  "north" :  __DIR__"shanroad1",
]));
        set("objects", ([
        __DIR__"npc/girl" : 1,
        __DIR__"obj/keyhold" : 1,
        __DIR__"obj/key" : 1,
        __DIR__"obj/xianglu" : 1,
        __DIR__"obj/desk" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-800);
        set("coor/y",-980);
        set("coor/z",120);
        setup();
        con = present("香炉",this_object());
        item= present("key", this_object());
        item->move(con);
        con = present("供桌",this_object());
        item= present("xianglu", this_object());
        item->move(con);
//        replace_program(ROOM);

}

void init()
{
        add_action("do_insert", "insert");
}

void close_path()
{
        if( !query("exits/southdown") ) return;
        message("vision",
"供桌下的洞消失了。\n",
                this_object() );
                delete("exits/southdown");
}

int do_insert(string arg)
{
 object obj;
 object me,con;
 if(!arg || arg=="")
  {
   write("你要插什么？\n");
   return 1;
  }
 me = this_player();
 if( arg == "key hole" || arg == "hole" || arg == "钥匙孔")
  {
   if(!objectp(con=present("key", me)))
    return notify_fail("你身上没有钥匙。\n");
   message_vision("$N尝试着把钥匙插进了墙角的一个很隐秘的钥匙孔里，转动了一下,\n随着吱吱的响声，供桌下出现了一个洞。\n", me);
   if(!me->query("m_success/无量山"))
    {
     me->set("m_success/无量山",1);
     me->add("score",100);
    }
   if( !query("exits/southdown") )
    {
     set("exits/southdown", __DIR__"hole1");
     call_out("close_path", 5);
    }
   return 1;       
  }
  else
   {
    write("你不能乱插!!\n");
    return 1;
   }
}