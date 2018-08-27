 inherit ROOM;
void create()
{
        set("short", "拱形门");
        set("long", @LONG
一个小小的拱形门，青石小路在这里穿门而过。门旁挂著一块木
牌，写著“来宾止步”四个大字。从这里可看到，门里是一个小小的
院落，种著无数花草。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"wuroad3",
                "west" : __DIR__"wuroad1",
        ]));
        set("objects", ([ 
                __DIR__"npc/taoist3" : 1,
        ]));
        set("outdoors", "wudang");
        set("coor/x",120);
        set("coor/y",-130);
        set("coor/z",50);
        setup();
} 
int valid_leave(object me, string dir)
{
        int i; 
        if( userp(me) && dir == "east" ) {
                if( (string)me->query("family/family_name")!="武当派" ) {
                        if( (string)me->name()!="彭长净" ) {
                                me->set_temp("marks/偷", 1);
                        } 
                        else if( !(int)me->query_temp("marks/彭长净") )  {
                                me->set_temp("marks/偷", 1);
                        }
                        else {
                                me->set_temp("marks/偷", 0);
                        }
                }
                else {
                        me->set_temp("marks/偷", 0);
           }
        }
        return 1;
}   
