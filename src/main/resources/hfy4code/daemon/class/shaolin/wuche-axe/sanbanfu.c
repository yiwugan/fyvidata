 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,extra_damage;
        object weapon;
        extra = me->query_skill("wuche-axe",1);
        
        if ( extra < 100) return notify_fail("����򳹲��縫�����������죡\n");
        
        if (extra >139 && me->query_skill("zen",1)>179 && me->query("class")=="shaolin")
			extra = me->query_skill("axe");
			
        if (me->query("class")=="shaolin") extra_damage=extra;
        
        if (me->query("class")!="shaolin") extra=extra/4;
                else extra = extra/2;
                        
//      if (userp(me) && me->query_skill_mapped("force") != "xiaochengforce")
//              return notify_fail("�����師����Ҫ��С���ķ��ݵ���ϣ�\n"); */
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����師��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",extra);
        msg = HIY  "$Nʹ���򳹲��縫���еģ����師�ݣ�һ���������������е�"+ weapon->name()+  "��ɽ����$n������һ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        msg = HIC  "�ڶ�����" NOR;
        me->add_temp("apply/damage",extra_damage);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        if (me->query_skill("wuche-axe",1) > 130) {
                        msg = HIC  "��������" NOR;
                        me->add_temp("apply/damage",extra+extra_damage);
                        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                        me->add_temp("apply/damage",-extra-extra_damage);             
                   }
        else tell_object(me,HIG"\n����ַ���������,������ûʹ����.\n"NOR);      
        
        me->add_temp("apply/damage",-extra_damage);
        me->add_temp("apply/attack",-extra);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
}      
