 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
//inherit NO_FIGHT_ROOM;
inherit ROOM;
void create()
{
  set("short","����д����");
  set("long",@LONG 
''';'';;''';'''
   ;;''''';;'
   ;;''''';;
   ;;''''';;
   ;';;'''';
   ,;';''';;'
 ,;'  ,;,;;,
' ,,,''   '';;' 
LONG
  );
  set("exits",([
         "southwest" : __DIR__"casino1",
         "east" : __DIR__"winter",
               ]));
        set("objects", ([
                __DIR__"npc/xiali" : 1,
       ]) );
        set("coor/x",50);
        set("coor/y",1980);
        set("coor/z",1);
        set("no_magic",1);
        set("no_fight",1);
        set("no_cast",1);
        set("NONPC",1);
        set("no_spells",1);
//    set("throw_exit","southwest");
        setup(); 
}
int valid_leave(object me, string dir)
{
   object dealer, pl;
        string *locs = ({"north","south","east","west"});
        int m;
        dealer = present("xia li",this_object());
        for(m=0;m<sizeof(locs);m++)
        if(objectp(pl=dealer->query(locs[m]+"/player")) && pl == me)
        return notify_fail("�ľ����ڽ����У���������߶���\n");
        return 1;
}  
