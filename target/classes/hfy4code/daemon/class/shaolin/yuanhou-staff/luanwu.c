 // tanzhijinghun.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target) {
        
        string msg;
        int bonus, damage_bonus, damage, level, lvl;
        
        if(!objectp(target)) target = offensive_target(me);
        
        if (me->query_skill("yuanhou-staff",1)<50) 
                return notify_fail("你的「猿猴棍法」不够熟练！\n");
        
        if( !target ) target = offensive_target(me);
        if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
                return notify_fail("「群猿乱舞」只能对战斗中的对手使用。\n");
        }
        
     /*   if(target->is_busy()) {
                return notify_fail("对方已经不能动弹了。。。\n");
        }*/
        
        bonus = (int) me->query_skill("yuanhou-staff",1);
        lvl = (int) me->query_skill("staff",1);
        
                if(me->query("class")!="bonze"&&me->query("class")!="shaolin")
                bonus/=5;   
                if(me->query("class")!="bonze"&&me->query("class")!="shaolin")
                lvl/=10;   
        
        me->add_temp("apply/attack",bonus+lvl);
        me->add_temp("apply/damage",bonus*2+lvl*2);
        
        msg = HIW  "\n$N身高高跃起，身影闪动，化出五个分身，竟是一招「猿猴乱舞」！！！\n\n"NOR;
        msg+=HIC"上面劈头一击！！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   
        msg = HIC"正前方迎面一戳！！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        msg = HIC "底下又来一撩！！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       
		    msg = HIC  "左方冲着太阳穴就是一扫！！！" NOR;
		    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    
        msg = HIC  "右侧拦腰风卷而至！！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
     
        me->add_temp("apply/attack",-bonus-lvl);
        me->add_temp("apply/damage",-bonus*2-lvl*2);
 
     me->start_busy(3);
    return 1;             
}