//lmd@wenxin
inherit ROOM;
void create()
{
        set("short", "大理城中心");
        set("long", @LONG
这里就是大理城的城中心，大理城的主要街道都在这里交会，宽广的路面在这里
形成了一个方园约十余丈的广场。广场呈菱形，一圈围的都是小贩，艺人，和看热闹
的。熙熙攘攘的人群中也少不了些个跑江湖的，杂耍声，叫卖声此起彼伏。一些在中
原闻所未闻的新鲜事物令一些初入江湖的年轻人兴奋不已。位于广场中心有一个不大
不小的水池，一巨大的闹龙石柱耸立水池中央，一汩汩的甘泉水从石柱的龙嘴中涌出，
放眼向石柱上看去，只见上书：
[1;32m
                         ~   天  大  ~

                         ~   下  理  ~

                         ~   太  中  ~

                         ~   平  兴  ~
[37m                         

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gnroad1",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
  "west" : __DIR__"wroad1",
]));
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);
        set("outdoors", "dali");
        set("resource/water",1);
        set("liquid/name","清澈的池水");
        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("coor/x",-800);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
// To "load" the board, don't ever "clone" a bulletin board.
  //      call_other( "/obj/board/dali_a", "???" );

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
                                "name": "甘泉水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你在龙嘴下装满了清澈的甘泉水！ \n");
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