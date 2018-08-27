#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int extra,skill,attack,force;
        object weapon;
        if (me->query("class")!="tieflag" )
                return notify_fail ("非铁血大旗门宗亲不能使用"CYN"「削香」"NOR"绝技。\n");        
        extra = me->query_skill("sword");
        force = me->query_skill("jiayiforce",1);
			  skill = me->query_skill("xiaoxiang-sword",1);
        if ( userp(me) && (me->query_skill_mapped("force") != "cloudsforce" && me->query_skill_mapped("force") != "jiayiforce" && me->query_skill_mapped("force") != "tiexue-force"))
                return notify_fail(CYN"「削香」"NOR"绝技需要铁血大旗门的心法配合！\n");
			  if(skill < 75)
			  	    return notify_fail("你的削香剑诀等级不够！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(CYN"「削香」"NOR+"只能对战斗中的对手使用。\n"); 
        if((int)me->query("kee")*10/(int)me->query("max_kee") < 4)
                return notify_fail("你的体力不足，不能使出"CYN"「削香」"NOR+"绝技！\n");
			  if(me->query_skill("jiayiforce")>=125 && me->query_skill_mapped("force") == "jiayiforce")
			  attack = extra + skill;
              else attack = extra;
			  if(me->query_skill("jiayiforce")>=160 && me->query_skill_mapped("force") == "jiayiforce")
			  attack += force;
        weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",attack);
        me->add_temp("apply/damage",attack);
        msg = HIB  "长啸声起，$N手腕翻飞，"+ weapon->name() + HIB"竟在空中舞出无数簇剑花，朵朵剑花如有灵性般铺天盖地向$n卷去！\n"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
      	if( target->is_busy() || target->query_temp("chansi") || target->query_temp("cutkee") )
      	{
            msg =  weapon->name() + HIC +"剑芒暴长，剑花敛而合一！$N身随剑势，直刺$n要害！\n"NOR;
            msg += HIR "剑过处，一束血光随之激射而起。\n"NOR;
            me->add_temp("apply/attack",attack*3);
            me->add_temp("apply/damage",attack*3);
            COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
            me->add_temp("apply/attack", -attack*4);
            me->add_temp("apply/damage", -attack*4);
        }
        else
        {
            msg = HIY  "满天飞舞的剑花竟分别从各个刁钻的角度袭往$n，$n心神失守，竟不知如何招架！\n"NOR;
            msg += HIR "剑花消散于无形，剑光中却溅出点点血花。\n" NOR;
            me->add_temp("apply/attack",attack*3/2);
            me->add_temp("apply/damage",attack*3/2);
            COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
            me->add_temp("apply/attack", -attack*5/2);
            me->add_temp("apply/damage", -attack*5/2);
        }
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
}  
