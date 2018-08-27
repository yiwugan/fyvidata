#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,mystr,yourstr,lvl;
        object weapon; 
       // if (me->query("class")!="tieflag")
         //       return notify_fail ("非大旗弟子不能使用［风起云涌］\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［狂蟒之徒］只能对战斗中的对手使用。\n");
        weapon = target->query_temp("weapon");
        if(!objectp(weapon)) return notify_fail("你的对手没有用兵器！\n");
        myexp = (int) me->query("combat_exp") / 1000;
        mystr = (int) me->query_str();
        if (me->query("class")=="yinshi")  mystr *= 5;
                if (me->query("class")== 0 )  mystr *= 5;
        yourexp = (int) target->query("combat_exp") / 1000;
        yourstr = (int) target->query_str();
        lvl = (int) me->query_skill("whip") / 100;
        if(lvl<1) lvl=1;
        msg = HIG "$N大喝一声，一式「狂蟒之徒」卷起大大小小的圈子，隐约之间一阵腥风传来，$n手中一痛，兵器茫然地落在地上！ \n" NOR;
     if(objectp(weapon) )
{
         if (me->query_skill_mapped("force") == "jingyiforce")
               if (( myexp * lvl * mystr) > (yourexp * yourstr) ) 
                {
                weapon->unequip();              
                weapon->move(environment(target));
                message_vision(msg, me, target);
                target->start_busy(1);
                }
                else message_vision(GRN"\n$N一式「狂蟒之徒」刚刚使出半招，却被$n看出了$N的意图，轻松跃出鞭圈之外。\n"NOR, me, target);
          else 
                if (( (myexp + random(myexp)/3) * mystr ) > (yourexp * yourstr) )
                {
                weapon->unequip();              
                weapon->move(environment(target));
                message_vision(msg, me, target);
                target->start_busy(1);
                }
                else message_vision(GRN"\n$N一式「狂蟒之徒」刚刚使出半招，却被$n看出了$N的意图，轻松跃出鞭圈之外。\n"NOR, me, target);
}
        else COMBAT_D->do_attack(target,me, TYPE_PERFORM);
        me->start_busy(2);
        return 1;
}      
