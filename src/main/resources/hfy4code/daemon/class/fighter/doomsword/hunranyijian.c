 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, skill, sword,damage;
        object weapon;
        
        if( !target ) target = offensive_target(me); 
        if( !target
                ||      !target->is_character()
                ||      !me->is_fighting(target) )
                return notify_fail("�ۻ�Ȼһ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        weapon = me->query_temp("weapon");
        skill=me->query_skill("doomsword",1);
        if(skill < 130 && userp(me)) {
        //      130+random(130)
                extra = skill + random(skill);
                damage = extra;
                msg = HIR  "$N����ǰ�����е�"+ weapon->name()+ HIR"һʽ��"+HIW"��Ȼһ��"+HIR"�ݣ���â�������޵���$n"+HIR"��ȥ��" NOR;
        }
        else    {
        //      260+random(260)
        sword=me->query_skill("sword",1);
        skill=me->query_skill("doomsword",1);
                extra = sword + random(skill);
                damage=extra*2;       
                if (me->query("class")=="fighter") damage = extra*5;
                msg = HIR "$N����ǰ�����е�"+ weapon->name() + HIR"һ�������Ǻ��촵Ѫ�����о���һʽ������"+HIW"��Ȼһ��"+HIR"�ݣ�\n ����Ѫ��ɫ�Ľ�â,��$n"+HIR"��Χ�����У�" NOR;
        }
        
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", damage);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -damage);
        
        if (me->query_busy()<2) {
                me->start_busy(2);
           }
                
        return 1;
}      
