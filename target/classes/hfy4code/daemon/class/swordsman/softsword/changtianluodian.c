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
        extra = me->query_skill("sword") *4;
        skill = me->query_skill("softsword",1);
        if( me->query_temp("parryup") ) skill = skill*4;
        	
        if(skill<150)
                return notify_fail("�����ϸ�����ὣ������Ϊ������\n");
                
        target->delete_temp("last_damage_from");
        me->set_temp("cut_mana",1);
        me->add_temp("apply/attack", skill);  
        me->add_temp("apply/damage", extra);
        msg =  weapon->name()+ HIC"��ն��𣬻���һ���⻪��һ����������Ĺ⻪���財��Ի͡������� \n"
HIW "�⻪����������á��߸����ϣ�����Ʈ�������Ǽ�����⻪�Ѿ���$n 
ü�޼�!���ı仯�������ѳ�Խ�����������ļ��ޣ������������޷����š� "NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -skill);
        me->add_temp("apply/damage", -extra);
        if (me->query_busy()<3) me->start_busy(3);
        me->delete_temp("cut_mana");
        return 1;
} 
