// hunqianmengrao.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void cutforce(object me, object target);
int perform(object me, object target) {
  string msg;
  int extra, skill, blade, n, kee, dam, force, count;
  int resist, tresist;
  object weapon;
  if(me->query_skill("zhuihun-biao",1)<100) 
    return notify_fail("��ġ��ɻ�׷���ڡ������������޷�ʹ�á�"MAG"����"NOR"��!\n");
  if(me->query("force") < 500) return notify_fail("�������������\n");
  if(!target) target = offensive_target(me); 
  if(!target 
      || !target->is_character() 
      || !me->is_fighting(target) ) 
    return notify_fail("��"MAG"����"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
  weapon = me->query_temp("weapon");
  count = weapon->query_amount();
	if (count < 5)
		return notify_fail("��İ�������̫�١�\n");
  skill = me->query_skill("zhuihun-biao",1);
  blade = (int)me->query_skill("duanmen-blade",1)/3;
  extra = skill + blade;
  if( !me->query_temp("zhuihun") )
	me->set_temp("zhuihun",1); 
  n = me->query_temp("zhuihun");
  msg = HIR"$N"HIR"��Х����������ͬ���ݰ�����Ｑת��"NOR+weapon->name()+HIR"�û�Ϊ���ϼ����$nϯ���ȥ��\n\n"NOR;
  kee = target->query("kee");
  me->add_temp("apply/attack", extra*5/2); 
  me->add_temp("apply/damage", extra*2);
  msg += HIG"ֻ��������"+weapon->name()+HIG"�����ȷ��������к��������о���ײ�����򣬾���֯�����޵�������$n�������У�\n"NOR;
  COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
  weapon->set_amount(count-1);
  me->add_temp("apply/attack", -extra*5/2); 
  me->add_temp("apply/damage", -extra*2);
  me->add("force", -300);
  me->start_call_out( (: call_other, __FILE__, "cutforce", me, 
target :), 10);  
		
  if( (int)target->query("kee") < kee ) 
  {
    if( random(16-n) > 4 && n < 10 )
    {
	dam = n>6?400:60*n;
	message_vision(RED"\n$n����һ��֮�����㣬����ʧ�أ�\n"NOR, me, target);
	target->receive_damage("sen", dam, me);
    }
    else
    {
	resist = target->query("resistance/sen");
	tresist = target->query_temp("resistance/sen");
	if( resist + tresist - n > 0 )
        target->set_temp("resistance/sen", tresist - n);
	dam = n>10?800:80*n;
	message_vision(YEL"\n$n����һ��֮�����㣬�����ɢ��\n"NOR, me, target);
	target->receive_damage("sen", dam, me);
    }
  }
  me->add_temp("zhuihun", 1);//�ؼ�

  if( skill/10 > random(25) )
  {
    kee = target->query("kee");
    me->add_temp("apply/attack", skill*5/2); 
    me->add_temp("apply/damage", extra*3);
    msg = HIC"$N�����Ķ���������������$n����һƬ�y�꣡\n"NOR;
    COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
    weapon->set_amount(count-2);
    me->add_temp("apply/attack", -skill*5/2); 
    me->add_temp("apply/damage", -extra*3);

  if( (int)target->query("kee") < kee ) 
 {
    if( random(16-n) > 4 && n < 10 )
    {
	dam = n>6?600:70*n;
	message_vision(RED"\n$n����һ��֮�����㣬����ʧ�أ�\n"NOR, me, target);
	target->receive_damage("sen", dam, me);
    }
    else
    {
	resist = target->query("resistance/sen");
	tresist = target->query_temp("resistance/sen");
	if( resist + tresist - n > 0 )
        target->add_temp("resistance/sen", tresist - n);
	dam = n>10?1000:100*n;
	message_vision(YEL"\n$n����һ��֮�����㣬�����ɢ��\n"NOR, me, target);
	target->receive_damage("sen", dam, me);
    }
    me->add_temp("zhuihun", 1);  //���ڶ�hit���Ҵ��вż�
  }
  }

  if( me->query_busy()<2 ) me->start_busy(2);

  return 1;
}   

//��ʱ���ٵ��񿹾Ͳ���Ϊ����ս���������ˣ����˿��Դ�һ����һ�¿ۿ���ˢzhuihun����ֵ�����������Ч���Ͳ��Ƿǳ��ã�����δ�ش���
void cutforce(object me, object target)
{
  int n, tforce, skill;
  if(!objectp(target))
{
    me->delete_temp("zhuihun");
    return;
}
  n = me->query_temp("zhuihun");
  tforce = (int)target->query("force");
  skill = me->query_skill("zhuihun-biao",1);
  if( (tforce - n*100 < 0) && tforce >= 0 )
	target->set("force", 0);
  else target->add("force", -n*100);
  message_vision(HIR"$n�ҽ�һ�����������������������ܵ���С�İ�����\n"NOR, me, target);  //ÿ�¶��������ĺ����˺�
  if( n > 5 && skill/10>random(50) )
  {
    target->set("force_factor", 0);
    message_vision(HIB"$n����һ����ֻ������������ɢ���޷��ᾢ��\n"NOR, me, target);  //һ��������enforce ����
  }
}
