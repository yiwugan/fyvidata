inherit ROOM;

void create()
{
        set("short", "十里长亭");
        set("long", @LONG
    这是一个岔路口，是远近闻名的十里长亭，大理人送至亲好友
都是此处，亭西即是大理城，由此东北去是通往东北方的沉香镇的
大道。这里向东南是著名的“蝴蝶泉”，据说能治百病。
LONG
        );
        set("exits", ([ 
  "northeast" :  __DIR__"qxroad",
  "west" : __DIR__"edoor",
  "southeast" : __DIR__"quan1",
]));
        set("objects", ([
        __DIR__"npc/girl1" : 1,
        __DIR__"npc/man1" : 1,
                        ]) );
        set("outdoors", "dali");
        set("coor/x",-650);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
        replace_program(ROOM);

}