 // Room: woodroad2.c --- neon
#include <ansi.h>
inherit ROOM; 
string view(string room);
void create()
{
        set("short", "楠木走廊"); 
        set("long", @LONG
这是一条长长的楠木走廊，它横架于滚滚流沙之上。长廊的木料透出金亮明橙
的楠木本色。这里热气已消，周围青草葱郁，使人不禁驻足浏览周围的风景。
LONG);
        
        set("indoors", "yinghe");
        set("exits",([
        "west":__DIR__"woodroad",
        "southeast":__DIR__"woodroad3",
        ]) );
        set("objects", ([
                __DIR__"npc/tan_tianlong" : 1,
        ]));
        setup();
} 
void init(){
        add_action("do_rest", "rest");
} 
int do_rest(){
        object me;
        string *rooms = ({"/d/guanwai/grassland0", "/d/guanwai/grassland1", "d/guanwai/grassland2",
"/d/guanwai/grassland3", "/d/guanwai/grassland4"});
        me = this_player();
        message_vision("$N坐在走廊栏杆上向外眺望。\n", me);
        tell_object(me, view(rooms[random(sizeof(rooms))]));
        if(me->query("attribute_mark") == "fire"){
                me->set_temp("yinghe_marks/rest", 1);
        }
        return 1;
} 
string view(string room) {
        int i;
        object *inv,env;
   mapping exits;
        string roomdesc, str, *dirs;
        
        env = find_object(room); 
        if(!env) {
                return "一句诗浮上你心头：大漠孤烟直，长河落日圆。\n";
        }
        if (!env->query("outdoors"))
                str = "那里的景色你依稀熟悉\n";
        else
                str = "只见天苍苍 野茫茫，朦胧沙海中，你好象见到了似曾相识的景象。。。\n\n";
        
        // room descriptions.
        str += sprintf( "%s \n    %s",
                        env->query("long"),
                        //wizardp(target)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
                        //              env->query("coor/y"),env->query("coor/z")): "",
                        //env->long(),
                        env->query("outdoors")? NATURE_D->outdoor_room_description() : "" ); 
        // exits. 
        
        // all things in the room.
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("no_shown") ) {
                        continue;
                }
                str += "  " + inv[i]->short() + "\n";
        }
        return str;
}  
int valid_leave(object obj, string dir){
        object ob;
        ob = present("tan tianlong", this_object());
        if(dir == "southeast" && objectp(ob)){
                if(obj->query("attribute_mark") == "fire" && obj->query_temp("yinghe_marks/rest")){
                        return 1;
                }
                message_vision("$N道：这位" 
+ RANK_D->query_respect(obj) + "，四周景色宜人，何不在此休息休息（ｒｅｓｔ）。\n",ob);
           return notify_fail("");
        }
        return 1;
}     
