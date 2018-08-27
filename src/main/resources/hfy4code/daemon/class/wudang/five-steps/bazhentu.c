#include <ansi.h>
#include <combat.h>
inherit SSERVER;
string single_perform(object target, object me, int myexp, int skill); 
int perform(object me, object target)
{
        string msg;
        int myexp, ownexp, ownskill;
        int skill, gin_cost, i, extra, boosted;
        string *style = ({
        HIY"�����ţݣ� $N��Ӱ�ӹ�����ɳ���ֳ�������$n��$l��"NOR,
        HIG"�����ţݣ� $N��ʽ���಻�����罭�����˽�$n�ȵô�����������"NOR,
        RED"�����ţݣ� $N�ڽ��Ľ����ľ�������$n���˹�ȥ��"NOR,
        CYN"�۶��ţݣ� $N��������������ʮ��ױ���ض�����"NOR,
        HIM"�۾��ţݣ� $N���а���������һ��������������$n��$l��"NOR,
        HIB"�����ţݣ� $N�������ڵ�ɱ���������������������$n��"NOR,
        HIC"�۾��ţݣ� $N��һ�һ��ǿ�������������һ�����$n��$l��"NOR,
        WHT"�ۿ��ţݣ� $N��Ѹ��է�֣���ȡ$n��$l��"NOR});
        object ob,*obs,*myteam,*env; 
        skill = (int) me->query_skill("five-steps",1);
        gin_cost = (int)me->query_int() + 45;
        /*if ((string)me->query("class") != "wudang")
                return notify_fail(WHT"�㲻���䵱���ӣ������ݱ䡸����ͼ����\n"NOR); */
        if( !skill || (skill < 100))
                return notify_fail(WHT"�����������������, �����ݱ䡸����ͼ����\n"NOR);
        
        if( me->is_fighting() ) {
                myexp = (int) me->query("combat_exp");
                if( !target ) target = offensive_target(me);
                if( !target
                        || !target->is_character()
                        || !me->is_fighting(target) )
                return notify_fail("������ͼ��ֻ�ܶ�ս���еĶ���չ����\n"); 
       /*Single player perform*/
        if (!me->query_team()) { 
                single_perform(target, me, myexp, skill/2);
                return 1;
                }
                
        if (member_array(target,myteam=me->query_team())!=-1) 
           return notify_fail("�㲻�ܹ������ѡ�\n"); 
//      Here is the checking to excluding all that not satisfy the condition.   
        obs = ({});
        env=all_inventory(environment(me));
        for (i=0;i<sizeof(env);i++) {
                if (member_array(env[i],myteam)==-1) continue;
                if (env[i]->is_busy()) continue;
                if (!env[i]->query_skill("five-steps")) continue;
                if (env[i]->query_skill_mapped("dodge") != "five-steps"
                        && env[i]->query_skill_mapped("move") != "five-steps")  continue;
                if (env[i]->query_skill("five-steps",1)<100) continue;
                obs += ({ env[i] });
                if (sizeof(obs)>=8) break;
        }
         
        if (sizeof(obs)<2) {
                single_perform(target, me, myexp, skill);
                return 1;
        } 
                /* team perform*/
                else { 
//===============Team==================================================
                        if(skill<160) {
                                single_perform(target, me, myexp, skill);
//                              return notify_fail(WHT"��ԡ�����ͼ������ⲻ���Է����󷨣�\n"NOR);
                                return 1;
                        }
                        
                        // confirm everyone using five-steps
                        if(sizeof(obs) > 8 ) {
                                single_perform(target, me, myexp, skill);
                                return notify_fail("������ͼ�������˸��ˣ���\n");
                        }
                        
                        myexp =0;
                        extra=0;
                        
                        for(i=0;i<sizeof(obs);i++)
                        {
                                myexp += (int) obs[i]->query("combat_exp");
                           extra += (int) obs[i]->query_skill("five-steps");
                        }
                        ownskill=me->query_skill("five-steps");
                        ownexp=me->query("combat_exp");
                                
                        message_vision(MAG"\nֻ��$N"NOR MAG"������һ�䣬�������˾����ݼ�"YEL" �ݡ������ˡ��š���������������"MAG" ����λ�ã��ܳ�"WHT"������ͼ��"MAG"��\n"NOR, me);
                        if ( random(myexp)*5/i + ownexp/2 > (int) target->query("combat_exp") ){
                                msg = HIR"$Nֻ��ɭɭɱ��ֱ͸��ͷ��Ω����ʯ��룬�Ѿ�ƽ�����ɳ�������ص���ɽ��\nһʱ�ĵ��Ժ����粽���ƣ�\n\n"NOR;
                                if (target->query_busy()<=2) target->start_busy(2);
                                target->receive_damage("sen", ownskill + 3*random(extra)/i ,me);
                        }
                        else{
                                msg = HIW"\n$N��̤���ţ���ת�����ֵ�������ͼ����Χ����\n"NOR;
                        }
                        extra = extra/i ;       
                        message_vision(msg, target);
                        
                        for(i=0;i<sizeof(obs);i++)
                        {
                                msg = HIR +  style[i] + NOR;
                                obs[i]->add_temp("apply/attack", extra/2);
                                obs[i]->add_temp("apply/damage", extra);
                                COMBAT_D->do_attack(obs[i],target, TYPE_PERFORM,msg);
                                obs[i]->kill_ob(target);        
                                obs[i]->add_temp("apply/attack", -extra/2);
                                obs[i]->add_temp("apply/damage", -extra);
                                obs[i]->start_busy(3);
                        }
                        return 1; 
//===============End Team==================================================
                }
        }
        else {
                if( (int)me->query("force") < 70 )
                        return notify_fail("�������������û����������������ͼ����\n");
                if( (int)me->query("gin") < gin_cost )
                        return notify_fail("�������޷����о�������������ͼ����\n"); 
                msg = MAG"$N����չ������ͼ��"HIY" �� "HIG"ľ "HIC" ˮ "HIR" �� "NOR YEL" �� "MAG"���в������������󷨡�����ͼ���С�\n" NOR;
                message_vision(msg, me);
                me->start_busy(random(3)+1);
           if (skill*skill*skill*3/5>me->query("combat_exp"))
                        return notify_fail(WHT"���ʵս���黹������һ�����򡸰���ͼ����\n"NOR);
                if (skill>=200 || skill>=200-me->query("betrayer")*20) 
                        return notify_fail(WHT"���Ѿ�����ͨ���ݱ�������һ�����򡸰���ͼ���ˣ�\n"NOR);
                me->add("force", -70);
                me->add("gin", -gin_cost);
                me->improve_skill("five-steps",  random((int)me->query_int()) + 1);
                return 1;
        }
} 
string single_perform(object target, object me, int myexp, int skill) {
                string msg = MAG"\nֻ��$N"NOR MAG"������һ�䣬�����ݼ�"YEL" �ݡ������ˡ��š���������������"MAG" �ܳ�"WHT"������ͼ��"MAG"��\n"NOR;
                msg += WHT"\n��ʱ�����������ɳ��ʯ������ǵء�$nֻ��������ӿ�����罣��֮����\n"NOR;
                if ( skill*(random(myexp)/40) + (myexp/2) > (int) target->query("combat_exp") ){
                        msg+= HIR"ɭɭɱ��ֱ͸$n��ͷ��Ω����ʯ��룬�Ѿ�ƽ�����ɳ�������ص���ɽ��\n$nһʱ�ĵ��Ժ����粽���ƣ�\n\n"NOR;
                                if (target->query_busy()<2) target->start_busy(2);
                                if (target->query("no_busy")) me->start_busy(2);
                                        else me->start_busy(3);
                                target->receive_wound("sen",5*random(skill)/2, me);
                                target->receive_damage("sen", skill*5/2,me);         
//                      average 750, lowest 500, highest 1000                           
                                message_vision(msg, me, target);
                                COMBAT_D->report_status(target);
                                COMBAT_D->win_lose_check(me,target,1);
                }
                else {
                        msg+= HIW"\n$n��̤���ţ���ת��ת�����ˡ�����ͼ����Χ����\n"NOR;
                        me->start_busy(2);
                        message_vision(msg, me, target);
                }                
}
                            
