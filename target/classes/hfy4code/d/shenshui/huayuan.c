 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
随风而闻到传来的阵阵花香，原来在此处有个诺大的后花园，白水宫处于
山腹，这里却又豁然开朗，变成了另一个小小的谷地，园中鲜花浪漫，异香扑
鼻，在此仙境之中，夫复何求。东边一间竹制的房子，看上去十分的宽敞。
LONG
        );
        set("outdoors","shenshui");
        set("exits", ([ 
  "west" : __DIR__"cangjian",
  "north" : __DIR__"guayu",
  "east" : __DIR__"shufang",
  "south" : __DIR__"qingong",
]));
   set("objects", ([
      __DIR__"npc/qinggirl": 1,
      __DIR__"npc/xiang": 1,
   ]) );
        set("coor/x",190);
        set("coor/y",12360);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}     
