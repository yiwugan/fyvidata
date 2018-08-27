 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "少室阙");
        set("long", @LONG
少室阙是嵩山现存三汉阙中的一块，雕刻细致，字体飘逸，过
少室阙便入了少室山，阙上铭文详细记述帝王封少室的种种逸事，
以少室阙，少林河为界，西则为少室山，东则为太室山，由此可折
向西面，便是闻名天下的禅宗祖庭，武学发源地--少林寺。
LONG
        );
        set("exits", ([ 
  "northwest" : AREA_SHAOLIN"ent",
  "southwest" : __DIR__"qimu",
  "east" : __DIR__"shuyuan", 
]));
        set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
        set("outdoors", "songshan");
        set("coor/x",-200);
        set("coor/y",120);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
