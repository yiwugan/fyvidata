 inherit ROOM;
void create()
{
        set("short", "卧室");
        set("long", @LONG
这间睡房十分宽敞，想来便是庄主的休息所在了。屋子里的光线很暗，满屋子
弥漫着一种醉人的香气。一张宽大柔软的床上铺着被褥，让人不觉昏昏欲睡。床头
一侧挂着一幅女子的画像，想必这便是已故的庄主夫人了。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"zhengtang",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}       
