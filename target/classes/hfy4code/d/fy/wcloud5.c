 inherit ROOM;
void create()
{
        set("short", "西门东");
        set("long", @LONG
宽宽的黄土路向东西方向伸展，路边的茅屋矮小而破旧，街边的垃圾散发着令
人作呕的腐臭，路上的行人面黄肌瘦，被贫困的生活拖得疲惫不堪。偶而有一两个
面色红润之人，都掩鼻匆匆而过，生怕沾上一点晦气。一股生猛的肉味从北面的屠
记肉铺散发出来，浑杂着南首醉生小酒馆里劣酒的味道。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tuji",
  "south" : __DIR__"zuisheng",
  "west"  : __DIR__"wgate",
  "east"  : __DIR__"wcloud4",
])); 
        set("outdoors", "fengyun");
        set("coor/x",-50);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
