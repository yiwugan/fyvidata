#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"天下第一峰"NOR); 
        set("long", @LONG
这里便是天下第一峰——珠穆朗玛峰！！
天下群山，远方的大草原尽在脚下。白色的布达拉宫在骄阳下看来亮如纯银，但见
天蓝色的冰川，像彩缎一样，从峰顶向四面八方撒下去，镶嵌在洁白的山坡上。狂
风虽劲，冰雪骇人，但望着这大好山河，豪情在胸，壮志凌云，你顿生睥睨天下之
心，长啸连连，击掌放歌。
LONG); 
        set("type","street");
        set("exits",([
        "jump":"/daemon/class/ghost/wudang-quan/null",
        ]) );
        set("objects", ([
                __DIR__"npc/champion":1,
        ]) );
        set("outdoors", "guanwai");
        set("no_death_penalty",1);
        set("coor/x",-1280);
        set("coor/y",-110);
        set("coor/z",888); 
        setup();
        call_other( "/obj/board/hero_b", "???" );
}     
