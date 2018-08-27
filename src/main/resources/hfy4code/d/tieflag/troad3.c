 //troad3
inherit ROOM; 
void create()
{
        set("short", "危崖前");
        set("long", @LONG
小路到此突然中断，一道危崖档住你的去路。崖上藤条缠绕，显的颇为古怪。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"troad2",
]));
        set("objects", ([
        __DIR__"npc/cat" : 1,
                        ]) ); 
        set("item_desc", ([
                "tree": "这里的藤条(tree)很密，似乎经过人工布置。\n",
                "藤条": "这里的藤条(tree)很密，似乎经过人工布置。\n" 
        ]) );
        
        set("outdoors","tieflag");      
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",25);
        setup();
}
void init()
{
        add_action("do_west", "w");
        add_action("do_west", "west");
}
int do_west(string arg)
{
        object me;
        object room;
        object *inv;
        int i;
        me = this_player();
        inv = all_inventory(me);
        if(!me->query_temp("mark/cat"))
        {
        for(i=0; i<sizeof(inv); i++)
        {
         if((string)(inv[i]->query("id")) == "leaf" && inv[i]->query("real"))       
          {
           me->set_temp("mark/cat",1);
           destruct(inv[i]);
           break;
          }
        }
        }
        if(me->query_temp("mark/cat"))
        {       
//              me->delete_temp("mark/cat");
                message_vision("$N掀开藤条，从西面的一个山洞钻了进去。\n", me);
                room = load_object(__DIR__"dong0");
                if(room) me->move(room);
                return 1;
        }
        return 0;
} 
