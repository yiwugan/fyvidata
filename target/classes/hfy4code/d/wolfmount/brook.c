#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "浣花溪"); 
        set("long", @LONG
一道清澈见底的泉水从山中溅落下来，嘈嘈切切错杂弹地，大珠小珠似雨打玉
盘，两旁山花烂漫，溪水中各色缤纷的花瓣随着溪水静静地流淌，一切美丽如画。
泉水浅浅可行，逆流而上，可看到不远处白云深处的泉水源头有个湖泊。
LONG); 
        set("type","waterbody");
        set("outdoors", "wolfmount");
        set("exits",([
                "southeast":__DIR__"brook4",
                "southwest":__DIR__"brook3",
        ]) );
        set("objects",([
                __DIR__"npc/xiaoling":1,
                __DIR__"npc/xiaorou":1,
        ]) ); 
    set("coor/x",-720);
    set("coor/y",-710);
    set("coor/z",60);
        setup();
} 
void init()
{
        add_action("do_look", "look");
} 
void conch_notify()
{
        object me;
        int lel;
        me = this_player();
        lel = me->query("kar");
        if(random(100) < lel) 
        {
                remove_call_out("fog_disappear");
                call_out("fog_disappear",3,me);
        }
   else 
        {
                message_vision("许久许久，雾气依旧，什么都没有发生。\n",me);
        }
        return;
} 
int valid_leave(object me, string dir)
{
        if( userp(me) && dir=="southwest" )
        {
                if ( !me->query_temp("marks/wolf_blow_conch") ) 
                {
            message_vision("眼前白雾弥漫，难以看清前路，$N不得不停下脚步。\n", me);
                        return notify_fail("看来只有等到黎明时雾散再走了．\n");
                }
                else
                {
                        tell_object(me,"你趁着风起的瞬间，穿过薄雾。\n"); 
                        me->set_temp("marks/wolf_blow_conch",0);
                        return 1;
                }
        }
        else
        {
                return 1;
        }
} 
void fog_disappear(object me)
{
        tell_object(me,"突然一阵风刮起来，雾气似乎消散了许多。\n"); 
        if (! me->query_temp("marks/wolf_blow_conch"))
        {
                me->set_temp("marks/wolf_blow_conch",1);
        }
/*      else
        {
                me->set_temp("marks/wolf_blow_conch",0);
        }*/
        return;
} 
int do_look(string arg)
{
        object  me;
        me = this_player();
        if( arg == "southwest") 
        {
                message_vision(HIY"$N探头探脑的向西南方看了看．．．．．．\n"NOR, me);
                tell_object(me,"那边雾气弥漫，什么都看不到。\n"); 
                return 1;
        }
        return 0;
}  
