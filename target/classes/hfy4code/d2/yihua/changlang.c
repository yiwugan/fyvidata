inherit ROOM;

void create()
{
  set("short","桂花廊");
  set("long",@LONG
这是通往宫主寝宫的长廊，柱子和栏杆上都缠满了美丽的桂
花，左边有一间房间，从里面传来很嘈杂的声音，似乎有很多人。
LONG
     );

  set("exits",([
      "north" : __DIR__"yihua_ge",
      "south" : __DIR__"changlang1",
     ]));

        set("coor/x",-160);
        set("coor/y",125);
        set("coor/z",0);
 setup();
 replace_program(ROOM);
}
