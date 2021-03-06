inherit ROOM;

void create()
{
        set("short", "段家铁铺");
        set("long", @LONG
大理城的人都喜欢在这里打造称手的铁器，从火炉中冒出的火光将墙
壁映得通红，屋子的角落里堆满了各式铁器的完成品或未完成品，像是锄
头、铁锤、铲子、长剑等，叮叮当当的声音敲得满屋子响。
门口有一个大木牌（ｓｉｇｎ）．
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wroad2",
]));

        set("outdoors", "dali");
        set("objects", ([
                "/d/dali/npc/smith": 1 ]) );
        set("item_desc", ([
                "sign": @TEXT

目前我们可订作（ding）：

铁斧（axe），单刀（blade），匕首（dagger），
钢叉（fork），铁锤（hammer），
禅杖（staff），铁剑（sword），铁鞭（whip）
长矛（spear），板指（banzhi）
每件十两黄金．

例子：
ding blade $HIY$ 屠龙刀 tulongblade tie

段铁匠就会用你带来的铁料帮你作一把黄色的＂屠龙刀＂ 叫 tulongblade.

$BLK$ - 黑色            $NOR$ - 恢复正常颜色
$RED$ - 红色            $HIR$ - 亮红色
$GRN$ - 绿色            $HIG$ - 亮绿色
$YEL$ - 土黄色          $HIY$ - 黄色
$BLU$ - 深蓝色          $HIB$ - 蓝色
$MAG$ - 浅紫色          $HIM$ - 粉红色
$CYN$ - 蓝绿色          $HIC$ - 天青色
$WHT$ - 浅灰色          $HIW$ - 白色

TEXT
        ]) );

        set("coor/x",-880);
        set("coor/y",-760);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}