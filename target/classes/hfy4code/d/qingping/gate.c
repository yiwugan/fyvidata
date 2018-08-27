 inherit ROOM;
void create()
{
        set("short", "山庄大门");
        set("long", @LONG
这里便是清平山庄的大门，红色得大门看上去普普通通，只有门额
上的"清平山庄"四字甚是惹人注目，门口立着几位劲装少年，正是清平
门下弟子，门前一棵老槐树，枝叶茂密，似乎体现着庄主的独特风骨。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuchang1",
  "west" : __DIR__"road",
]));
   set("objects", ([
      __DIR__"npc/lu": 1,
      __DIR__"npc/young": 2,
   ]) ); 
        set("outdoors","qingping");
        set("coor/x",110);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        
        replace_program(ROOM);
}      
