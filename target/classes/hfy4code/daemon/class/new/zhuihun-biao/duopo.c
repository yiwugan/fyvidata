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
    return notify_fail("你的「飞虎追魂镖」不够熟练，无法使用「"MAG"夺魄"NOR"」!\n");
  if(me->query("force") < 500) return notify_fail("你的内力不够！\n");
  if(!target) target = offensive_target(me); 
  if(!target 
      || !target->is_character() 
      || !me->is_fighting(target) ) 
    return notify_fail("「"MAG"夺魄"NOR"」只能对战斗中的对手使用。\n");
  weapon = me->query_temp("weapon");
  count = weapon->query_amount();
	if (count < 5)
		return notify_fail("你的暗器数量太少。\n");
  skill = me->query_skill("zhuihun-biao",1);
  blade = (int)me->query_skill("duanmen-blade",1)/3;
  extra = skill + blade;
  if( !me->query_temp("zhuihun") )
	me->set_temp("zhuihun",1); 
  n = me->query_temp("zhuihun");
  msg = HIR"$N"HIR"长啸声起，身形如同陀螺般滴溜溜急转，"NOR+weapon->name()+HIR"幻化为五道霞光往$n席卷而去！\n\n"NOR;
  kee = target->query("kee");
  me->add_temp("apply/attack", extra*5/2); 
  me->add_temp("apply/damage", extra*2);
  msg += HIG"只见得漫天"+weapon->name()+HIG"，有先发后至，有后发先至，有经碰撞而变向，竟交织成天罗地网，将$n笼罩其中！\n"NOR;
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
	message_vision(RED"\n$n被这一招之威所摄，心神失守！\n"NOR, me, target);
	target->receive_damage("sen", dam, me);
    }
    else
    {
	resist = target->query("resistance/sen");
	tresist = target->query_temp("resistance/sen");
	if( resist + tresist - n > 0 )
        target->set_temp("resistance/sen", tresist - n);
	dam = n>10?800:80*n;
	message_vision(YEL"\n$n被这一招之威所摄，魂飞魄散！\n"NOR, me, target);
	target->receive_damage("sen", dam, me);
    }
  }
  me->add_temp("zhuihun", 1);//必加

  if( skill/10 > random(25) )
  {
    kee = target->query("kee");
    me->add_temp("apply/attack", skill*5/2); 
    me->add_temp("apply/damage", extra*3);
    msg = HIC"$N真气鼓动，长袖飞舞间再向$n洒出一片銀雨！\n"NOR;
    COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
    weapon->set_amount(count-2);
    me->add_temp("apply/attack", -skill*5/2); 
    me->add_temp("apply/damage", -extra*3);

  if( (int)target->query("kee") < kee ) 
 {
    if( random(16-n) > 4 && n < 10 )
    {
	dam = n>6?600:70*n;
	message_vision(RED"\n$n被这一招之威所摄，心神失守！\n"NOR, me, target);
	target->receive_damage("sen", dam, me);
    }
    else
    {
	resist = target->query("resistance/sen");
	tresist = target->query_temp("resistance/sen");
	if( resist + tresist - n > 0 )
        target->add_temp("resistance/sen", tresist - n);
	dam = n>10?1000:100*n;
	message_vision(YEL"\n$n被这一招之威所摄，魂飞魄散！\n"NOR, me, target);
	target->receive_damage("sen", dam, me);
    }
    me->add_temp("zhuihun", 1);  //出第二hit而且打中才加
  }
  }

  if( me->query_busy()<2 ) me->start_busy(2);

  return 1;
}   

//临时减少的神抗就不因为脱离战斗而减少了，让人可以打一下逃一下扣抗和刷zhuihun的数值，本来扣神的效果就不是非常好，而且未必打中
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
  message_vision(HIR"$n惨叫一声，体内真气逆流，当下受到不小的暗亏。\n"NOR, me, target);  //每下都有内力的后续伤害
  if( n > 5 && skill/10>random(50) )
  {
    target->set("force_factor", 0);
    message_vision(HIB"$n浑身一颤，只觉周身真气涣散，无法提劲！\n"NOR, me, target);  //一定几率让enforce 归零
  }
}
