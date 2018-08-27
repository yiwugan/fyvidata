 // mietiandao.c 灭天刀
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,skill,i,n;
        object weapon;
        if (me->query("class")!="bat")
                return notify_fail("非蝙蝠岛弟子不能使用绝技·"RED"［灭天刀］"NOR+"！\n");
        if ( (string) me->query_skill_mapped("dodge") != "meng-steps")
                return notify_fail("绝技·"RED+"［灭天刀］"NOR+"需要和［幻梦步法］配合才能施展！\n");
        skill = me->query_skill("bat-blade",1);
        extra = me->query_skill("blade");
		i = skill/50;
        if (skill < 150) return notify_fail("你的［蝙蝠刀法］还不够纯熟！\n");
        if ( me->query_skill("meng-steps",1) < 150)  return notify_fail("你的［幻梦步法］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("绝技·"RED+"［灭天刀］"NOR+"只能对战斗中的对手使用。\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("你的真气不够，不足以施展此招。\n");
        if(userp(me) && me->query_temp("timer/shiwanshenmo") + i < time() )
                return notify_fail("绝技·"RED+"［灭天刀］"NOR+"只能从［十万神魔］一式中变化而来！\n");
				else if(me->query_busy() < 2) {
		        message_vision(HIW "\n$N强运内功，原本滞涩的身形竟又轻巧起来！\n" NOR, me);				
				me->stop_busy();
		        me->add("force", -500);
				}
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        msg = HIB  "\n$N一式［十万神魔］刚刚使尽，刀招在这一瞬间突然又有了新的变化！\n"HIY"$N突然一步踏出，手中的长刀凭空划出无数道圆弧，刀光封住了$n的头脸，令$n睁眼如盲！"NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		if(random(skill/40) > 2)
		{
        message_vision(HIW "\n$N突然化作重重幻影向四面八方游走，$n心神失守下竟完全不能闪避！\n" NOR, me ,target);
        if (target->query_busy()<3) 
                target->start_busy(3);
		}
		if( n < 200)
		n = random(skill/60);
		else n = random(skill/50);
		msg = HIR "$N身形闪现，直切入$n身法破绽之中，手中$w"HIR"如青云漩下般斩落！" NOR;
        me->add_temp("apply/attack",extra*n);
        me->add_temp("apply/damage",extra*n);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra*n);
        me->add_temp("apply/damage",-extra*n);

		msg = HIC "$N身随意动，刀势化开，$w"HIC"若九天流云坠地，气势磅礴如一去三千里般攻向$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}