 // neon@fengyun  ��˪���ϼ��
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, bonus, attack_bonus;
        object weapon; 
        if(me->is_busy())
                return notify_fail("������û�գ���\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��˪���ϼ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        weapon = me->query_temp("weapon");
        extra = me->query_skill("sword");
        bonus = me->query_skill("nine-moon-sword",1);
        
        if (bonus>130) extra = extra/2*3 + bonus;
        
        attack_bonus=(me->query("combat_exp")-3500000)/4000*bonus/1000;
        if (attack_bonus>bonus) attack_bonus=bonus;
        if (attack_bonus>0) bonus= bonus+attack_bonus;
                
        me->add_temp("apply/attack", bonus*5);    
        me->add_temp("apply/damage", extra);
        msg = WHT"\n$N����"+ weapon->name() +WHT"����бָ���ϣ�����һ�ڣ�"+weapon->name()+WHT"���޲�б�Ӷ����������Ľ��������ص���˪��" NOR;
        if (me->query("class")=="shenshui") {
        if ( me->query_skill_mapped("force") == "nine-moon-force" 
             && me->query("force")>30 &&  random(bonus)>30 
             && random(me->query("combat_exp"))/60 * extra > target->query("combat_exp")) {
                msg += MAG"\n\nõ��ɫ�ı���ȽȽ������ɭɭ�Ľ�Ӱ�䣬������һ����ɴ����˵�������������ޡ�\n"NOR ;
                target->apply_condition("ninemoonpoison",1 + (extra*(int) me->query_skill("nine-moon-force"))/600);
                target->add("sen",-random(extra/2*3));
                target->set_temp("last_damage_from",me);
                me->add("force", -20);
        }       
   }
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -bonus*5);
        me->add_temp("apply/damage", -extra);
        if (me->query_busy()<2) me->start_busy(2);
        return 1;
} 
