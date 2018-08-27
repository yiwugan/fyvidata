inherit ROOM;
void create()
{
        set("short", "地下暗道");
        set("long", @LONG
这里伸手不见五指，但可以感觉到地道很窄，只能爬(climb)着过去。
LONG
        );
        set("no_magic",1);
        set("coor/x",-800);
        set("coor/y",-990);
        set("coor/z",100);
        setup();
}

init() 
{
        add_action("do_climb", "climb");        
}


int do_climb()
{
        object room;
        message_vision("$N摸着黑向前爬去！\n",this_player());
        room = load_object(__DIR__"hole2");
        this_player()->move(room);
        tell_object(this_player(),"你感觉到地势越来越低了。\n",this_player());
        return 1;       

}