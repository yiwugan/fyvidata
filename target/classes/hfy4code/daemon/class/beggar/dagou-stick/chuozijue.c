 //silencer@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, myexp, enemyexp, lvl;
        object weapon,hisweapon; 
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("�۴��־���ֻ���ڸ�ؤ����ӣ�\n");
        
        lvl = (int) me->query_skill("dagou-stick",1);
        if(lvl < 20)
                return notify_fail("��Ĵ򹷰���������������\n");       
        
        if (me->query_skill_mapped("force") != "huntunforce")
                return notify_fail("���־���Ҫ�����ķ�����ϡ�\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۴��־���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon");
        
        msg = HIY"\n$N"+HIY"һ�С�"+NOR CYN"��"+HIY"���־���ӭ��һ����ȥ������ζ������Ǵ������̣�ȴ������$n"+HIY"����·����\n"NOR;
        
        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", lvl/5);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", -lvl/5);
        me->start_busy(1+random(2));
        return 1;
}    
