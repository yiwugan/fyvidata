 // Room: irongate.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "青砖甬道");
        set("long", @LONG
这是一条宽敞的甬道。地面用密实的青砖铺就。甬道尽头，一座灰暗的大铁门
伫立在眼前。门前的青砖似乎有被人翻动过的痕迹。
LONG); 
        set("objects", ([
                __DIR__"obj/yubow" : 1,
        ]));
        set("outdoor","yinghe");
        
        
        setup();
}
void init(){
        object bow;
        add_action("do_open", "open");
        bow = present("yu bow", this_object());
        if(objectp(bow)){
                bow->set("installed", 1);
        }        
}  
void close_path(int i){
        object room;
        switch(i) {
        case 1:
                if( query("exits/south") ) {
                message("vision","哐铛一声大门在你面前关闭。\n",this_object() );
                delete("exits/south");
                room = find_object(__DIR__"irongate2");
                if(!objectp(room)) {
                        room = load_object(__DIR__"irongate2");
                }
                message("vision","哐铛一声大门在你面前关闭。\n", room);
                        room->delete("exits/north");
            }
        break;
   case 2:
                if( query("exits/north") ) {
                message("vision","哐铛一声大门在你面前关闭。\n",this_object() );
                delete("exits/north");
                room = find_object(__DIR__"thundercity");
                if(!objectp(room)) {
                        room = load_object(__DIR__"thundercity");
                }
                message("vision","哐铛一声大门在你面前关闭。\n", room);
                        room->delete("exits/south");
            }   
    break;
    }
}
int do_open(string arg){
        object room, me, room1;
        
        me = this_player();
    if( arg=="south door" || arg =="乌黑的大铁门") {
                if(query("exits/south")){
                        return notify_fail("门已经被打开了。\n");
                }
        message_vision("$N往大铁门上轻轻地一推，大铁门缓缓打开。\n", me);
                room = find_object(__DIR__"irongate2");
                if(!objectp(room)){
                        room = load_object(__DIR__"irongate2");
                }
                message("vision", "门被人从另外一边打开。\n", room);
                room->set("exits/north", __DIR__"irongate");
                set("exits/south", __DIR__"irongate2");
                call_out("close_path", 5, 1);
                return 1;
        } 
        if (arg=="north door" || arg =="灰暗的大铁门") {
                if(query("exits/north")){
                        return notify_fail("门已经被打开了。\n");
                }
        message_vision("$N往大铁门上轻轻地一推，大铁门缓缓打开。\n", me);
                room = find_object(__DIR__"thundercity");
                if(!objectp(room)){
                   room = load_object(__DIR__"thundercity");
                }
                message("vision", "门被人从另外一边打开。\n", room);
                room->set("exits/south", __DIR__"irongate");
                set("exits/north", __DIR__"thundercity");
                call_out("close_path", 5, 2);
                return 1;
        } 
        if(arg = "door"){
                return notify_fail("你要开那一扇门？（ｎｏｒｔｈ　ｄｏｏｒ／ｓｏｕｔｈ　ｄｏｏｒ）\n");
        }
        else {
                write("你要推什么呢？\n");
        }
        return 1;       
        message_vision("$N伸手推开了大铁门。\n", me);
}
