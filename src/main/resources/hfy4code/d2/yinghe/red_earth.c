 // Room: red_earth.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "红色土地");
        set("long", @LONG
这是一个红彤彤的土坡，它延伸而下，构成了五色土金字塔的一面。
LONG);
        set("type","street");
        set("exits",([
        "northup":__DIR__"earthtemple",
        ]) );
        //}}
    set("objects", ([
        __DIR__"npc/yan_duhe" : 1,
        __DIR__"npc/liu_yuhen" : 1,
        ]) );
        set("item_desc", ([
                "tupo" : "红彤彤的土坡似真似幻，你不由得想好好找找。（ｓｅａｒｃｈ）\n",
                "slop" : "红彤彤的土坡似真似幻，你不由得想好好找找。（ｓｅａｒｃｈ）\n",
                "土坡" : "红彤彤的土坡似真似幻，你不由得想好好找找。（ｓｅａｒｃｈ）\n",
        ]));
        set("red_jade", 1);
        setup(); 
} 
void init(){
        add_action("do_search", "search");
} 
int do_search(){
        object me, obj, yan;
        me = this_player();
        yan = present("yan duhe", this_object());
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("你正在忙！\n");
        }
        me->start_busy(1);
        message_vision("$N在红土地上仔细寻找。\n", me);
        if(objectp(yan)){
                message_vision("$N对着$n大喝一声：你鬼鬼祟祟的在干什么？\n", yan, me);
                yan->kill_ob(me);
   } else if(query("red_jade")){
                obj = new(__DIR__"obj/red_jade");
                if(objectp(obj)){
                        obj->move(me);
                }
                message_vision("$N从地上捡起一块红色的玉石。\n", me);
                delete("red_jade");
        } else {
                tell_object(me, "你什么都没有发现。\n");
        }
        return 1;
} 
void reset(){
        ::reset();
        if(!query("red_jade")) {
                set("red_jade", 1);
        }
}
