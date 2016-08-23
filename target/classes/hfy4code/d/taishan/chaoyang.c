 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","朝阳洞");
  set("long",@LONG
由五松亭以来，一路松涛夹道，天色昏暗，别有幽趣，石道上怪石横空
宛若隧道，穿山而行，再一路向山，便是天街，由此以上，都是观日，朝阳
的好所在，东去便是梦仙龛。
LONG
  );
  set("exits",([
        "westdown" : __DIR__"wusong",
        "up" : __DIR__"duisong",
        "eastup" : __DIR__"mengxian",
               ]));
        set("objects", ([
        __DIR__"npc/dalao" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",320);
        set("coor/y",2390);
        set("coor/z",90);
        setup();
        replace_program(ROOM);
}       
