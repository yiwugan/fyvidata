 // poqi.c ����ʽ
 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{

 string msg;
 int skill,ap,dp,tf;
if (me->query("class")!="huashan")
                return notify_fail ("������ʽ��ֻ�л�ɽ������ʹ�á�\n");
 if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
 skill = (int)me->query_skill("dugu-sword",1);
 //no poqi in fy4 -neon
 if( skill < 175 && userp(me))
  return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n"); 
 if( me->query("force") < 500 )
  return notify_fail("��������������޷����á�����ʽ����\n");
 
 msg = HIB "$N���˶��¾Ž�������ʽ����һ����������Ȼ����, �����ǽ�����񾪣� \n";
 if(userp(me)) me->add("force",-100);
 ap =  (int) me->query("combat_exp")* skill/10;
 dp = (int) target->query("combat_exp");
 if(random(ap+dp) > dp) {
 if(userp(target)){
  tf = (int)target->query("max_force");
  target->set("force",0);
  target->set("max_force",tf/3);
 }
 msg += "$n�����������Ѩ�ƺ��������У�������ʧ��\n" NOR;
        me->start_busy(2);
        target->start_busy(2);
 }else {
 msg += "����$n������$N�Ľ�·���͵�һ�����ſ��������\n" NOR;
 me->start_busy(2);
 }
 message_vision(msg, me, target);
 return 1;
} 
