#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int extra, skill, i; 
  //  if(me->query("class")!="wudang" && userp(me))
    //            return notify_fail("太极粘字诀是武当镇殿之宝。\n"); 
    skill= me->query_skill("taiji",1);
	
    if (skill < 60)
        return notify_fail("你的太极拳还不够高深！\n"); 
    
	extra = skill;
      if( me->query("class") != "wudang" ) extra/=2;
      	if (userp(me) && me->query_skill_mapped("force") == "taijiforce") extra/=2;

    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("［粘字诀］只能对战斗中的对手使用。\n"); 
        if (target->query("step_less")==1) 
                return notify_fail(HIW"此人身势灵活，功力深湛，不会被此拳法迷惑的。\n"NOR); 
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");  
    if (skill < 165) {
        msg = CYN "$N"+NOR CYN"使出太极拳法中的"+HIC"「粘」"+NOR CYN"字诀，企图减缓$n"+NOR CYN"的攻势，";
        me->start_busy(1);
        if( random(me->query("combat_exp")*2/3) > (int)target->query("combat_exp")/2) {
            msg += "结果$p"+NOR CYN"被$P"+NOR CYN"攻了个措手不及！\n" NOR;
            target->start_busy( 2 + random(1)); //最多busy 3，最低busy 2
        }
        else {
            msg += "可是$p"+NOR CYN"看破了$P"+NOR CYN"的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
    }
    else {
        msg = HIR "$N"+HIR"真气鼓动，双拳幻化为无数大大小小的圆圈向$n"+HIR"攻去，";
	  if( me->query("class") != "wudang" ) i = 2;
		else i = 5;  //不是武当弟子嘛，哼哼，效果差一截
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/i
 ) {
            msg += "结果$p"+HIR"头晕目眩，被$P"+HIR"的拳势围住不能脱身，频频中招！\n" NOR;
            target->start_busy(3);
            me->start_busy(random(2));
            target->receive_damage("kee",((int) me->query("force_factor")*random(extra)/3),me);
            message_vision(msg, me, target);
            target->set_temp("damaged_during_attack", 1);
            COMBAT_D->report_status(target, 0);
            COMBAT_D->win_lose_check(me,target,1);
        }
        else {
            msg += "可是$p"+HIR"从容应招，将$P"+HIR"的攻势消于无形。\n" NOR;
            me->start_busy(random(2));
            message_vision(msg, me, target);
        } 
        return 1;
    }
}   
