 // drift_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
//      if (me->query("class")!="ninja")
//              return notify_fail("只有忍者才能用忍术.\n");
                
//      if((int) me->query_skill("ninjitsu",1) < 150)
//                return notify_fail("你的忍术不够高深！\n");
        if(environment(me)->query("no_death_penalty"))
                return notify_fail("你无法在这里使用飞镖。\n");
        if( me->query_temp("ninjitsu_dart"))
                return notify_fail("你正在狙击之中，不可分心。。\n");
        if( me->query("atman") < 200 )
                return notify_fail("你的灵力不够！\n");
         if( me->query("gin") <= 100 )
                return notify_fail("你的精不够！\n"); 
        write("你要狙杀谁？");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
} 
void select_target(object me, string name)
{
        object ob,room,here;
        int lvl,extra,delay,dis,x,y,z;
        int my_exp, your_exp, your_perp, my_skill;
        
        if( !name || name=="" ) {
                write("终止狙击。\n");
                return;
        } 
        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if ( !ob) 
                {
                tell_object(me,"你要狙击的对象不存在。\n");
                return;
                }
   if( me->query("atman") < 200 ) {
                write("你的灵力不够！\n");
                return;
        } 
        my_exp=me->query("combat_exp");
        your_exp=ob->query("combat_exp");
        
        if ( my_exp>your_exp*5) {
                tell_object (me,"对付这么差劲的对手用暗杀太失忍者身份!\n");
                return;
        }
        me->add("atman", -200);
        me->receive_damage("gin", 100);
        
        lvl=me->query_skill("magic");
        extra=lvl*lvl/460*lvl/100;
        if (me->query("class")=="shaolin")  extra = extra *5/2;
        extra=extra+random(extra);
        delay=50-lvl/10;
        if(delay<0) delay=0;
        if (delay>10) delay=10;
        delay=delay+random(delay);
        
    message_vision( HIY "$N闭目凝神，似乎在计算着什么。。\n" NOR, me);
        room=environment(ob);
        if(!room||room->query("no_magic")||room->query("no_fight")) 
        {       
                tell_object(me,HIB"你无法确定敌人的位置。\n"NOR);
                return;
        }
                
        here=environment(me);
        x=room->query("coor/x")-here->query("coor/x");
        y=room->query("coor/y")-here->query("coor/y");
        z=room->query("coor/z")-here->query("coor/z");
        dis=x*x+y*y+z*z;
        if(dis>lvl*lvl/2)
        {
        tell_object(me,HIB"依你此时的功力，还无法狙击如此遥远的敌人。\n"NOR);
                return;
        }
   me->set_temp("ninjitsu_dart",1);        
        call_out("throwing",delay,me,ob,room,extra);
        me->start_busy(delay);
        
        my_skill=me->query_skill("ninjitsu",1)+1;
        your_perp=ob->query_skill("perception",1)+1;
        
        if (random(your_exp*your_perp)>random(my_exp*my_skill)) 
                tell_object(ob,HIW"你心念一动，只觉一股无形的杀气袭来。\n"NOR);
                
        return ;
} 
int throwing(object me, object ob, object room,int extra)
{       
        string msg;
        int my_exp,your_exp,your_perp, my_skill;
        me->delete_temp("ninjitsu_dart");
        if(userp(ob))
                me->start_busy(10+random(10));
        else
                me->start_busy(3);
    message_vision(HIR"$N微睁双目低喝一声，袍袖轻拂，一枚飞镖顿如流星闪电般划过长空。。。\n"NOR,me);
        
        my_exp=me->query("combat_exp");
        my_skill=me->query_skill("ninjitsu",1)+1;
        your_exp=ob->query("combat_exp");
        your_perp=ob->query_skill("perception",1);
        
        if(present(ob,room))
        {
        message_vision(HIR"$N眼前一花，一枚飞镖竟已呼啸而至！！\n"NOR,ob);
        if(userp(ob))
                ob->delete_temp("been_darted");
                if (random(your_exp*your_perp)>random(my_exp*my_skill*2)
                        || ob->query_temp("been_darted")+300>time())
                {
                        message_vision(HIG"$N似乎早有准备,两指一摒,啪地将飞镖夹住.\n"NOR,ob);
                        msg=TASK_D->locate_obj(ob,me->query("id"));
                        tell_object(ob,"根据飞镖的来势，你判断出，袭击你的"+msg+"。\n");                
                        tell_object(me,"不好,你的飞镖被对方破了。\n");
                   return 1;
                }
                        
                ob->set_temp("damaged_during_attack",1);
                COMBAT_D->report_status(ob);
                msg=TASK_D->locate_obj(ob,me->query("id"));
                tell_object(ob,"根据飞镖的来势，你判断出，袭击你的"+msg+"。\n");                
                tell_object(me,"看来你的狙击成功了。\n");
                ob->receive_wound("kee",extra/2);
                ob->receive_damage("kee",extra/2);
                ob->set_temp("last_damage_from",me);
                ob->set_temp("been_darted",time());
                return 1;
        }
    message("vision",HIW"一枚飞镖吧嗒一声掉在你面前。\n"NOR,room);
    tell_object(me,"非常遗憾，你的狙击无功而返。。。\n");
        return 1;
}
        
           
