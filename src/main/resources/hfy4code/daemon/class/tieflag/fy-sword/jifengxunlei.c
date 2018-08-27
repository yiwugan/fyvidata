#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,skill;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("fy-sword", 1);
        skill = extra;
        if ( userp(me) && (me->query_skill_mapped("force") != "cloudsforce" && me->query_skill_mapped("force") != "jiayiforce" && me->query_skill_mapped("force") != "tiexue-force"))
                return notify_fail("［疾风迅雷］需要铁血大旗门的心法配合！\n");
        if ( extra < 50) return notify_fail("你的大旗风云剑还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［疾风迅雷］只能对战斗中的对手使用。\n");
        i = extra/40+random(extra/60);
        if(i<4)i=4;
        if(me->query_skill_mapped("force") == "jiayiforce" && me->query_skill("jiayiforce", 1) >= 100)
         extra*=5/3;


        msg = HIR  "$N长剑一展，突然使出大旗风云剑的绝招［疾风迅雷］，道道剑芒如流星赶月般攻往$n！\n" NOR;
        message_vision(msg,me,target);
        if(skill>=120)
        {
        msg = YEL"无数道纵横交错的异色剑芒直往$n的$l袭去！" NOR;
	  extra*=3/2;
        }
        else
        {
        msg = WHT"一丝丝若有若无的剑芒刺往$n的$l！" NOR;
        }        
        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);
        while(i>0)
        {
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        i--;
        }
        if(me->query_temp("tiexue"))
        {
        me->add_temp("apply/damage",extra*5);
        me->add_temp("apply/attack",extra*5);
        if(skill>=120) msg = YEL"$N大喝一声，手中长剑化作一道闪电，迅捷无比地刺往$n的$l！" NOR;
        else msg = WHT"$N急步上前，剑如轮转般击往$n的$l" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*6);
        me->add_temp("apply/attack",-extra*6);
        }
        else
        {
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);
        }
        if ( me->query_busy()<3 ) me->start_busy(3);
        return 1;
}    
