 // XXDER@fy
inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "槐树上");
        set("long", @LONG
你发现你现在以经隐身在老槐树上，在这里阳光也透不过茂密的树冠。向前望
你可以清楚地看到八大弟子居住的院落，向后望，整个后花园还有池塘都落入你的
眼底，再往后，一条几乎被荒草淹没的小路不知通向何方。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "down" : __DIR__"garden",
   ])); 
   set("item_desc", ([
   "treetop" : "树冠茂密得使你看不到天空，你隐约看见树冠里似乎有一块黑乎乎的东西。\n",
   "树冠" : "树冠茂密得使你看不到天空，你隐约看见树冠里似乎有一块黑乎乎的东西。\n",
   ]) );
        set("coor/x",170);
        set("coor/y",2000);
        set("coor/z",10);
        setup();
} 
void init()
{
   add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "老槐树" && arg != "tree") return 0; 
   mlvl = (int)me->query_skill("move");
   if(mlvl < 70)
      message_vision("$N抬头向上望了望，心里不由的有些发慌。\n", me);
   else{
      message_vision("$N毫不费力得往上爬去。\n", me);
      room = find_object(__DIR__"treetop");
      if(!objectp(room)) room=load_object(__DIR__"treetop");
      me->move(room);
   }
   return 1;
}
