inherit ROOM;
void init();
void create()
{
        set("short", "地下密室");
        set("long", @LONG
由于当年一场恶战.燕大侠全身经脉震断.成为废人
而其子小鱼儿孝心不死.专设一密室.为燕南天每天
运功疗伤.日复一日.燕大侠还是毫无转机.泡在药缸
里就如活死人一般。西边的墙壁影出光亮。
LONG );
        set("exits", ([ 
  "eastup" : __DIR__"congwai",
])); 
        set("objects",([
           __DIR__"obj/book2" : 1,
           __DIR__"obj/book3" : 1,
           __DIR__"obj/book" : 1,                                                   __DIR__"obj/book1" :1,
        ]) );
        set("coor/x",-195);
        set("coor/y",250);
        set("coor/z",20);
        set("no_magic",1);
        set("item_desc", ([
                "墙壁": "一面光滑墙壁。\n",
        ]) );;
        set("no_dazuo",1);
        setup();
}
void init()
{
        add_action("do_jump", "break");
}

int do_jump(string arg)
{
        object me=this_player(), room;

        if(!arg || arg!="墙壁")
                return notify_fail("你想干什么？\n");

        if(!( room = find_object(__DIR__"dishi1")) )
                room = load_object(__DIR__"dishi1");

        if(!objectp(room))
                return notify_fail("ERROR:not found 'xiaojin.c' \n");
   if(!(me->query("force_factor") >= 120))
                return notify_fail("你运起灵神决，双手合十，一招水火不容向墙壁击去。\n墙壁一动不动。\n");
   if(me->query_skill("lingshenforce") < 120 && me->query_skill("binghuostrike") < 80)
                return notify_fail("你的武功不能打开这块墙壁。\n");
        message_vision("$N运起灵神决，双手合十，一招水火不容向墙壁击去。\n由于用力过猛，你掉进墙壁里面去了。\n",me);
        me->move(room);
        return 1;
}
