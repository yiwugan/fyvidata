inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
一条非常宽阔的大路，是由大理城往沉香镇的官道。沿路向北
丛林愈发茂密，大片雨林覆盖山岭，此间地势较平坦，大路连接着
大理城和沉香镇。
LONG
        );
        set("exits", ([ 
  "northeast" : "/d/chenxiang/cxs1",
  "southwest" : __DIR__"qxroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-500);
        set("coor/y",-600);
        set("coor/z",0);
        setup();
        replace_program(ROOM);

}