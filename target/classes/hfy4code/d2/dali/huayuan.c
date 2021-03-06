inherit ROOM;

void create()
{
        set("short", "后花园");
        set("long", @LONG
好大的一个花园，种满了各种茶花，开满了五颜六色的花，几只彩
蝶在花中飞舞。花园中间是一个非常大的假山。还有一缕清泉从假山顶
流出，发出叮叮咚咚的声音。远处隐约听到读书声......
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"houdian",
]));
        set("objects", ([
                __DIR__"npc/monk4" :1,
        ]) );

        set("item_desc", ([
                "jiashan": "一个非常大的假山。\n",
                "假山": "一个非常大的假山。\n"

        ]) );

        set("outdoors", "dali");
        set("coor/x",-730);
        set("coor/y",-810);
        set("coor/z",150);
        setup();
}
void init()
{
        add_action("do_push", "push");
}

void close_path()
{
        if( !query("exits/westdown") ) return;
        message("vision",
"假山晃了晃，向西的路又消失了。\n",
                this_object() );
                delete("exits/westdown");
}

int do_push(string arg)
{
 object obj;
 object me;
 if(!arg || arg=="")
  {
   write("你要推什么？\n");
   return 1;
  }
 me = this_player();
 if( arg == "jiashan" || arg == "假山")
  {
   if( (int) me->query("force_factor") >= 120 )
    {
     message_vision("$N尝试着推了推假山，假山居然晃动了一下，露出了一条向西的路。\n", me);
     if(!me->query("m_success/见段誉"))
      {
       me->set("m_success/见段誉",1);
       me->add("score",150);
      }
     if( !query("exits/west") )
      {
       set("exits/westdown", __DIR__"jingshe");
       call_out("close_path", 5);
      }
     return 1;       
    }
    else
     {
      write("试着推了推假山，但没有推动。\n");
      return 1;
     }
  }
  else
   {
    write("你不能乱推"+arg+"\n");
    return 1;
   }
}