 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,skill;
        object weapon;
        if(me->query("class")!="swordsman")
                return notify_fail("��ֻ�н���ĵ��Ӳ����ʸ��ã�\n");
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۳�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("sword") *2;
        skill = me->query_skill("softsword",1);
        
        if(skill<100)
                return notify_fail("�����ϸ�����ὣ������Ϊ������\n");
                
        target->delete_temp("last_damage_from");
        me->set_temp("cut_mana",1);
        me->add_temp("apply/attack", -extra/2); 
        me->add_temp("apply/damage", extra*2);
        msg =  weapon->name()+ HIC"��ն��𣬻���һ���⻪��һ����������Ĺ⻪���ӳǡ��Ի͡������� \n"
HIW "�⻪����������á��߸����ϣ�����Ʈ�������Ǽ�����⻪�Ѿ���$n 
ü�޼�!���ı仯�������ѳ�Խ�����������ļ��ޣ������������޷����š� "NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", extra/2);
        me->add_temp("apply/damage", -extra*2);
        if (me->query_busy()<3) me->start_busy(3);
        me->delete_temp("cut_mana");
        return 1;
} 
