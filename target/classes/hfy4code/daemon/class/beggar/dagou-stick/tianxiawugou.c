 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i, bonus, exp_bonus;
        
        object weapon, *enemy;
        
/*      
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������޹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/
        if((int)me->query_skill("dagou-stick",1) < 120 && userp(me))
                return notify_fail("��Ĵ򹷰���������������\n");        
        enemy=me->query_enemy();
        if(!sizeof(enemy))
                return notify_fail("�������޹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target)
                return notify_fail("������в���Ҫָ��ʹ�ö��󣡣�\n");
                
        weapon = me->query_temp("weapon"); 
        extra = me->query_skill("dagou-stick");
        bonus = 0;
        if (extra>150 && me->query("class")== "beggar") bonus= extra*3; 
        me->add_temp("apply/attack", extra);  
        me->add_temp("apply/damage", extra+bonus);
        msg = HIY  "\n\n$N"+HIY"�ͺ�һ����"+HIR"�졪�¡��ޡ���"+HIY"�ݣ�\n"+HIW"$N"+HIW"������Ȼ���ۣ�"+
weapon->name() +
HIW"���������Ӱ������ǵ�ɢ���ڳ�ÿһ���ˣ�\n" NOR;
        message_vision(msg,me);
        for(i=0;i<sizeof(enemy);i++)
        {
                msg=HIY"$N"+HIY"���е�$w"+HIY"ֱȡ$n"+HIY"��$l����"NOR;
                me->set_temp("dagou/pfm",1);
           COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
                me->delete_temp("dagou/pfm",1);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra-bonus);
        if (me->query_busy()<2) 
                me->start_busy(2);
        return 1;
}  
