 inherit ROOM;
void create()
{
        set("short", "回廊");
        set("long", @LONG
一路朱红栏杆，院子遍植花树，却已凋零，花寒依稀梦，蝉语诉秋心。这儿只
有花香，只有虫声，莫说歌声无影，连酒气都没有，和鹦鹉阁里歌舞升平的气氛大
相径庭。抬头望去，空中一排人字形的大雁飞过，雁声嘹亮，凄凉。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"garden2",
                "east": __DIR__"corridor5",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
