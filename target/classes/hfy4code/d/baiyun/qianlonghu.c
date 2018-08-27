 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
#include <room.h> 
void create() 
{ 
        set("short", "潜龙泉");
        set("long", @LONG 
剑林西行，蜿蜒盘亘的是一条溪流，汩汩得冒着热气，千万年前白云本为火山，
千载而下，火山不再，但地热丰富，其中夹杂着许多世人不能参晓的物质，不过白
云岛的岛民和白云城的弟子倒也经常来这条形状宛如龙盘的泉水中沐浴，时日一久
更加发觉这汩汩热流着实功用非凡。
LONG 
           ); 
        set("exits",  
           ([  
       "eastup" : __DIR__"jianlin",
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("no_fly", 1);
        set("coor/x",10); 
        set("coor/y",-1720); 
        set("coor/z",5); 
        setup(); 
//        replace_program(ROOM); 
} 
void init()
{
        add_action("do_wash", "wash"); 
} 
int do_wash()
{
        object me;
        int wait;
        me = this_player();
        me->add_temp("jumpinpool",1);
        wait = random( 5 * (int)me->query_temp("jumpinpool"));
        if ( wait <= 5) wait = 6;
        message_vision("$N噗咚地一下子跳入温泉中。\n",me);
        tell_object(me,"温暖的泉水令你感到身心通畅．．．．．．\n");
        remove_call_out("curehimup");
        call_out("curehimup", wait, me);
return 1;
} 
void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
        {
        message_vision("$N的精气神全恢复了！！！\n", me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        if(!random(10)) me->delete_temp("jumpinpool");
        }
return ;
} 