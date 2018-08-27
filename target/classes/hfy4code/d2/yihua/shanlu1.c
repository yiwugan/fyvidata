inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
这条山路盘嵩山主峰而上，山路贴着石璧凿出，只容一人可过，
形势极为险峻。往远处望去。群山环绕，列於脚下，百里美景尽收眼
底，顿时令人豪气陡声，想要长啸一声。往南下是一片空地。往北上
就是移花小径。
LONG
        );
        set("outdoors", "yihua");
        set("exits", ([
                "southdown" : "/d/songshan/junji",
                "northup"   : __DIR__"shanlu2",
        ]));
        set("coor/x",-180);
	set("coor/y",160);
	set("coor/z",20);
        setup();
        replace_program(ROOM);
}
