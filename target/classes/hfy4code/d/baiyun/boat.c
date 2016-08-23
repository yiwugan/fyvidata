 //Created by justdoit at June 2001
//All Rights Reserved ^_^ 
 
#include <ansi.h> 
inherit ROOM; 
void create() 
{ 
    set("short", "一叶小舟中");
        set("long", @LONG 
一叶轻盈的小舟，可以用来航海（ｓａｉｌ）。
LONG 
           ); 
        set("no_fight",1); 
        set("no_magic",1);       
        set("coor/x",40); 
        set("coor/y",-690); 
        set("coor/z",-20); 
        setup();            
} 
 
void init() 
{ 
    add_action("do_sail","sail"); 
} 
 
void boat_sail(int counter,object me) 
{ 
    if (me->query_skill("dodge",1) < 30 )
                { 
                  message_vision(HIB"一个大浪打来，$N脚下不稳，被抛入大海之中！……\n"NOR,me); 
                  delete("counter"); 
                  me->move(__DIR__"seabutton1"); 
                  return; 
                } 
        switch (counter) 
                { 
                  case 1: 
                  message_vision(HIC"海水在脚下时而咆哮，时而低沉。时而汹涌，时而柔顺。放眼 
望去，海天相接，无边无际，一片空蒙。仿佛永远没有尽头。\n"NOR,me); 
                  break; 
                     
                  case 3: 
                  message_vision(HIC"黄昏过去，黑夜来临，前方已是茫茫黑夜。抬头望天，但见繁 
星满天，闪烁不已……但听海风咆哮，海浪翻滚。长夜将逝， 
黎明即来。太阳又要升起。\n"NOR,me); 
                  break; 
 
                  case 5: 
                  tell_object(me,HIC"黎明时分，海天之际隐约浮现一个小岛。经久方近，这小岛却 
是十分古怪，小岛白云缭绕，不见岛中风情，给人十分神秘之感。\n\n"NOR);
                  delete("counter"); 
                  tell_object(me,HIY"你拼命用力划了几下，终于到了岸边。你怀着激动的心情离开小船，踏上小岛。\n"NOR); 
          me->move(__DIR__"baiyundu");
                  break; 
                }  
        return; 
} 
 
int do_sail(string arg) 
{    
        object me; 
        me = this_player(); 
        if( !arg || (arg != "south") )  
        return notify_fail("你要往哪儿划？\n"); 
        if( arg=="south" )  
                { 
                  add("counter", 1); 
                  write("你试著把小船往南划去....\n"); 
                  call_out("boat_sail",0,(int)query("counter"),me); 
                } 
        return 1; 
} 
