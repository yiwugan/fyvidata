 // silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object friend)
{
        string msg;
        int skl_me, skl_you, extra_me, extra_you,i,j,k;
        object you,ob,target,*myteam; 
        target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［一指定乾坤］只能对战斗中的对手使用。\n");
        
        skl_me= me->query_skill("yiyangzhi",1);
        extra_me= me->query_skill("unarmed");
                  
//      ..........single perform 
        if (!friend) {
                msg = HIR+"$N施展出刚阳的一阳指，"+ HIY +
                "无数指影夹杂着炽热的指风，点向$n的全身！\n\n" + NOR;
                me->add_temp("apply/attack",skl_me);
                me->add_temp("apply/damage",extra_me);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-skl_me);
                me->add_temp("apply/damage",-extra_me);
                if (me->query_busy()<2) me->start_busy(2);
                return 1;
        } else 
        
//      ......... team perform        
        
        you=friend;                          
        myteam = me->query_team();
        for(j=0; j<sizeof(myteam); j++) {
                if (myteam[j]==you) 
                                {k=1; 
                                continue;
                                }
           }               
        if (k!=1)
                return notify_fail("同伴必须是与你在同一个队伍中。\n");  
        
        if(!you->query_skill("tenderzhi",1) || you->query_skill_mapped("unarmed") != "tenderzhi") 
                return notify_fail("同伴没有配合的武功。\n");
        if(objectp(ob=you->query_temp("weapon"))) 
                return notify_fail("同伴不是空手。\n");
        if (you->is_busy())
                return notify_fail("同伴正忙着呢。\n");
                        
        skl_you= you->query_skill("tenderzhi",1);
        extra_you= you ->query_skill("unarmed");
        
        msg = HIR+"$N施展出刚阳的一阳指，"+ HIG + you->name()+"施展出阴柔的柔虹指，\n"+ HIY +
        "无数指影夹杂着阴冷炽热的指风，点向$n的全身！\n\n" + NOR;
        me->add_temp("apply/attack",skl_you+skl_me*2);
        me->add_temp("apply/damage",extra_you*2+extra_me*2);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_you-skl_me*2);
        me->add_temp("apply/damage",-extra_you*2-extra_me*2);
        you->kill_ob(target);
        target->kill_ob(you);
        if (me->query_busy()<2) me->start_busy(2);
        if (you->query_busy()<2) you->start_busy(2);
        return 1;
}  
