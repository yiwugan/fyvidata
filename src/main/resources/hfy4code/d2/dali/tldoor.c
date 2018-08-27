// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "天龙寺山门");
        set("long", @LONG
不太高大的门楼，门额上悬着一块金字的黑漆方匾：

                     天龙寺

LONG
        );
        set("exits", ([ 
  "west"   : __DIR__"dadian",
  "eastdown" : __DIR__"tlroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-950);
        set("coor/y",-800);
        set("coor/z",150);
        setup();
}

int valid_leave(object me, string dir)
{
if(me->query("m_success/无量洞")&&me->query("m_success/金瓶梅")) return 1;
if(wizardp(me)) return 1;
if(!((me->query("family/family_name") == "大理") ||(me->query("family/family_name")=="朝廷"))&& dir == "west")
{message_vision("一股大力将$N推了回来，
一个苍老的声音说道：此乃大理国寺，闲杂人等不得入内！！\n",me);
return notify_fail("");}
if(!(me->query("title")=="大理王爷" || me->query("title")=="天龙寺高僧") && dir == "west")
{message_vision("一股大力将$N推了回来，
一个苍老的声音说道：你的爵位还不够，等当了王爷再来吧。\n",me);
return notify_fail("");}
 return 1;
}