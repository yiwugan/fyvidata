 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "万马堂堂口");
        set("long", 
"　　　　　 　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌
 　　　　　　　　≌≌　　　　　　　　　　　　　≌≌
　 　　　　　　　≌≌　　　"HIR"万　　马　　堂"NOR"　　　≌≌
 　　　　　　　　≌≌　　　　　　　　　　　　　≌≌
 　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"+
@LONG
    用整条杉木围成的栅栏，高达三丈。里面一片屋宇，看不出有多少间。一道拱
门矗立在夜色中，门内的刁斗旗杆看来更高不可攀。一盏天灯，慢慢地升起在十丈
高的旗杆上，雪白的灯笼上三个鲜红的大字。
LONG
        );
        set("exits", ([ 
                "enter" : __DIR__"yard",
                "south" : __DIR__"grassland2",
                "southeast": __DIR__"grassland3",
        ]));
        set("objects", ([
                __DIR__"npc/vguard":    2,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1110);
        set("coor/y",260);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me, string arg) {
        object ob;
        
        ob=present("white man",this_object());
        me=this_player();
        if (!ob) return 1;
        
        if (userp(me))
        if (arg== "enter" &&  !me->query("wanma/迎宾")) {
        	message_vision("$N说：“三堂主今天有重要客人，闲杂人等，不准入内。”\n",ob);
                return notify_fail("");
        }
        
        return 1;
}
