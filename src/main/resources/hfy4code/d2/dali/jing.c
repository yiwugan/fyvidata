//lmd@wenxin
inherit ROOM;
void create()
{
        set("short", "水井");
        set("long", @LONG
这是大理茶园的水井，据说用这口井的水浇茶花才能长出极品茶花。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"chayuan",
]));
        set("outdoors", "dali");
        set("resource/water",1);
        set("liquid/name","茶园井水");
//        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("coor/x",-820);
        set("coor/y",-830);
        set("coor/z",80);
        setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "茶园井水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你装满了刚从井里打上来的水！ \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}
