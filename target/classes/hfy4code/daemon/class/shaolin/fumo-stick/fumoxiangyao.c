#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
	        int extra,skill,lvl;
	        int myexp,tarexp;
	        object weapon,who;
	        string msg;
	        
	        if( me->query("class") != "shaolin" )
	                return notify_fail("����ħ������ֻ�����ָ�ɮ����ʹ�á�\n");
	        extra = me->query_skill("fumo-stick",1);
	        lvl = me->query_skill("fumo-stick");
	        skill = me->query_skill("zen",1);
	        if( me->query("shaolin/class") == "chan" )
	        {
	        	    if( userp(me)&&extra < 125 )
	        	           return notify_fail("������ַ�ħ����������������\n");
	        	    if( userp(me)&&me->query("force") < 200) return notify_fail("�������������\n");
	        }else
	        if( me->query("shaolin/class") == "wu" )
	        {
	        	      if( userp(me)&&extra < 150 )
	        	           return notify_fail("������ַ�ħ����������������\n");
	                if( userp(me)&& me->query("force") < 100) return notify_fail("�������������\n");
	        	      if( !objectp(target) ) target = offensive_target(me);
                  if( !objectp(target)
                        ||!target->is_character()
                        ||!me->is_fighting(target) )
                        return notify_fail("����ħ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	        }else
	        {
	        	      return notify_fail("��Ȳ�����ɮ�ֲ�����ɮ�������Ǹ������ˣ�\n");
	        }
	        
          weapon = me->query_temp("weapon");
          if( me->query("shaolin/class") == "chan" )//��ɮ����ɱ��
          {
          	    if( !objectp(target) ) target = offensive_target(me);
                  if( !objectp(target)
                        ||!target->is_character()
                        ||!me->is_fighting(target) )
                        return notify_fail("����ħ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                  if( !objectp(who=target->query("possessed"))
                      && !target->is_zombie()
                      && !target->is_ghost() )
                      
                          return notify_fail("����ħ������ֻ�ܶԽ�ʬ����꣬������Ӷ��ʹ�á�\n"); 
                   
                  message_vision(HIR"$N"HIR"������ţ����ļ���������ȥ�������ӷ𡹣�����"HIR+weapon->name()+HIR"��$nͷ��һ��!\n"NOR,me,target); 
                  if( target->is_zombie() || target->is_ghost() )
                  {
                  	    message_vision(HIW"$NͻȻ�󳹴��򣬻���������\n"NOR,target);
                  	    target->set_temp("last_damage_from", me);
                        target->die();
                  }
                  else
                  {
                        myexp = (int) me->query("combat_exp");
                        tarexp= (int)target->query("combat_exp");
                        myexp=myexp*3+random(myexp);
                        if( myexp > tarexp )
                        {
                             message_vision(YEL"$N����һ�����·�ʲô����Ļ�����һ��!\n"NOR,target);
                             target->set_temp("last_damage_from", me);
                             target->receive_wound("kee",target->query("max_kee")*5/6);
                             target->receive_damage("kee",target->query("max_kee")*5/6);
                        }
                        else
                        {
                         	   if( target->query("race") == "����" )
                         	         message_vision(HIR"$N������$n�ȵ�������ͺ¿����������\n"NOR,target,me);
                         	   target->kill_ob(me);
                         	   me->kill_ob(target);  
                        }
                  }
                  me->add("force",-200);
                  if( me->query_busy()<2 ) me->start_busy(2);
          }
          else if( me->query("shaolin/class") == "wu" )
          {
          	      message_vision( HIY"\t$NͻȻ����һ��:\n"NOR,me);
          	      me->add_temp("apply/attack",lvl);
          	      me->add_temp("apply/damage",extra);
          	      msg = HIR"\t\t������\n"NOR;
          	      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	      msg = HIY"\t\t��ħ��\n"NOR;
          	      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	      //add 1
          	      me->add_temp("apply/attack",lvl/2);
          	      me->add_temp("apply/damage",extra/2);
          	      msg = WHT"\t\t������\n"NOR;
          	      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	      
          	      msg = RED"\t\t������\n"NOR;
          	      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	      //add 1.5
          	      me->add_temp("apply/attack",-lvl*3/2);
          	      me->add_temp("apply/damage",-extra*3/2);
          	      //add - 2
          	      
          	      if( extra>170&&random(extra)>150 )
          	      {
          	            msg = HIY"$Nʹ���Ĺ�����Ȼһ�䣬"HIY+weapon->name()+HIY"����������⣬��ҫ��أ�\n"NOR;
          	            me->add_temp("apply/attack",2*lvl);
          	            me->add_temp("apply/damage",2*extra);
          	            COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	            me->add_temp("apply/attack",-lvl*2);
          	            me->add_temp("apply/damage",-extra*2);
          	            if( me->query_busy()<4 ) me->start_busy(4);
          	     }
          	     else
          	     {
          	     	      if( me->query_busy()<3 ) me->start_busy(3);
          	     }
          }
          else
          {
          	      if( me->query_busy()<1) me->start_busy(1);
          	      return notify_fail("��Ĺ����������£�\n");
          }
    return 1;
} 
