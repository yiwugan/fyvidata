#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "�����");
       set("half", "�����");
        set("long", @LONG
�������������£�����о������η�������
LONG
        );
                set("exits", ([ 
                "jump":       "/d/fy/fysquare",
        ]));
        set("no_death_penalty",1);
  
   
        setup();
        replace_program(ROOM);
}
     
