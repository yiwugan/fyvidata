 // street2.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","碑林");
  set("long",@LONG
泰山就在眼前了，东北处便是名闻遐迩的岱庙。路边立了密密麻麻许多石
碑，最显眼的当数一块丈许高的铜碑。上面据说是当年杜子美游览泰山后，意
兴所至，挥墨而就的『望岳』，千古流芳。
LONG
  );
  set("exits",([
         "southwest":__DIR__"road3",
         "northeast":AREA_DAIMIAO"yaocan",
               ]));
    set("outdoors", "jinan");
    set("coor/x",300);
    set("coor/y",2200);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}     
