 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        object weapon, ob; 
        if (me->query("class")!="quanli")
                return notify_fail ("［萍水相逢］只有财神庙的兄弟姐妹才能使用。\n");
        extra = me->query_skill("yuping-dagger",1); 
        if ( extra < 50) return notify_fail("你的［玉平短兵刃］还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［萍水相逢］只能对战斗中的对手使用。\n"); 
        weapon = me->query_temp("weapon"); 
		ob = target->query_temp("weapon");
        msg = HIG "$N"+HIG"横刀一立，仰天长叹：人生何处不相逢。。。\n";
		if (random(extra)>50 && me->query_skill_mapped("dodge") == "wuchen-steps" && target->query_temp("weapon") != 0
			&& (ob->query("skill_type") == "staff" || ob->query("skill_type") == "spear" || ob->query("skill_type") == "hammer" || ob->query("skill_type") == "axe"))
		{
			msg += HIR"\n$N"+HIR"脚踏无尘步，以短克长，突入$n"+HIR"的破绽！\n"NOR;
			me->add_temp("apply/attack", extra*8); 
			me->add_temp("apply/damage", extra*8); 
			me->set_temp("yuping",1);
		} 
		message_vision(msg,me,target); 
        me->add_temp("apply/attack", extra*5); 
        me->add_temp("apply/damage", extra*5); 
		msg = HIC "「萍」字诀！手中的" + weapon->name() + HIC "呼啸着如毒蛇般的向$n"+HIC"削去！" NOR;  
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIC "「水」字诀！只见"+ weapon->name()+ HIC "在空中一转，似有灵性，直指$n"+HIC"的左肩！" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIC "「相」字诀！$N"+HIC"跃起一劈，"+ weapon->name()+ HIC "火光四起，砍向$n"+HIC"的大腿！" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        msg = HIC "「逢」字诀！$N"+HIC"招式未尽已然图穷匕现，手中"+ weapon->name()+ HIC "直刺$n"+HIC"的胸口！" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
        me->add_temp("apply/attack", -extra*5); 
        me->add_temp("apply/damage", -extra*5);
		if (me->query_temp("yuping")) {
			me->add_temp("apply/attack", -extra*8); 
			me->add_temp("apply/damage", -extra*8);
			me->delete_temp("yuping");
		}

        if(me->query_busy()<3) me->start_busy(3); 
        return 1; 
} 
