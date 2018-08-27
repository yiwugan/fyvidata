//ximen@sxfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
void remove_effect(object target);
int perform(object me, object target)
{
        string msg;
        int extra,skill,attack,armor,iron_cloth,force,cut,cooldown,kee;
//        object weapon;
		  
        if( me->query("class")!="tieflag" ) 
                return notify_fail ("����Ѫ���������ײ���ʹ�þ�����"HIW+"��������"NOR"������\n");
        if( me->query("family/master_id") !="master tie" && me->query("combat_exp") < 10000000 )
              return notify_fail("������"HIW+"��������"NOR+"ֻ���������״����Ӳ���ʹ�á�\n"); 
        force = me->query_skill("jiayiforce",1);
        cooldown = 200 - force;
        if( cooldown <= 0) cooldown = 0;
        extra = me->query_skill("sword");
        skill = me->query_skill("xiaoxiang-sword",1);


        if (  me->query_temp("timer/shenjian") + 60 + cooldown>time())
              return notify_fail("������"HIW+"��������"NOR+"��������ʹ�á�\n"); 
        if( me->query("force") < 500 )
                return notify_fail("�������������\n");

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() ||  !me->is_fighting(target) )
              return notify_fail("������"HIW+"��������"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        iron_cloth = target->query_skill("iron-cloth",1);
        armor = target->query("resistance/kee");
        if( me->query_skill("xiaoxiang-sword",1)<180)
              return notify_fail("����δ���㹻������ʩչ������"HIW+"��������"NOR+"��\n"); 
//        weapon = me->query_temp("weapon");
        msg = HIB  "\n$N�������£���������$n�̳�һ��������ȥ�ƺ��������ò��ϳ���\n"NOR;
        message_vision(msg, me, target);
        msg = HIB  "Ȼ����$n���У��ⲻ�ϳ����һ���������޿�ƥ�е�ɱ�У�$N�Ľ�������ͬ��ɰ���հ��޴����ڣ���$n�ܻ�Ŀռ����������\n\n"NOR;
        message_vision(msg, me, target);

        if( me->query_skill_mapped("force") != "jiayiforce") extra*=1/7;
        me->add("force", -500);
        if( !target->query_temp("cutkee") && armor > 0 && me->query_skill_mapped("force") == "jiayiforce")
        {
        cut = armor*force/200;
	  if(cut >= armor)
		cut = armor;
        message_vision(RED"���ȵĽ��������߰���Ѩ������$n����Ѫ�����ڣ����ܵò����Ѫ��\n"NOR,me,target);
        target->set_temp("resistance/kee",-cut);//������Ϊ����
        target->set_temp("cutkee",1);
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), force/15);
        }
        msg = HIC  "�������һɲ�Ǽ�·�ֹ��ǰ����$N�ǻ�����һ���ڵ�ָ�仯�����磬ֱ��$n��ȥ��\n"NOR;
        message_vision(msg, me, target);
        msg = WHT  "\n$N��˻�Ƶģ��·������Լ���������������\n"NOR;
        message_vision(msg, me, target);
        msg = HIG"���񡤽��������⡤ɽ���ӡ�������"NOR;
        me->add_temp("apply/attack",extra*5);
        me->add_temp("apply/damage",extra*7);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY"���졤�ء��䡤�⡤�硤�ơ��ң���"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        if(iron_cloth > 0)
        {
        message_vision(YEL"\n����ʵ�ʵĽ����緱�Ƿ�׹������$n�Ļ�����͸����룡\n"NOR,me,target);
	  if( me->query_skill("jiayiforce",1) < 180 )
	  skill*=1/2;
        target->receive_damage("kee", skill*iron_cloth/5, me);
        }
        me->add_temp("apply/attack",-extra*5);
        me->add_temp("apply/damage",-extra*7);
        me->set_temp("timer/shenjian",time());
        me->start_busy(3); 
        target->set_temp("damaged_during_attack", 1);
        COMBAT_D->report_status(target, 0);
        COMBAT_D->win_lose_check(me,target,1);
        return 1;
}  

void remove_effect(object target)
{
	if( !objectp(target) ) return;
	target->delete_temp("resistance/kee");
	target->delete_temp("cutkee");
    message_vision(HIG"\n$N����һ���������ò����ײŰ����־��������Ƚ���������ȥ��\n"NOR,target);
} 