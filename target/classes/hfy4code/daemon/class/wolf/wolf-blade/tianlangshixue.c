#include <ansi.h>
#include <combat.h>
inherit SSERVER;
static string *sym_dee = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" }); 
int perform(object me, object target)
{
        string msg,day;
        int extra,time,damage;
        mixed *local;
        object weapon;
        
        if( me->query("class") != "wolf" )
        	return notify_fail("ֻ����ɽ���Ӳ���ʹ�á�������Ѫ����\n");
        
        extra = me->query_skill("wolf-blade",1);
        
        if ( extra < 151) return notify_fail("��ģ�������Ѫ���ݻ��������죡\n"); 
        if( !target ) target = offensive_target(me);    
        if( !target     
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        local = NATURE_D->getTime(time());      
        day = sym_dee[local[1]]; 
        if(  day == "��" || day == "��" || day == "��"
           ||day == "��" || day == "��" || day == "î"  )
           {
           	damage = extra*3;
           	me->add_temp("apply/damage",extra);
           	me->add_temp("apply/attack",damage);
        	msg = RED "$NͻȻ���쳤����ҹɫ�£���ϡ�ɿ���$Nͫ���������ɺ���̣�����һ��Ѫɫ�ĵ����$n�������У�"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = WHT "�졤Ѫ��ĵ���Ѹ���ڿ������ģ�"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = MAG "�ǡ�ããҹ���£��ǹ�â�۳�һֻ�޴��ޱȵ���������$n��"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = HIC "�ɡ�����¶����������ҹ������ҫ���������ǵĺ��⡣"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/damage",-extra);
           	me->add_temp("apply/attack",-damage);
           	if( random(2) )
           	{
           		me->add_temp("apply/damage",2*extra);
           		me->add_temp("apply/attack",2*damage);
           		msg = RED"Ѫ�����Ǽ��֣���Ѫ���飡"NOR;
        		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        		me->add_temp("apply/damage",-2*extra);
           		me->add_temp("apply/attack",-2*damage);
           		if( target->query_temp("damaged_during_attack") )//û�д��У���ôҲҪ��Ѫ
           		{
        			target->receive_wound("kee",random(extra/2)+extra/2);
                        	target->receive_damage("kee",extra+extra/2);
                        	target->set_temp("last_damage_from",me);
                        	COMBAT_D->report_status(target);
                        	COMBAT_D->win_lose_check(me,target,1);
                        }
                }
                else
                {
                	msg = RED"Ѫ��Ѫ�쵶���������ǵ�����һ�¾͵���$n������"NOR;
                	me->add_temp("apply/damage",2*extra);
           		me->add_temp("apply/attack",2*damage);
        		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        		me->add_temp("apply/damage",-2*extra);
           		me->add_temp("apply/attack",-2*damage);
           	}
        }
        else
        {
        	damage = extra*2;
        	me->add_temp("apply/damage",extra);
           	me->add_temp("apply/attack",damage);
           	msg = RED "$NͻȻ���쳤��:-��-��-��-Ѫ-������һ��Ѫɫ�ĵ�â���ǣ��ڿն����������$n�������У�"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = WHT "Ѫ��ĵ��ڿ��к������֣�������ã�$n�����ξ���"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = MAG "ͻȻѪ����û����ճ���һͷ�޴����������$n��"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = HIC "���Ƿ�����������ҫ���Ĺ�â��$n������������"NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/damage",-extra);
           	me->add_temp("apply/attack",-damage);
           	if( random(2) )
           	{
           		me->add_temp("apply/damage",2*extra);
           		me->add_temp("apply/attack",2*damage);
           		msg = RED"���Ǽ��֣���Ѫ���飡"NOR;
        		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        		me->add_temp("apply/damage",-2*extra);
           		me->add_temp("apply/attack",-2*damage);
           		if( target->query_temp("damaged_during_attack") )//û�д��У���ôҲҪ��Ѫ
           		{
        			target->receive_wound("kee",random(extra/2)+extra/2);
                        	target->receive_damage("kee",extra+extra/2);
                        	target->set_temp("last_damage_from",me);
                        	COMBAT_D->report_status(target);
                        	COMBAT_D->win_lose_check(me,target,1);
                        }
                }
                else
                {
                	msg = RED"Ѫ�쵶���������ǵ�����һ�¾͵���$n������"NOR;
                	me->add_temp("apply/damage",2*extra);
           		me->add_temp("apply/attack",2*damage);
        		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        		me->add_temp("apply/damage",-2*extra);
           		me->add_temp("apply/attack",-2*damage);
           	}
        	
        }
        if( me->query_busy()<4) me->start_busy(4);
        return 1;
}
	