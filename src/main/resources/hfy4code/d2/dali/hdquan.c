inherit ROOM;
#include <room.h>
void create()
{
        set("short", "蝴蝶泉");
        set("long", @LONG
眼前出现了美丽的景象，远处群山环抱，近处绿树苍苍，鲜花遍地，有许多彩蝶
在花间飞舞，仿佛置身仙境。鲜花中间有一个很大的泉眼，汩汩清泉涌出，带着缕缕
清香，令人心旷神怡。泉水在不远处汇成一个小湖，据说颇有去病健身之功效。有几
个小孩正在水中嬉水，传来阵阵笑声，令人也想试试（ｊｕｍｐ）。
LONG
        );
        set("exits", ([
                "north" : __DIR__"quan8",
        ]));
        set("resource/water",1);
        set("liquid/name","蝴蝶泉水");
        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("objects", ([
                __DIR__"npc/beauty": 3,
                __DIR__"npc/boy": 2,
          ]) );
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_magic", 1);
        set("coor/x",-620);
        set("coor/y",-800);
        set("coor/z",80);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_fillwater", "fillwater");
}

int do_jump()
{
        object me;
        int wait;
        me = this_player();
        if (me->query_temp("hdqwashing")) {
                tell_object(me,"你已经在泉水中了！\n");
                return 1;
        }
        wait = random( 10 - (int)(me->query("con"))) ;
        if ( wait <= 10) wait = 1;
        message_vision("$N噗嗵一声跳进湖里。\n",me);
        tell_object(me,"清澈的湖水包围着你，让你感到全身无比的舒泰．．\n");
        me->set_temp("hdqwashing",1);
        call_out("curehimup", wait, me);
return 1;
}

void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
        {
        message_vision("$N缓缓的爬上泉边，眼前出现了彩蝶飞舞的景象，$N的精气神全得到了恢复！！\n", me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
}
me->delete_temp("hdqwashing");
return;
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
                                "name": "蝴蝶泉水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你在蝴蝶泉里装满了清澈的蝴蝶泉水！ \n");
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
