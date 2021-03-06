#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra, blade,myexp,tarexp;
//        if (me->query("class")!="emei")
//                return notify_fail ("只有峨嵋弟子才能使用［刀剑双杀］。\n");
        extra = me->query_skill("sky-sword",1);
        blade = me->query_skill("shenji-blade",1);
//                if (me->query("class")=="emei") extra*=3;
        if ( extra < 150) 
                return notify_fail("你的［蓝天剑法］还不够纯熟！\n");
        if ( blade < 150) 
                return notify_fail("你的［神机刀法］还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("blade");
        if ( dodskill != "shenji-blade")
                return notify_fail("［刀剑双杀］需要神机刀法和蓝天剑法的配合！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［刀剑双杀］只能对战斗中的对手使用。\n");
        
	if (me->query("class")=="emei") blade*=2;
        if (me->query("class")!="emei") blade/=2;
        if (me->query("class")=="emei") extra*=3;
        myexp=(int)me->query("combat_exp");
        tarexp=(int)target->query("combat_exp");
        msg = HIR"$N手中刀剑挥舞，突然使出一招『刀剑双杀』！\n"+NOR;
        if(random((extra+blade)/50)*myexp + random(myexp/2) >= tarexp*2/3)
        {
//        	me->add_temp("apply/attack",blade*4);
//        	me->add_temp("apply/damage",extra*4);     
        	message_vision(msg+"\n",me,target);
        	if( target->is_busy() ){       //如果对方正busy，那么不必要busy对方了
        		me->add_temp("apply/damage",extra*4);
        		me->add_temp("apply/attack",blade*4);
        		message_vision( BLU " 森森杀气突然向$N扑来，"NOR+HIC"刀"+HIB"即"+HIM"是"+HIW"剑"+NOR"，"+CYN"剑"+GRN"即"+MAG"是"+RED"刀"+HIY"！" NOR,target);
        		msg= HIC"一瞬间，刀光剑影连绵不断。"NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        		target->receive_wound("sen",extra);
        		me->add_temp("apply/damage",-extra*4);    
        		me->add_temp("apply/attack",-blade*4);
        	}else{
        		me->add_temp("apply/damage",extra*3);
        		me->add_temp("apply/attack",blade*4);
        		message_vision( BLU " $N只见眼前刀剑变幻不断，一下子不知所措！\n"+NOR"周围突然杀气重重，"+HIC"刀"+HIB"即"+HIM"是"+HIW"剑"+NOR"，"+CYN"剑"+GRN"即"+MAG"是"+RED"刀"+HIY"！" NOR,target);
        		msg=HIC"一瞬间，刀光剑影连绵不断。"NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        		target->receive_wound("sen",extra/2);
        		me->add_temp("apply/damage",-extra*3);    
        		me->add_temp("apply/attack",-blade*4);
        		target->start_busy(2);
        	}
        }else{
           msg= HIR  "$N手中刀剑挥舞，突然使出一招『刀剑双杀』！\n\n"+NOR"周围突然杀气杀气重重，"+HIC"刀"+HIB"即"+HIM"是"+HIW"剑"+NOR"，"+CYN"剑"+GRN"即"+MAG"是"+RED"刀"+HIY"！" NOR;
           COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        target->set_temp("last_damage_from",me);
        me->start_busy(2);
        return 1;
}     
