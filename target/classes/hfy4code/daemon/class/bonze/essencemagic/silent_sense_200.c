 // void_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
    int lvl;
    
//      if(me->query("class")!="bonze")
//              return notify_fail("只有兴国禅寺的弟子才可以使用寂识神通！\n"); 
    lvl = (int) me->query_skill("essencemagic",1);
    if  (lvl<30) 
        return notify_fail("你八识神通的修为不够，无法使用寂识神通。\n");
    
    if (me->is_fighting())
        return notify_fail("寂识神通不能在战斗中使用。\n");
        
    if (me->query("class")!="bonze")
    if (me->query("timer/silent"))
    if (lvl<me->query("timer/silent_level")) {
        me->set("timer/silent",1);
        return notify_fail("你需要继续修炼八识神通才能使用寂识神通。\n");
        } 
    if(target) 
        return notify_fail("寂识神通只能对自己使用。\n");
    if( me->query("atman") < 100 )
        return notify_fail("你的灵力不够！\n");
    if( me->query("gin") <= 50 )
        return notify_fail("你的精力不够！\n");
    me->add("atman", -100);
    me->receive_damage("gin", 50);
    
    message_vision(HIY "$N盘膝而座，开始运用寂识神通静思入定 ...\n" NOR, me);
    
    if(random(me->query_skill("essencemagic",1))+14< me->query_skill("essencemagic",1) && !me->is_fighting())
    {
        tell_object(me,HIW"你的周围一片寂静，你感觉身体不断的下沉。\n"NOR);
        me->move("/d/death/yanluo");
        me->be_ghost(1);
        me->start_busy(5);
        return 1;
    }
    write("可是什么事情都没有发生。\n");
    
    if (me->query("class")!="bonze") me->add("timer/silent",1);
    if (me->query("class")!="bonze" && me->query("timer/silent")>200){
        tell_object(me,HIR"你既非禅门弟子，八识神通就该勤加练习才能继续使用。\n"NOR);
        me->set("timer/silent_level",lvl+1);
        }
    return 1;
}   
