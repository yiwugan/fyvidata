 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","凌汉峰");
  set("long",@LONG
凌汉峰，取“会当凌绝顶”“会冲霄汉”之意，非泰山主峰，在西
却也是个好所在，西溪便发源于此，顺着蜿蜒山势，一泄至山腰，峰半
腰有一石窟。
LONG
  );
  set("exits",([
        "east" : __DIR__"doumu",
               ]));
        set("objects", ([
        __DIR__"obj/hole" : 1,
        __DIR__"npc/lengqingshuang" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",300);
        set("coor/y",2380);
        set("coor/z",30);
         
        setup();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string arg)
{
message_vision("$N试着往山峰上爬，结果一不小心，摔了下来！\n",this_player());
this_player()->unconcious();
return 1; 
}       
