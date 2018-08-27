 inherit ROOM;
void create()
{
        set("short", "天涯路");
        set("long", @LONG
万里荒寒，连残阳都似已因寂寞而变了颜色，变成一种空虚而苍凉的灰白色。
漠漠黄沙，无边无际。似乎永远也走不到头，一眼望去，天连着黄沙，黄沙连着
天；人，也已在天涯。  
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"mfoot",
  "northwest" : __DIR__"skyroad2",
]));
        set("outdoors", "quicksand"); 
        set("coor/x",-1120);
    set("coor/y",100);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_go","go");;
}
int do_go()
{
if(random(10)){
this_player()->move(this_object());
return 1;
}
}      
