inherit ROOM;

void create()
{
        set("short", "剑湖谷底");
        set("long", @LONG
谷底有一大湖，只见湖畔生着一从丛茶花，在月下摇曳生姿。
这湖作椭圆形，大半部分隐在花从之中，其余各处决计无法攀上，
仰望高崖石壁，白雾封谷。世外桃源！
LONG
);
/*        set("exits", ([ 
  "east" : __DIR__"houdian",
]));
        set("objects", ([
                __DIR__"npc/monk4" :1,
        ]) ); */

        set("item_desc", ([
                "shibi": "在壁上隐约有剑影，剑影斜指向北，剑尖对准了一块岩石。\n",
                "石壁": "在壁上隐约有剑影，剑影斜指向北，剑尖对准了一块岩石。\n",
                "yanshi": "长满青苔的一块小岩石。\n",
                "岩石": "长满青苔的一块小岩石。\n"
        ]) );

        set("outdoors", "dali");
        set("coor/x",-700);
        set("coor/y",-900);
        set("coor/z",100);
        setup();
}

void init()
{
 add_action("do_push", "push");
}

void close_path()
{
 if( !query("exits/northdown") ) return;
 message("vision","岩石缓缓转动，石门又消失了。\n",this_object() );
 delete("exits/northdown");
}

int do_push(string arg)
{
 object me;

 me = this_player();
 if(!arg || arg=="")
  {
   write("你要推什么？\n");
   return 1;
  }
 if( arg == "yanshi" || arg == "岩石")
  {
   message_vision("$N尝试着推了推岩石，岩石居然晃动了一下，露出了一条向北的路。\n", me);
   if(!me->query("m_success/无量洞"))
    {
     me->set("m_success/无量洞",1);
     me->add("score",100);
    }
   if( !query("exits/northdown") )
    {
     set("exits/northdown", __DIR__"gudi1");
     call_out("close_path", 5);
    }
  }
  else write("你不能乱推!!\n");
  return 1;       
}