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
                return notify_fail("��һָ��Ǭ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        skl_me= me->query_skill("tenderzhi",1);
        extra_me= me->query_skill("unarmed");
                  
//      ..........single perform 
        if (!friend) {
        msg = HIG+"$Nʩչ����������ָ��"+ HIY +
        "����ָӰ�����������ָ�磬����$n��ȫ��\n\n" + NOR;
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
                return notify_fail("ͬ�������������ͬһ�������С�\n");  
        
        if(!you->query_skill("yiyangzhi",1) || you->query_skill_mapped("unarmed") != "yiyangzhi") 
                return notify_fail("ͬ��û����ϵ��书��\n");
        if(objectp(ob=you->query_temp("weapon"))) 
                return notify_fail("ͬ�鲻�ǿ��֡�\n");
        if (you->is_busy())
                return notify_fail("ͬ����æ���ء�\n");
                        
        skl_you= you->query_skill("yiyangzhi",1);
        extra_you= you ->query_skill("unarmed");
        
        msg = HIG+"$Nʩչ����������ָ��"+ HIR + you->name()+"ʩչ��������һ��ָ��\n"+ HIY +
        "����ָӰ������������ȵ�ָ�磬����$n��ȫ��\n\n" + NOR;
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
