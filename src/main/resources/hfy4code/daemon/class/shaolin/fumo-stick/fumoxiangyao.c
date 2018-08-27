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
	                return notify_fail("『伏魔降妖』只有少林高僧才能使用。\n");
	        extra = me->query_skill("fumo-stick",1);
	        lvl = me->query_skill("fumo-stick");
	        skill = me->query_skill("zen",1);
	        if( me->query("shaolin/class") == "chan" )
	        {
	        	    if( userp(me)&&extra < 125 )
	        	           return notify_fail("你的少林伏魔棍法还不够熟练。\n");
	        	    if( userp(me)&&me->query("force") < 200) return notify_fail("你的内力不够！\n");
	        }else
	        if( me->query("shaolin/class") == "wu" )
	        {
	        	      if( userp(me)&&extra < 150 )
	        	           return notify_fail("你的少林伏魔棍法还不够熟练。\n");
	                if( userp(me)&& me->query("force") < 100) return notify_fail("你的内力不够！\n");
	        	      if( !objectp(target) ) target = offensive_target(me);
                  if( !objectp(target)
                        ||!target->is_character()
                        ||!me->is_fighting(target) )
                        return notify_fail("『伏魔降妖』只能对战斗中的对手使用。\n");
	        }else
	        {
	        	      return notify_fail("你既不是武僧又不是禅僧，那你是干嘛来了？\n");
	        }
	        
          weapon = me->query_temp("weapon");
          if( me->query("shaolin/class") == "chan" )//禅僧可以杀鬼
          {
          	    if( !objectp(target) ) target = offensive_target(me);
                  if( !objectp(target)
                        ||!target->is_character()
                        ||!me->is_fighting(target) )
                        return notify_fail("『伏魔降妖』只能对战斗中的对手使用。\n");
                  if( !objectp(who=target->query("possessed"))
                      && !target->is_zombie()
                      && !target->is_ghost() )
                      
                          return notify_fail("『伏魔降妖』只能对僵尸，鬼魂，宠物或雇佣兵使用。\n"); 
                   
                  message_vision(HIR"$N"HIR"高喧佛号：「心既无物，不如归去，阿弥陀佛」，手中"HIR+weapon->name()+HIR"往$n头顶一敲!\n"NOR,me,target); 
                  if( target->is_zombie() || target->is_ghost() )
                  {
                  	    message_vision(HIW"$N突然大彻大悟，恍若隔世！\n"NOR,target);
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
                             message_vision(YEL"$N心中一颤，仿佛被什么深深的击打了一下!\n"NOR,target);
                             target->set_temp("last_damage_from", me);
                             target->receive_wound("kee",target->query("max_kee")*5/6);
                             target->receive_damage("kee",target->query("max_kee")*5/6);
                        }
                        else
                        {
                         	   if( target->query("race") == "人类" )
                         	         message_vision(HIR"$N大声对$n喝道：“死秃驴，找死啊！\n"NOR,target,me);
                         	   target->kill_ob(me);
                         	   me->kill_ob(target);  
                        }
                  }
                  me->add("force",-200);
                  if( me->query_busy()<2 ) me->start_busy(2);
          }
          else if( me->query("shaolin/class") == "wu" )
          {
          	      message_vision( HIY"\t$N突然长喝一声:\n"NOR,me);
          	      me->add_temp("apply/attack",lvl);
          	      me->add_temp("apply/damage",extra);
          	      msg = HIR"\t\t『伏』\n"NOR;
          	      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	      msg = HIY"\t\t『魔』\n"NOR;
          	      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	      //add 1
          	      me->add_temp("apply/attack",lvl/2);
          	      me->add_temp("apply/damage",extra/2);
          	      msg = WHT"\t\t『降』\n"NOR;
          	      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	      
          	      msg = RED"\t\t『妖』\n"NOR;
          	      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
          	      //add 1.5
          	      me->add_temp("apply/attack",-lvl*3/2);
          	      me->add_temp("apply/damage",-extra*3/2);
          	      //add - 2
          	      
          	      if( extra>170&&random(extra)>150 )
          	      {
          	            msg = HIY"$N使出的棍法陡然一变，"HIY+weapon->name()+HIY"发出道道佛光，闪耀大地！\n"NOR;
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
          	      return notify_fail("你的棍法杂乱无章！\n");
          }
    return 1;
} 
