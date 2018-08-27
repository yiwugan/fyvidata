inherit ROOM;
void create()
{
        set("short", "衙门");
        set("long", @LONG
这是大理的巡捕衙门，凡大理官员都可以来这里缉拿（ｊｉｎａ）想要的疑犯。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"paifang",
]));
        set("objects", ([
//        __DIR__"npc/governor" : 1,
                        ]) );

        set("coor/x",-810);
        set("coor/y",-680);
        set("coor/z",80);
        setup();
}
void init()
{
add_action("do_jina","jina");
}
int gethim(object target,object me)
{
        if(!target || !me ) return 1;
        if(environment(me) == this_object())
        {
        message_vision("$N一句话不说，匆匆忙忙地离开了。\n",target);
        target->move(this_object());
        message_vision("$N被大理护卫押了进来。\n",target);
        if(me){
        me->kill_ob(target);
        target->kill_ob(me);
                }
        return 1;
        }
        return 1;
}
int do_jina(string arg)
{
        object me, target;
        int exp, stra,leader,factor;
        if(!arg)
        return notify_fail("你要下令缉拿谁？\n");
        me = this_player();
        if((string) me->query("class") != "dali" )
        return notify_fail("你不是大理官员，不可缉拿疑犯！\n");
        if( me->is_busy() )
                return notify_fail("（你上一个动作还没有完成，不能抓拿。） \n");
        if((int) me->query("sen") < 50 )
        return notify_fail("你的心神不够！\n"); 
        me->start_busy(4);
        me->add("sen",-50);
        if(!objectp(target = find_living(arg)))
        return notify_fail("找不到你想要的疑犯！\n");
        if( interactive(target) || !environment(target))
        return notify_fail("找不到你想要的疑犯！\n");
        if( target->query("no_arrest") )
        return notify_fail("找不到你想要的疑犯！\n");
 if( target->query("id")=="heiyi ren"&& random(this_player()->query("kar"))<30 )
        return notify_fail("找不到你想要的疑犯！\n");
          if(target->query_temp("netdead"))
        return notify_fail("警告：你不可以抓拿断线的玩家！\n");
        message_vision("$N大声下令道：来人那．．把$n给我拿来！！\n",me,target);
        exp = (int) target->query("combat_exp");
        stra = (int) me->query_skill("strategy",1);
        leader = (int) me->query_skill("leadership",1);
        factor = stra/10 * stra/10 * leader/10 * leader;
        factor = factor + (((int) me->query("combat_exp") ) - 2000 )/1000;                      
        if( random(factor) <= exp)
        return notify_fail("以你现在的能力，还不足以缉拿"+target->query("name")+"！\n");
        call_out("gethim",5,target,me);
        return 1;
}
int valid_leave(object me, string dir)
{
        if(me->is_fighting())
        return notify_fail("你现在不可离开！\n");
        return 1;
}
