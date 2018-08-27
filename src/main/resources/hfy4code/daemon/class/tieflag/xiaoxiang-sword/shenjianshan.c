//ximen@sxfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
void remove_effect(object target);
int perform(object me, object target)
{
        string msg;
        int extra,skill,attack,armor,iron_cloth,force,cut,cooldown,kee;
//        object weapon;
		  
        if( me->query("class")!="tieflag" ) 
                return notify_fail ("非铁血大旗门宗亲不能使用绝技·"HIW+"「神剑闪」"NOR"绝技。\n");
        if( me->query("family/master_id") !="master tie" && me->query("combat_exp") < 10000000 )
              return notify_fail("绝技·"HIW+"「神剑闪」"NOR+"只有铁中棠亲传弟子才能使用。\n"); 
        force = me->query_skill("jiayiforce",1);
        cooldown = 200 - force;
        if( cooldown <= 0) cooldown = 0;
        extra = me->query_skill("sword");
        skill = me->query_skill("xiaoxiang-sword",1);


        if (  me->query_temp("timer/shenjian") + 60 + cooldown>time())
              return notify_fail("绝技·"HIW+"「神剑闪」"NOR+"不能连续使用。\n"); 
        if( me->query("force") < 500 )
                return notify_fail("你的内力不够。\n");

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() ||  !me->is_fighting(target) )
              return notify_fail("绝技·"HIW+"「神剑闪」"NOR+"只能对战斗中的对手使用。\n"); 

        iron_cloth = target->query_skill("iron-cloth",1);
        armor = target->query("resistance/kee");
        if( me->query_skill("xiaoxiang-sword",1)<180)
              return notify_fail("你尚未有足够的能力施展绝技·"HIW+"「神剑闪」"NOR+"。\n"); 
//        weapon = me->query_temp("weapon");
        msg = HIB  "\n$N神情肃穆，缓缓地向$n刺出一剑，剑的去势很慢，慢得不合常理。\n"NOR;
        message_vision(msg, me, target);
        msg = HIB  "然而在$n眼中，这不合常理的一剑，竟是无可匹敌的杀招！$N的剑气更如同飞砂漫空般无处不在，把$n能活动的空间紧锁起来！\n\n"NOR;
        message_vision(msg, me, target);

        if( me->query_skill_mapped("force") != "jiayiforce") extra*=1/7;
        me->add("force", -500);
        if( !target->query_temp("cutkee") && armor > 0 && me->query_skill_mapped("force") == "jiayiforce")
        {
        cut = armor*force/200;
	  if(cut >= armor)
		cut = armor;
        message_vision(RED"灼热的剑气如游蛇般侵穴入脉，$n体内血气翻腾，难受得差点吐血！\n"NOR,me,target);
        target->set_temp("resistance/kee",-cut);//不可以为负数
        target->set_temp("cutkee",1);
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), force/15);
        }
        msg = HIC  "天地在这一刹那间仿佛静止不前——$N那缓慢的一剑在弹指间化作闪电，直往$n击去！\n"NOR;
        message_vision(msg, me, target);
        msg = WHT  "\n$N用嘶哑的，仿佛不属于自己的声音低吟道：\n"NOR;
        message_vision(msg, me, target);
        msg = HIG"「神·剑·闪·兮·山·河·动！」"NOR;
        me->add_temp("apply/attack",extra*5);
        me->add_temp("apply/damage",extra*7);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY"「天·地·变·兮·风·云·乱！」"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        if(iron_cloth > 0)
        {
        message_vision(YEL"\n有若实质的剑气如繁星飞坠，刺破$n的护体神功透体而入！\n"NOR,me,target);
	  if( me->query_skill("jiayiforce",1) < 180 )
	  skill*=1/2;
        target->receive_damage("kee", skill*iron_cloth/5, me);
        }
        me->add_temp("apply/attack",-extra*5);
        me->add_temp("apply/damage",-extra*7);
        me->set_temp("timer/shenjian",time());
        me->start_busy(3); 
        target->set_temp("damaged_during_attack", 1);
        COMBAT_D->report_status(target, 0);
        COMBAT_D->win_lose_check(me,target,1);
        return 1;
}  

void remove_effect(object target)
{
	if( !objectp(target) ) return;
	target->delete_temp("resistance/kee");
	target->delete_temp("cutkee");
    message_vision(HIG"\n$N猛提一口真气，好不容易才把入侵经脉的灼热剑气尽数化去。\n"NOR,target);
} 