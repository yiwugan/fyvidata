inherit ROOM;
void create()
{
        set("short", "地下暗道");
        set("long", @LONG
这里伸手不见五指，但可以感觉到地道很窄，只能爬(climb)着过去。
远处似乎有一点点亮光。
LONG
        );
        set("no_magic",1);
        set("coor/x",-750);
        set("coor/y",-950);
        set("coor/z",80);
        setup();
}

init() 
{
        add_action("do_climb", "climb");        
}


int do_climb()
{
        object room;
        message_vision("$N顺着亮光向前爬去！\n",this_player());
        tell_object(this_player(),"爬出了洞口，你眼前一亮。\n",this_player());
        room = load_object(__DIR__"shanjiao");
        this_player()->move(room);
        return 1;       

}