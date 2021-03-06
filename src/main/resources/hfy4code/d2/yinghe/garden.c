 // Room: garden.c --- by MapMaker
inherit ROOM;
void bird_attack(object me);
int bird_flee(object me);
void create()
{
        set("short", "万木流莺园"); 
        set("long", @LONG
景色猛然一变，眼前出现一片翠绿的树林，其间不乏奇花异草，林间四季漂
浮着淡淡的雾气及花香，充耳是鸟鸣之声，美丽的夜莺不时地盘旋在西方的一扇
小木门前。这里时间似乎是停止的，一切都笼罩在一种神秘的灰白色下。
LONG); 
        //{{ --- by MapMaker 
        set("exits",([
                "east":__DIR__"slop",
                "northup" : __DIR__"gardenn",
                "southdown" : __DIR__"gardens",
        ]) );
        set("item_desc", ([
                "door" : "一扇小木门，似乎可以推开。（ｐｕｓｈ）\n",
                "小木门" : "一扇小木门，似乎可以推开。（ｐｕｓｈ）\n",
                "门" : "一扇小木门，似乎可以推开。（ｐｕｓｈ）\n",
                "tree" : "一棵棵碗口大小的树挺拔苍翠。（ｃｈｏｐ　ｔｒｅｅ）\n", 
                "树林" : "一棵棵碗口大小的树挺拔苍翠。（ｃｈｏｐ　ｔｒｅｅ）\n", 
        ]));    
        
        set("objects", ([
                __DIR__"npc/bird_guard" : 4,
        ]));
        set("tree", 1);
        set("indoors", "linghe");
        setup();
} 
void init(){
        add_action("do_push", "push");
        add_action("do_chop", "chop");
} 
int do_chop(string arg){
    object obj, me;
    
    me = this_player();
        if(!query("bird_flee")) {
                bird_attack(me);
                return 1;
        }
    if(arg && (arg=="tree" || arg=="树")){
        obj = me->query_temp("weapon");
        if( !obj ) {
            write("你空着手，怎么砍？\n");
            return 1;
        }
        if( obj->query("flag") == 4){
            if(query("tree")) {
                object ob;
                message_vision(sprintf(
                    "$N挥动%s，转眼间一棵小树就被砍倒了。\n",obj->name()),me);
                delete("tree");
                ob=new(__DIR__"obj/tree");
                if(objectp(ob)){
                       ob->move(me);
                        }
            } else {
                                return notify_fail("没有合适的树了。\n");
                }
        } else {
                message_vision(sprintf(
            "$N用手中的%s向小树上一通乱砍。\n",obj->name()), me);
        }
    }
    else write("你要砍什么？\n");
    return 1;
}
void close_path(){
        object room;
        room = find_object(__DIR__"woodcabin");
        if(!objectp(room)){
                room = load_object(__DIR__"woodcabin");
        }
        if( room->query("exits/east")){
                message("vision","吱呀。。。一声木门又掩上了。\n",room );
           room->delete("exits/east");
    }
        if( query("exits/west") ) {
        message("vision","吱呀。。。一声木门又掩上了。\n",this_object() );
        delete("exits/west");
    }
} 
int do_push(string arg){
        object me, *inv, bird, room;
        int i, j; 
    me = this_player();
    if(query("exits/west")){
        return notify_fail("门是开着的。\n");
    }
        if(!query("bird_flee")) {
                bird_attack(me);
                return 1;
        }    
    if( arg=="door" || arg =="门" || arg == "小木门") {
        message_vision("$N往小木门上轻轻地一推，吱。。。的一声门开了。\n", me);
                set("exits/west", __DIR__"woodcabin");
                room = find_object(__DIR__"woodcabin");
                if(!objectp(room)){
                        room = load_object(__DIR__"woodcabin");
                }
                room->set("exits/east", __DIR__"garden");
                call_out("close_path", 5);
        } else {
                write("你要推什么呢？\n");
        }
        return 1;       
} 
void bird_attack(object me){
        object *inv, bird;
        int i, j;
        
        inv = all_inventory();
        j = 0;
        for(i=0; i<sizeof(inv); i++){
                if(inv[i]->query("id") == "nightingale"){
                   inv[i]->kill_ob(me);
                        j++;
                }
        }
        if(j < 4){
                for(i=0; i<random(4)+2; i++){
                        bird = new(__DIR__"npc/bird_guard");
                        if(objectp(bird)){
                                bird->move(this_object());
                        }
                        message_vision("扑楞楞，几只夜莺俯冲下来，拦在$N面前。\n", me);
                        bird->kill_ob(me);
                }
        }
        return notify_fail("一群夜莺在你面前飞舞着，拦阻了你的去路。\n");
} 
int valid_leave(object who, string arg){
        object bird, *inv, *guard;
        int i, j;
        if(arg == "west"){
                if(query("bird_flee")) {
                        return 1;
                } else {
                        bird_attack(who);
                }
        }
        return 1;
} 
int bird_flee(object me){
        object *inv;
        int i, j;
        j = 0;
        inv = all_inventory();
        for(i=0; i<sizeof(inv); i++){
                if(inv[i]->query("id") == "nightingale"){
                        destruct(inv[i]);
                        j++;
                }
        }       
        if (j) {        
           message_vision("在霹雳般的响声中，夜莺惊惶的向四下飞去。\n", me);
                set("bird_flee", 1);
                call_out("bird_back", 10);
                return 1;
        }  
        return 1;
} 
void bird_back(){
        message_vision("四周又充满了悦耳的鸟鸣。\n", this_object());
        delete("bird_flee");
} 
void reset(){
        ::reset();
        set("tree", 1);
}
