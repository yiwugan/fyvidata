 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","月观峰");
  set("long",@LONG
巴掌大得峰顶上建有一个小亭子，亭子虽小，但建在这高山之上，也是不易，
日观峰的红日，月观峰的金月都是极好看的景致，每当清风之夜，月高悬其上，美
不胜收，如恰逢秋高气爽之时，持螯赏月，乘风而舞，兴之所致，实在无可比拟。
月观峰再往前行，便是天下武林英豪景仰之地——【无垢山庄】！
LONG
  );
    set("exits",([
            "down" : __DIR__"shanfeng",
        "northup" : __DIR__"yushijie3",
    ]));
    
        set("objects", ([
                __DIR__"npc/mantrainer" : 1,
        ]) );
    set("outdoors", "fengyun");
        set("coor/x",310);
        set("coor/y",2390);
    set("coor/z",125);
        setup();
        replace_program(ROOM);

} 
void init(){
    int dayTime;
    mixed *local; 
    local = NATURE_D->get_current_time();
    dayTime = local[5];
    if(NATURE_D->get_season() != 3) {
        return;
    }
    if (random(10) > 3 && (dayTime < 210 || dayTime > 1260)) {
//if(1==1) {
//      write("call_ing\n");
        call_out("falling_star", random(60), this_player());
    }     
} 
void falling_star(object me) {
    int i, age;
    
    if(environment(me) != this_object() ) {
        return;
    }
    if(me->is_fighting()) {
        return;
    }
    message("vision", HIW"\n    一道银色星光划过深蓝色的夜空，没入对面山峦的后面。 \n"NOR, me);
    message("vision", HIC"只听，惊起宿鸟一片。\n"NOR, me);
    age = me->query("age");
    if (age >= 18 && age <= 28 && !me->query("宿命A/泰山_流星")) {
        tell_object(me,HIG"\n在流星没入对面山峦前，你默默的在心中许了个愿。\n"NOR);
        me->set("宿命A/泰山_流星", 1);       
    }   
}      
