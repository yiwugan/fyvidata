//springrain-blade.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 int extra; 
 object weapon;
 if(me->is_busy())
  return notify_fail("������û�գ���\n");
 extra = me->query_skill("blade"); 
 if (me->query("class")== "swordsuper") extra = extra * 8;
        if (me->query("class")=="legend") extra = extra * 2;
        if (me->query("class")=="tieflag") extra = extra * 3;
        if (me->query("class")=="huangshan") extra = extra * 6;
        if (me->query("class")=="yinshi") extra = extra * 5;
 if ( me->query_skill("springrain-blade",1) < 120 && userp(me)) 
     return notify_fail("��Ĵ��굶���������졣\n");
 if( !target ) target = offensive_target(me);
 if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۵�ʱ���£�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",extra/3);
        me->add_temp("apply/damage",extra/5);
        weapon = me->query_temp("weapon");
        msg = HIC  "\n$N��̾һ�����������˸�������"+ weapon->name()+HIC"бб�ӳ���ȴ�ǡ����굶�����еľ���֮ʽ"HIY"����ʱ�������£���"+HIC"��\n" NOR;
        message_vision(msg,me,target);
        msg = HIC"              ��   "HIY"             ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"              ʱ   "HIY"             ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"              ��   "HIY"             ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"              ��   "HIY"             ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"              ��   "HIY"             ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->start_busy(3);
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra/5);
        return 1;
}    
