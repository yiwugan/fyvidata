 // Room: garden.c --- by MapMaker
inherit ROOM;
void bird_attack(object me);
int bird_flee(object me);
void create()
{
        set("short", "万木流莺园"); 
        set("long", @LONG
时间在这里似乎是静止的，一切依然笼罩在一种神秘的灰白色下，透过淡淡
的雾气，可见眼前是一片梅林，墨色的树枝虬干盘枝错结，向你展现着力与美，
枝头的花瓣却柔嫩的似乎一碰就碎。
LONG); 
        //{{ --- by MapMaker 
        set("exits",([
                "southdown" : __DIR__"garden",
        ]) );
        set("item_desc", ([
                "tree" : "一棵棵碗口大小的树开满了梅花。（ｃｈｏｐ　ｔｒｅｅ）\n", 
                "树林" : "一棵棵碗口大小的树开满了梅花。（ｃｈｏｐ　ｔｒｅｅ）\n", 
        ]));    
         
        set("tree", 1);
        set("indoors", "linghe");
        setup();
} 
void init(){ 
        add_action("do_chop", "chop");
} 
int do_chop(string arg){
    object obj;
    object me;
    
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
                ob=new(__DIR__"obj/tree2");
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
