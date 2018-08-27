inherit ROOM;
void create() 
{ 
    set("short", "甬道"); 
    set("long", @long
甬道里高低起伏不平，忽而爬上，忽而往下，走起来的时候脚上
要用点力，免得人踉踉跄跄不知摔到哪里。转了几个弯后，走上一个
石台，迎面又有个大字「停」。 
long 
    ); 
    /*set("item_desc", ([ 
        "清潭":  "清潭明澈见底，不时的有小鱼越出水面。\n", 
        "pond":  "清潭明澈见底，不时的有小鱼越出水面。\n", 
    ])); */
    set("exits", ([ 
    		"east": __DIR__"midao",
    		"south": __DIR__"midao",
    		"west": __DIR__"midao",
    		"north": __DIR__"midao",
        ])); 
    set("indoors","shanxi"); 
set("coor/x",-460);
        set("coor/y",-260);
        set("coor/z",100);
        setup(); 
} 
void init() 
{ 
   add_action("do_around", "around"); 
   add_action("do_stop", "stop"); 
} 
 
int do_around(string arg) 
{ 
   object me, room; 
   int i; 
    
   string *rooms = ({"alou2", "alou2a", "alou2b", "alou2c"}); 
   i = random(4); 
   me = this_player(); 
   tell_object(me, "你转来转去，也没找到出口，你迷了路！！\n\n"); 
   room = find_object(__DIR__ + rooms[i]); 
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]); 
   me->move(room); 
 
   return 1; 
} 
int do_stop(string arg) 
{ 
   object me; 
   /*int i; 
    
   string *rooms = ({"alou2", "alou2a", "alou2b", "alou2c"}); 
   i = random(4); */
   me = this_player(); 
   tell_object(me, "你刚站停，忽然发现站着的这石台猛地往下沉。。。然後就到了一间六角形的石屋。\n\n"); 
   /*room = find_object(__DIR__ + rooms[i]); 
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]); */
   me->move("/d2/shanxi/alou3"); 
    return 1; 
} 
