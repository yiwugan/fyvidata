#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg,weapon_name;
        int extra,skill,kee,dam;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۶ϻ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        extra = me->query_skill("blade")*2/3;
        skill = me->query_skill("duanmen-blade",1);
        if ( me->query_skill("duanmen-blade",1) < 80 && userp(me)) 
        return notify_fail("����廢���ŵ��������졣\n");
        if ( skill <= 125) 
		extra = extra*3/4;
        if ( extra >= 300 ) 
		extra = 300;
		    if ( !me->query("marks/��Ҹ���")) extra = extra/6;
        weapon=me->query_temp("weapon");
        weapon_name = weapon->query("name");
        message_vision(HIR "$N�����ذ�"NOR+weapon_name+HIR"������ǰ������ңָ$n������ɢ��������ɱ����$n����������\n\n"+NOR, me,target);

        if( !me->query("class"))
        {
                kee = target->query("kee");
                msg = HIW "$N"+HIW"�澢��ע��һ���ӳ���\nһ��������ƥ�����ֱϮ$n��\n" NOR;
                me->add_temp("apply/damage",extra*3);
                me->add_temp("apply/attack",extra);
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                me->add_temp("apply/damage",- extra*3);
                me->add_temp("apply/attack",- extra);

                if( (int)target->query("kee") < kee )
                { 
				             message_vision(HIY "����ǣ��֮�£�$n���޷���ܣ�������ӲӲ����������$N�˵���һ��ֱ����ǰ������������$nҪ����\n\n"+NOR, me,target);        
				             me->add_temp("apply/attack", extra*3);
				             me->add_temp("apply/damage", extra*4);
				             msg = HIG "���ϻ꣡��" NOR;
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             msg = HIM "�����Σ���" NOR;
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             msg = HIB "����������" NOR;
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             me->add_temp("apply/attack", extra*3);
				             me->add_temp("apply/damage", extra*2);
				             msg = HIR "��ն��ɱ������" NOR;
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             me->add_temp("apply/attack", -extra*6);
				             me->add_temp("apply/damage", -extra*6);
				             if(me->query_busy()<3) me->start_busy(3); 
				        }
				        else
				        {
				             message_vision(HIC "$n����һת�������ܹ�ӭ������ĵ�����$Nһ��ʧ�������浶�ߣ��ݺݵ�ֱ��$nҪ����\n"+NOR, me,target);        
				             me->add_temp("apply/attack", extra*3);
				             me->add_temp("apply/damage", extra*3);
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM);
				             me->add_temp("apply/attack", -extra*3);
				             me->add_temp("apply/damage", -extra*3);
				             if(me->query_busy()<3) me->start_busy(random(1)+1);
             		}
                return 1;
        }//������û��class 
        else 
        if(me->query("class") == "ghost"||me->query("class") == "wolf"||me->query("class") == "bonze"||me->query("class") == "lama"||me->query("class") == "taoist"||me->query("class") == "wudang"||me->query("class") == "shenshui")
        {
	             msg = HIB "$N"+HIB"���ֳֵ�����չ����ͬʱ�ó�������Ӱֱ��$n��ȥ" NOR;
	             me->add_temp("apply/attack", extra*2);
	             me->add_temp("apply/damage", extra*2);
	             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	             me->add_temp("apply/attack", -extra*2);
	             me->add_temp("apply/damage", -extra*2);
	             msg = HIM "$N"+HIM"״����ħ�������е�"NOR+weapon_name+HIM"�������ϼ�⣬����ǵص���$nϮȥ" NOR;
	             me->add_temp("apply/attack", extra*2);
	             me->add_temp("apply/damage", extra*3);
	             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	             me->add_temp("apply/attack", -extra*2);
	             me->add_temp("apply/damage", -extra*3);
        }//����Ҳ�Ǽ���class 1
        else if(me->query("class") == "bandit"||me->query("class") == "bat"||me->query("class") == "emei")
        {
	             msg = YEL "$N"+YEL"����һ�������е�"NOR+weapon_name+YEL"�ڿ��л���һ�������Ļ���ֱ��$n" NOR;
	             me->add_temp("apply/attack", extra*3);
	             me->add_temp("apply/damage", extra*3);
	             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	             me->add_temp("apply/attack", -extra*3);
	             me->add_temp("apply/damage", -extra*3);
				        if( me->query_skill("moon-blade",1) >= 100||me->query_skill("bat-blade",1) >= 150||me->query_skill("shenji-blade",1) >= 160)
				        {
				             msg = BLU "$N"+BLU"�����ƿգ�ƾ���������������$n����ʧ��֮�¾��޷��м�" NOR;
				             me->add_temp("apply/attack", extra*2);
				             me->add_temp("apply/damage", extra*2);
				             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				             me->add_temp("apply/attack", -extra*2);
				             me->add_temp("apply/damage", -extra*2);
				             target->receive_damage("sen", extra*2+random(extra), me);
				        }        
        }//����Ҳ�Ǽ���class 2
        else if(me->query("class") == "legend" ||me->query("class") == "huangshan")
        {
        			 msg = HIY "$N"+HIY"������һ��"NOR+weapon_name+HIY"ƽƽ����ش�������ֱ��$n" NOR;
	             me->add_temp("apply/attack", extra*2);
	             me->add_temp("apply/damage", extra*2);
	             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	             me->add_temp("apply/attack", -extra*2);
	             me->add_temp("apply/damage", -extra*2);
				      if( me->query_skill("shortsong-blade",1) >= 120||me->query_skill("qiusheng-blade",1) >= 120)
				      {
				           msg = HIG "$N"+HIG"���ƻӳ������ֳֵ�����$n" NOR;
				           me->add_temp("apply/attack", extra*3);
				           me->add_temp("apply/damage", extra*2);
				           COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				           me->add_temp("apply/attack", -extra*3);
				           me->add_temp("apply/damage", -extra*2);
				      }        
			        if( me->query_skill("shortsong-blade",1) >= 180||me->query_skill("qiusheng-blade",1) >= 180)
			        {
			             msg = HIC "$N"+HIC"����ͥ�Ų��㣬ʩʩȻ����$n���ţ����������ư�����$n" NOR;
			             me->add_temp("apply/attack", extra*2);
			             me->add_temp("apply/damage", extra*3);
			             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
			             me->add_temp("apply/attack", -extra*2);
			             me->add_temp("apply/damage", -extra*3);
			        }        
        }//����Ҳ�Ǽ���class 3
        else
        {
             msg = HIY "$N"+HIY"��̾һ����"NOR+weapon_name+HIY"��������֮��ֱ��$n" NOR;
             me->add_temp("apply/attack", extra);
             me->add_temp("apply/damage", extra);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             msg = HIW "$N"+HIW"����˫Ŀ��˫�ֳֵ��ῳ$n" NOR;
             me->add_temp("apply/attack", extra*2);
             me->add_temp("apply/damage", extra);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -extra*3);
             me->add_temp("apply/damage", -extra*2);
             msg = HIG "$N"+HIG"�������������һ����$n����·ȫ������" NOR;
             me->add_temp("apply/attack", extra*2);
             me->add_temp("apply/damage", extra*2);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -extra*2);
             me->add_temp("apply/damage", -extra*2);
        }//class������� 4
        if( me->query_skill("wind-blade",1) >= 220)
        {
        if(( me->query_skill("springrain-blade",1) >= 160)&&( me->query_skill("tang-blade",1) >= 180))
            dam=extra*2;
            else dam=extra*3/2;
             msg = MAG "$N"+MAG"����΢�������������������ֱ��$n" NOR;
             me->add_temp("apply/attack", dam);
             me->add_temp("apply/damage", dam);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -dam);
             me->add_temp("apply/damage", -dam);
        }
        if( me->query_skill("xiruo-blade",1) >= 200)
        {
        if(( me->query_skill("springrain-blade",1) >= 160)&&( me->query_skill("tang-blade",1) >= 180))
            dam=extra*3/2;
            else dam=extra;
             msg = CYN "$N"+CYN"�ֵ���ǰ������������㿳��$n" NOR;
             me->add_temp("apply/attack", dam);
             me->add_temp("apply/damage", dam);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -dam);
             me->add_temp("apply/damage", -dam);
        }
        if( me->query_skill("ittouryu",1) >= 160)
        {
        if(( me->query_skill("springrain-blade",1) >= 160)&&( me->query_skill("tang-blade",1) >= 180))
            extra*=2;
             msg = RED "$N"+RED"Ŀɫ���࣬ͻȻ����һ������$n" NOR;
             me->add_temp("apply/attack", extra*3/2);
             me->add_temp("apply/damage", extra*3/2);
             COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
             me->add_temp("apply/attack", -extra*3/2);
             me->add_temp("apply/damage", -extra*3/2);
        }
             if(me->query_busy()<3) me->start_busy(3);
        return 1;
}  
