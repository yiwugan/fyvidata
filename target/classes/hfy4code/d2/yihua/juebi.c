inherit ROOM;

void init();
int do_zou(string);

void create()
{
  set("short","绝壁");
  set("long",@LONG
在你东边是一条绝壁，往下看去云雾缭绕，北边下面是个花园，你根
本无法看清谷底。你向东望去(east)什么也看不见，旁边有一块石碑(bei)。
LONG
     );
  set("outdoors", "yihua");
  set("exits",([
      "southdown" : "/d/yihua/qiaobi",
      "northdown" : "/d/yihua/xiaojing",
     ]));
  set("item_desc",([
      "bei" : "『移花宫』禁止外人进入,违者后果自负！\n" ,
      "east" : "这里没有任何路，你想不通可以(jump)下去。\n" ,
     ]));
        set("coor/x",-170);
        set("coor/y",170);
        set("coor/z",40);
 setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me=this_player(), room;

        if(!arg || arg!="east")
                return notify_fail("你真的想不通吗？\n");

        if(!( room = find_object(__DIR__"xiaojin")) )
                room = load_object(__DIR__"xiaojin");

        if(!objectp(room))
                return notify_fail("ERROR:not found 'xiaojin.c' \n");
        message_vision("$N双眼一闭，纵然跳了下去。\n",me);
//       　message("vision","你只见一个身影从天而降。\n", room);
        me->move(room);
        return 1;
}
