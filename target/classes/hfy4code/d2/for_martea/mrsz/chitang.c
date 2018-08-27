 inherit ROOM;
void create()
{
        set("short", "池塘");
        set("long", @LONG
后花园有一小小的池塘，池塘里的水碧绿清澈，上面有几朵盛开的睡莲，粉红，
洁白，鹅黄，衬托着碧绿的叶子，漂浮在小池塘上，煞是惹人喜爱。透过睡莲的缝
隙隐约可见几尾红色金鲤在水中悠闲地缓缓游动。池塘的两侧分别建有凉亭、假山，
给这宁静的池塘带来无限生机。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"jiashan",
        "south" : __DIR__"houhuayuan2",
        "west" : __DIR__"liangting",
        "north" : __DIR__"houhuayuan1",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
