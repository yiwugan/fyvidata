#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "半空中");
       set("half", "半空中");
        set("long", @LONG
蓝天白云在你脚下，让你感觉到神游方外的美妙。
LONG
        );
                set("exits", ([ 
                "jump":       "/d/fy/fysquare",
        ]));
        set("no_death_penalty",1);
  
   
        setup();
        replace_program(ROOM);
}
     
