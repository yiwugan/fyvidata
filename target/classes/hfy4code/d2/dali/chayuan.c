inherit ROOM;
void create()
{
        set("short", "茶花园");
        set("long", @LONG
院中种满了茶花幼苗。每棵都在茁壮成长，显然有人精心照顾。花苗
之间还有人工开垦的小河沟，半尺深的渠水绕树而淌，灌溉着每一棵幼苗。
土壤黑而酥松，显然是饱含营养的肥土。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sroad2",
  "west" : __DIR__"jing",
]));
        set("outdoors", "dali");
        set("item_desc", ([
                "茶花": "
你似乎可以挖（ｄｉｇ）几根花苗出来。
                        \n",

        ]) );
        set("coor/x",-810);
        set("coor/y",-830);
        set("coor/z",80);
        setup();
}
void init()
{
        add_action("do_dig","dig");
}
do_dig()
{
object vege;
if((this_player()->query("sen") < 70) || (this_player()->query("kee") < 70) || (this_player()->query("gin") < 70) )
 {
  write("你已经没有力气再挖了。\n");
  return 1;
 }
if((int) query("pulled") <= 5000)
{
write("你挖了一棵茶花幼苗放在怀里。\n");
vege = new(__DIR__"obj/huamiao");
vege->move(this_player());
this_player()->add("sen",-(random(50)+20));
this_player()->add("kee",-(random(50)+20));
this_player()->add("gin",-(random(50)+20));
add("pulled",1);
return 1;
}
else
        write("都被人挖光了！！\n");
        return 1;
}

void reset()
{
:: reset();
delete("pulled");
}
