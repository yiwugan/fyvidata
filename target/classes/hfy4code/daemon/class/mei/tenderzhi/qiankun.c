 // sfy changed
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int skl_me, skl_you, extra_me, extra_you,i,j, dmg;
        int FLAG=0;
        object you,ob,*obs;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��һָ��Ǭ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		dmg = me->query_skill("tenderzhi",1) + me->query_skill("xuanxinjue",1);
		if(me->query("kee")<= dmg)
			return notify_fail("�������״��̫����������������ָ��\n");
        if(pointerp(obs=me->query_team()) )
        {
        FLAG=1;
        for(i=0;i<sizeof(obs);i++)
        {
        if(obs[i] == me) continue;
        if(!obs[i]) {FLAG=0;continue;}
        if(environment(obs[i]) != environment(me)) {FLAG=0;continue;}
        if(!obs[i]->query_skill("yiyangzhi")) {FLAG=0;continue;}
        if(objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0;continue;}
        if(obs[i]->query_skill_mapped("unarmed") != "yiyangzhi") {FLAG=0;continue;}
        }       
        if(sizeof(obs) !=2) FLAG=0;
        }
        skl_me=(int)me->query_skill("unarmed");
        extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/10;
        if(FLAG)
        {
                if(obs[0]==me) you=obs[1]; else you=obs[0];
        skl_you=(int)you->query_skill("unarmed");
        extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str();
        msg = HIG+"$Nʩչ����������ָ��"+ HIR + you->name()+"ʩչ��������һ��ָ��\n"+ HIY +
        "����ָӰ������������ȵ�ָ�磬����$n��ȫ��\n\n" + NOR;
        me->add_temp("apply/attack",(skl_you+skl_me)/5);
        me->add_temp("apply/damage",(extra_you+extra_me * 3));
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-(skl_you+skl_me)/5);
        me->add_temp("apply/damage",-(extra_you+extra_me * 3));
        you->kill_ob(target);
        }
        else
        {
        msg = HIG"$N"HIG"ʩչ����������ָ��"HIY"����ָӰ�����������ָ�磬����$n"HIY"��ȫ��\n"NOR;
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
        
	if(me->query_temp("xuanxinaomiao"))
 	{
        msg = HIM"$N"HIM"ֻ��������ʢ��ָ�����㣬"HIY"����ָӰ���������������������$n"HIY"��ȫ��\n"NOR;
        me->add_temp("apply/attack",skl_me*3);
        me->add_temp("apply/damage",extra_me*2);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me*3);
        me->add_temp("apply/damage",-extra_me*2);
	}
	if(me->query_skill("tenderzhi",1)>150)
		if(me->query_skill("xuanxinjue",1)>150)
					if(me->query_temp("xuanxinaomiao"))
	{
		if(me->query_skill("tenderzhi",1)>200) skl_me= skl_me * 2;
		if(me->query_skill("xuanxinjue",1)>220) extra_me = extra_me*2;
		msg = HIR"$N"HIR"�������ȣ�ָ�⾹Ȼ���Ƴ�һ����Ѫ��"HIY"���İ�����Ĺ�â����Ѫ����һ�𣬱���һ��Ѫ������$n"HIY"��ȫ��\n"NOR;
        me->add_temp("apply/attack",skl_me*3);
        me->add_temp("apply/damage",extra_me*5);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me*3);
        me->add_temp("apply/damage",-extra_me*5);
		me->receive_damage("kee", dmg);
	} 
}      
        me->start_busy(2);
        return 1;
} 
