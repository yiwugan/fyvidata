 inherit ROOM;
void create()
{
                object silver;
        set("short", "隧道东");
        set("long", @long
隧道内漆黑一片，但乾爽宁静。虽然横七竖八摆了很多东西，不过依然显
得很宽敞。地上还有一些湿漉漉的脚印，显然经常有人来往。偶然身边闪过一
个身影，也不觉得惶恐。人们似乎对地上的宝物并不贪婪，只取去自己所需，
便悄悄离开。
long
        );
        set("exits", ([ /* sizeof() == 4 */
"out" : __DIR__"enewbie3",
  "enter" : __DIR__"newbiecenter",
  
]));
        set("objects", ([
               "/d/palace/npc/obj/hammerbook":1,
"/d/taishan/npc/obj/staffbook":1,
"/d/chuenyu/npc/obj/parrybook":1,
                
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",20);
        set("coor/y",0);
        set("coor/z",-10);
        
        setup();
    

}
