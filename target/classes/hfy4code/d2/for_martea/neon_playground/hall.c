#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "������");
        set("long", CYN"  
______________________________________________________________ 
   
                                         ~
        
                    ~ 
                               ~   ~
                           
 
                             ��     ��          �� 
          ��  ��    
               ��              ��       
   ��     ��           ��       ��             ��          
        
        
        \n"NOR
        );
        set("exits", ([ 
  "east" : __DIR__"kezhan",
  ]));
        set("outdoors", "neon_playground");
        set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
