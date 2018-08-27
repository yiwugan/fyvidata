 //neon@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, myexp, enemyexp, lvl;
        object weapon; 
     //   if(me->query("class")!="beggar" && userp(me))
       //         return notify_fail("［绊字诀］只传授给丐帮弟子！\n");
        
        if((int)me->query_skill("72-panguan",1) < 50)
                return notify_fail("你的七十二路判官笔还不够熟练！\n");       
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［点穴］只能对战斗中的对手使用。\n"); 
        weapon = me->query_temp("weapon");
        
        lvl = (int) me->query_skill("72-panguan",1);
        if (me->query("force")<lvl/2+10)        
                return notify_fail("你的内力不够。\n");
        
        lvl = lvl /100;
        if (lvl >= 9) lvl =9;
        
        extra = me->query_skill("dagger");
         if (me->query("class")== 0 )extra = extra*3;
         if (me->query("class")> 0 ) lvl = lvl/3;
         
        myexp = (int) me->query("combat_exp");
       // if (me->query("class")=="yinshi") myexp = myexp*3/2;
        enemyexp= (int) target->query("combat_exp");
        
        msg = HIY"\n说时迟那时快，$N"+HIY"左手并指，右手"+ weapon->name() + HIY"反手点出，分别虚点$n"+HIY"肩井和膻中二穴！\n" NOR;
        
        if (target->query("disable_type")&& target->query("is_unconcious")) {
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                return 1;
        }
        else message_vision(msg,me,target); 
        if (myexp/3 + random(myexp/80*extra) > enemyexp) {
                msg = YEL"一时防备不切，"+ weapon->name() + YEL"已刺中$n"+YEL"穴道，$n"+YEL"顿时身形一滞，被连环击中，节节退后！\n"NOR;
                  
                        me->start_busy(lvl);

                target->start_busy(lvl+1);
                target->receive_wound("kee", extra+random(extra*3), me);
              
                message_vision(msg,me,target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
                        
        }
        else {
                me->add_temp("apply/attack", extra/2);
                me->add_temp("apply/damage", extra/2);
                msg = YEL"$n似乎已经有防范，身形乱闪，避开身前要穴，$N只好顺势改点为刺，全力一击！"NOR;

                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

                me->add_temp("apply/attack", -extra/2);
                me->add_temp("apply/damage", -extra/2);
                me->start_busy(2);
        }
        return 1;
} 
   
