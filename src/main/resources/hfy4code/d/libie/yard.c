 // Room: yard.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "小院"); 
        set("long", @LONG
这是一间萧索冷清的小院，一棵衰老的白杨树已经开始枯萎，一
条黄狗蜷伏在墙角，墙的一角有口水井。院中搁了两个破石凳，一个
老者呆呆做在凳上喃喃地不知在说些什么。院子西首就是杨铮租的小
屋，破木门开着，风吹之下，“嘎嘎”作响。
LONG); 
        set("exits",([
        "west":__DIR__"nongjia",
        "south":__DIR__"stoneroad",
        "north":__DIR__"neishi",
        ]) );
        set("objects", ([
                __DIR__"npc/oldyu": 1,
        ]) );
        set("indoors", "libie");
        set("coor/x",45);
        set("coor/y",210);
        set("coor/z",0);
        setup(); 
} 
int valid_leave(object me, string dir)
{       object room; 
        room=this_object();
        
        if(!present("old yu",room)&&dir!="north")
        if(me->query_temp("libie/离别钩_取信")&&!me->query_temp("libie/离别钩_送信"))
                return notify_fail(HIY"还不赶快去取信？\n"NOR);         
        return 1; 
}  
