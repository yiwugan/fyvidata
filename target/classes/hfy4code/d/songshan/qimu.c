 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "启母石");
        set("long", @LONG
出县城不远，便到启母石，相传夏启的母亲所化，当年大禹治
水，开少室，太室之间的通道，妻子涂山氏来往送饭，一日山石拦
路，大禹化做巨熊开山，妻子见到化做熊的大禹，惊吓过度化为石
头，其实身怀六甲，后大禹抚石痛哭，居然石开而生子启，此石便
从此叫做“启母石”，是游嵩山必历的奇景。再往前行便是少室阙
了。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"shaoshi",
  "southeast" : __DIR__"dengfeng",
]));
        set("objects", ([
                __DIR__"npc/yumo" : 1,
       ]) );
        set("outdoors", "songshan");
        set("coor/x",-210);
        set("coor/y",110);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
