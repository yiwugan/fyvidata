inherit ROOM;
void create()
{
        set("short", "迎宾酒家");
        set("long", @LONG
这里是大理城里小有名气的酒家。来大理的人都要来这里品尝一下大理的特色美食。
店里整齐的摆着竹桌竹椅。厨房里飘出的阵阵香味让你不觉得胃口大开，一个店伙计正
在忙里忙外地招呼着客人。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"eroad1",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) ); 
        set("valid_startroom", 1);

        set("coor/x",-750);
        set("coor/y",-740);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}