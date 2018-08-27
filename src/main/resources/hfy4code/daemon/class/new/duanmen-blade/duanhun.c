#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg,weapon_name;
        int extra,skill,kee,dam;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［断魂］只能对战斗中的对手使用。\n");
        extra = me->query_skill("blade")*2/3;
        skill = me->query_skill("duanmen-blade",1);
        if ( me->query_skill("duanmen-blade",1) < 80 && userp(me)) 
        return notify_fail("你的五虎断门刀不够纯熟。\n");
        if ( skill <= 125) 
		extra = extra*3/4;
        if ( extra >= 300 ) 
		extra = 300;
		    if ( !me->query("marks/彭家复仇")) extra = extra/6;
        weapon=me->query_temp("weapon");
        weapon_name = weapon->query("name");
        message_vision(HIR "$N缓缓地把"NOR+weapon_name+HIR"举至胸前，刀锋遥指$n，刀上散出的摄人杀气把$n牢牢锁定！\n\n"+NOR, me,target);

        if( !me->query("class"))
        {
                kee = target->query("kee");
                msg = HIW "$N"+HIW"真劲灌注，一刀挥出！\n一股凛烈无匹的罡气直袭$n！\n" NOR;
                me->add_temp("apply/damage",extra*3);
                me->add_temp("apply/attack",extra);
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                me->add_temp("apply/damage",- extra*3);
                me->add_temp("apply/attack",- extra);

                if( (int)target->query("kee") < kee )
                { 
				             message_vision(HIY "气机牵引之下，$n竟无法躲避，被刀气硬硬逼退三步！$N人刀合一，直冲上前－－刀刀不离$n要害！\n\n"+NOR, me,target);        
				             me->add_temp("apply/attack", extra*3);
				             me->add_temp("apply/damage", extra*4);
				             msg = HIG "「断魂！」" NOR;
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             msg = HIM "「碎梦！」" NOR;
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             msg = HIB "「绝命！」" NOR;
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             me->add_temp("apply/attack", extra*3);
				             me->add_temp("apply/damage", extra*2);
				             msg = HIR "「斩尽杀绝！」" NOR;
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             me->add_temp("apply/attack", -extra*6);
				             me->add_temp("apply/damage", -extra*6);
				             if(me->query_busy()<3) me->start_busy(3); 
				        }
				        else
				        {
				             message_vision(HIC "$n身形一转，堪堪避过迎面而来的刀气，$N一招失利，人随刀走，狠狠地直劈$n要害！\n"+NOR, me,target);        
				             me->add_temp("apply/attack", extra*3);
				             me->add_temp("apply/damage", extra*3);
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM);
				             me->add_temp("apply/attack", -extra*3);
				             me->add_temp("apply/damage", -extra*3);
				             if(me->query_busy()<3) me->start_busy(random(1)+1);
             		}
                return 1;
        }//这里是没有class 
        else 
        if(me->query("class") == "ghost"||me->query("class") == "wolf"||me->query("class") == "bonze"||me->query("class") == "lama"||me->query("class") == "taoist"||me->query("class") == "wudang"||me->query("class") == "shenshui")
        {
	             msg = HIB "$N"+HIB"反手持刀，身法展动，同时幻出数个身影直往$n攻去" NOR;
	             me->add_temp("apply/attack", extra*2);
	             me->add_temp("apply/damage", extra*2);
	             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	             me->add_temp("apply/attack", -extra*2);
	             me->add_temp("apply/damage", -extra*2);
	             msg = HIM "$N"+HIM"状若疯魔，把手中的"NOR+weapon_name+HIM"舞出满天霞光，铺天盖地地往$n袭去" NOR;
	             me->add_temp("apply/attack", extra*2);
	             me->add_temp("apply/damage", extra*3);
	             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	             me->add_temp("apply/attack", -extra*2);
	             me->add_temp("apply/damage", -extra*3);
        }//这里也是计算class 1
        else if(me->query("class") == "bandit"||me->query("class") == "bat"||me->query("class") == "emei")
        {
	             msg = YEL "$N"+YEL"暴喝一声，手中的"NOR+weapon_name+YEL"在空中划出一道优美的弧线直削$n" NOR;
	             me->add_temp("apply/attack", extra*3);
	             me->add_temp("apply/damage", extra*3);
	             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	             me->add_temp("apply/attack", -extra*3);
	             me->add_temp("apply/damage", -extra*3);
				        if( me->query_skill("moon-blade",1) >= 100||me->query_skill("bat-blade",1) >= 150||me->query_skill("shenji-blade",1) >= 160)
				        {
				             msg = BLU "$N"+BLU"宝刀破空，凭空舞出无数刀花，$n心神失守之下竟无法招架" NOR;
				             me->add_temp("apply/attack", extra*2);
				             me->add_temp("apply/damage", extra*2);
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             me->add_temp("apply/attack", -extra*2);
				             me->add_temp("apply/damage", -extra*2);
				             target->receive_damage("sen", extra*2+random(extra), me);
				        }        
        }//这里也是计算class 2
        else if(me->query("class") == "legend" ||me->query("class") == "huangshan")
        {
        			 msg = HIY "$N"+HIY"心神守一，"NOR+weapon_name+HIY"平平无奇地从上往下直劈$n" NOR;
	             me->add_temp("apply/attack", extra*2);
	             me->add_temp("apply/damage", extra*2);
	             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	             me->add_temp("apply/attack", -extra*2);
	             me->add_temp("apply/damage", -extra*2);
				      if( me->query_skill("shortsong-blade",1) >= 120||me->query_skill("qiusheng-blade",1) >= 120)
				      {
				           msg = HIG "$N"+HIG"左掌挥出，右手持刀横劈$n" NOR;
				           me->add_temp("apply/attack", extra*3);
				           me->add_temp("apply/damage", extra*2);
				           COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				           me->add_temp("apply/attack", -extra*3);
				           me->add_temp("apply/damage", -extra*2);
				      }        
			        if( me->query_skill("shortsong-blade",1) >= 180||me->query_skill("qiusheng-blade",1) >= 180)
			        {
			             msg = HIC "$N"+HIC"如闲庭信步般，施施然切入$n空门，刀光如流云般洒向$n" NOR;
			             me->add_temp("apply/attack", extra*2);
			             me->add_temp("apply/damage", extra*3);
			             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
			             me->add_temp("apply/attack", -extra*2);
			             me->add_temp("apply/damage", -extra*3);
			        }        
        }//这里也是计算class 3
        else
        {
             msg = HIY "$N"+HIY"低叹一声，"NOR+weapon_name+HIY"隐含风雷之音直劈$n" NOR;
             me->add_temp("apply/attack", extra);
             me->add_temp("apply/damage", extra);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             msg = HIW "$N"+HIW"紧闭双目，双手持刀横砍$n" NOR;
             me->add_temp("apply/attack", extra*2);
             me->add_temp("apply/damage", extra);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -extra*3);
             me->add_temp("apply/damage", -extra*2);
             msg = HIG "$N"+HIG"刀光霍霍，反手一刀把$n的退路全部封死" NOR;
             me->add_temp("apply/attack", extra*2);
             me->add_temp("apply/damage", extra*2);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -extra*2);
             me->add_temp("apply/damage", -extra*2);
        }//class计算结束 4
        if( me->query_skill("wind-blade",1) >= 220)
        {
        if(( me->query_skill("springrain-blade",1) >= 160)&&( me->query_skill("tang-blade",1) >= 180))
            dam=extra*2;
            else dam=extra*3/2;
             msg = MAG "$N"+MAG"刀锋微颤，道道刀气如旋风般直割$n" NOR;
             me->add_temp("apply/attack", dam);
             me->add_temp("apply/damage", dam);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -dam);
             me->add_temp("apply/damage", -dam);
        }
        if( me->query_skill("xiruo-blade",1) >= 200)
        {
        if(( me->query_skill("springrain-blade",1) >= 160)&&( me->query_skill("tang-blade",1) >= 180))
            dam=extra*3/2;
            else dam=extra;
             msg = CYN "$N"+CYN"持刀向前，刀光如闪电般砍往$n" NOR;
             me->add_temp("apply/attack", dam);
             me->add_temp("apply/damage", dam);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -dam);
             me->add_temp("apply/damage", -dam);
        }
        if( me->query_skill("ittouryu",1) >= 160)
        {
        if(( me->query_skill("springrain-blade",1) >= 160)&&( me->query_skill("tang-blade",1) >= 180))
            extra*=2;
             msg = RED "$N"+RED"目色尽赤，突然尽力一刀挥向$n" NOR;
             me->add_temp("apply/attack", extra*3/2);
             me->add_temp("apply/damage", extra*3/2);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -extra*3/2);
             me->add_temp("apply/damage", -extra*3/2);
        }
             if(me->query_busy()<3) me->start_busy(3);
        return 1;
}  
