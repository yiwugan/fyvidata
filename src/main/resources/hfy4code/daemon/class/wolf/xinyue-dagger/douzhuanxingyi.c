 // silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
//inherit NPC;
void simulate_set(object target,object shadow); 
int perform(object me, object target)
{
        string msg,temp,temp1;
        int extra,num,num1;
        int myexp,yourexp, exp_bonus,cond;
        object weapon,shadow,hisweapon,newweapon;
        
        extra = me->query_skill("xinyue-dagger",1);
        exp_bonus = (me->query("combat_exp")-3000000)/2000*extra/100;
        if (exp_bonus> extra) exp_bonus=extra;
        
        if(me->query("class")!="wolfmount")
        return notify_fail("ֻ����ɽ���Ӳ���ʹ������ת���ơ��ľ�����\n");
        
        if ( extra < 100) return notify_fail("���[����ն�ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۶�ת���ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        myexp=me->query("combat_exp");
        yourexp=target->query("combat_exp");
        
        me->add_temp("apply/damage", extra*5+(exp_bonus*3));
        me->add_temp("apply/attack", extra*5);
        msg =HIY"      ൣ�˳���߲�������������������أ�Ψ��������\n\n"NOR;
        msg= msg+HIR"  $N����Ȱ��۵�$n��ǰ��"NOR+ weapon->name()+ HIR "��$n���Ĵ�ȥ��\n" NOR;
        COMBAT_D->do_attack(this_player(),target,TYPE_PERFORM,msg);
        me->add_temp("apply/damage", -extra*5-(exp_bonus*3));
        me->add_temp("apply/attack", -extra*5);
        
        msg = HIR "\n������$Nһ����Х��"NOR+"      "+HIC"��"NOR+"      "+HIY"ת"NOR+
        "      "+HIW"��"NOR+"      "+HIB"��"NOR+"\n"; 
        message_vision(msg,me);
        
        if ((myexp+random(myexp*3)+myexp*3>yourexp/2)&& !target->query_temp("is_unconcious")) {
                
                msg= MAG"\n$N�·�������һ������������У���������ʽ��Ȼ����������\n\n"NOR;
                message_vision(msg,target);
                        
                seteuid(getuid());
           if (!userp(target)) {
                        sscanf(file_name(target),"%s#%d",temp,num);
                        shadow=new(temp);
                        
                        }
                else    {
                        shadow=new("/d/fy/npc/shadefigure");
                        shadow->changeshape(target);            
                        if(hisweapon=target->query_temp("weapon"))      {
                                sscanf(file_name(hisweapon),"%s#%d",temp1,num1);
                                newweapon=new(temp1);
                                newweapon->move(shadow);
                                newweapon->wield();
                        }
                }       
                shadow->set("owner",me);
                shadow->set("possessed",me);
                shadow->move(environment(me));
                if (!target->query_temp("weapon"))
                if (newweapon=shadow->query_temp("weapon"))
                        newweapon->unequip();   
                shadow->add_killer(target->query("id"));
                
                
                simulate_set(target,shadow);
                shadow->add_temp("apply/attack", 2*extra);
                shadow->add_temp("apply/damage", 2*extra);
                if(shadow->query("str")<40) shadow->set("str",40); //by xiuaolang
                if(shadow->query("force_factor")<250) shadow->set("force_factor",250);//by xiaolang
                message_vision(HIC "    ��\n" NOR,me);
                COMBAT_D->do_attack(shadow,target,msg);
                if (target->query_temp("damaged_during_attack"))
                                        target->set_temp("last_damage_from",me);
                
                message_vision(YEL "            ת\n" NOR,me);
                simulate_set(target,shadow);
                COMBAT_D->do_attack(shadow,target,msg);
                if (target->query_temp("damaged_during_attack"))
                                        target->set_temp("last_damage_from",me);
                
                message_vision(HIW "                    ��\n" NOR,me);
                simulate_set(target,shadow);
                COMBAT_D->do_attack(shadow,target,msg);
           if (target->query_temp("damaged_during_attack"))
                                        target->set_temp("last_damage_from",me);
                
                message_vision(HIB "                              ��\n" NOR,me);
                simulate_set(target,shadow);
                COMBAT_D->do_attack(shadow,target,msg);
                if (target->query_temp("damaged_during_attack"))
                                        target->set_temp("last_damage_from",me);
                
                shadow->add_temp("apply/attack", -2*extra);
                shadow->add_temp("apply/damage", -2*extra);
                if (me->is_killing(target->query("id"))) cond=1;
                destruct(shadow);
        }
        else {
                if (!target->query_temp("is_unconcious"))
                        message_vision(WHT"$N��Ϊ$n��������һȦһת����$n�Ĺ��ƻ�Ϊ���Ρ�\n",target,me);
                else message_vision(WHT"$N����������Ϊ$n�Ļ������Ի�\n",target,me);
                }
        
        if (cond) 
        	
        	
                me->add_killer(target->query("id"));            
        me->add_enemy(target);
        

        if (me->query_busy()<3) me->start_busy(3);
                
        return 1;
} 
        
void simulate_set(object target, object shadow) {
        shadow->set("kee",target->query("kee"));                        
        shadow->set("sen",target->query("sen"));
        shadow->set("gin",target->query("gin"));
        shadow->set("eff_kee",target->query("eff_kee"));
   	shadow->set("eff_gin",target->query("eff_gin"));
        shadow->set("eff_sen",target->query("eff_sen"));
        shadow->set("max_kee",target->query("max_kee"));
        shadow->set("max_sen",target->query("max_sen"));
        shadow->set("max_gin",target->query("max_gin"));
        shadow->set("name",target->query("name"));
//      message_vision("my kee is "+(string)shadow->query("kee")+"\n",shadow);  
}   
