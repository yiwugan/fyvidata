 inherit ROOM;
void create()
{
        set("short", "盘龙阁");
        set("long", @LONG
这里便是山庄子龙大少爷的住所。房间正中是块千年古玉雕成的祥龙，玉龙活
灵活现，穿梭于祥云之中。龙嘴中含玉球，玉球有拳头大小，翠绿欲滴。房间正面
的墙上挂一宝刀，只见刀鞘上刻着一金龙，栩栩如生，刀未出鞘，你便感觉阵阵寒
意，此刀乃庄主隐退江湖后传与其长子子龙少爷的兵刃。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"changlang2",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
