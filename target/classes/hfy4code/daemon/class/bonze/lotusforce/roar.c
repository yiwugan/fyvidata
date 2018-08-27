 // neon@fy
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP; 
void remove_effect(object target, int damage, int cor); 
int exert(object me, object target, int amount)
{
        int i, skill, limit_skill, apply_level, myexp, 
            factor, cor_damage, apply_damage, attack_points;
        object *enemy;
        string msg;
        
        if(me->query("class")!="bonze")
                return notify_fail("ֻ���˹����µĵ��Ӳ���ʹ�ã۷���ʨ�Ӻ�ݣ�\n");
        if( !me->is_fighting() )
                return notify_fail("�۷���ʨ�Ӻ��ֻ����ս����ʹ�á�\n");
        
        skill = me->query_skill("lotusforce", 1);
        if(skill < 50) return notify_fail("��ģ������ķ���̫���ˣ�\n");
        
        limit_skill = me->query_skill("essencemagic", 1);
        if(limit_skill < 80) return notify_fail("��ģ۰�ʶ��ͨ��̫��޷�����������ͨ�ľ��磡\n");
        
        if( (int)me->query("force") < 100 )     return 
                notify_fail("�������������\n");
        me->add("force", -100);
                 
        message_vision(
                HIY 
        "$N���Ƶ��أ�������ͨ������۷���ʨ�Ӻ�ݳ����Ϻȣ�\n\n"HIR"�࣭�����ޣ��� ������ �� ͷ �� �� �� �� ��\n\n"NOR YEL"����ֻ���������������죬��ʮ�����������\n\n" NOR, me);
  
        myexp = me->query("combat_exp");
        cor_damage = 0;
        apply_damage = 0; 
        enemy = me->query_enemy();
       
        for (i = 0 ; i< sizeof(enemy); i++) {
                
                if( enemy[i]&& enemy[i]->is_character()
                        && me->is_fighting(enemy[i]) )
                
                {       target = enemy[i];
                        factor = (int) target->query("combat_exp");
                        factor = 6 * factor /(myexp/2 + random(myexp)/2) + 1;
                        attack_points = COMBAT_D->skill_power(target, SKILL_USAGE_ATTACK);
                        attack_points = attack_points /1000 ;
                        
                        apply_level = (skill + limit_skill)/factor ;
                
                        if(apply_level >35){
                                msg = HIW"$n���ö�Ĥһ�����ͷ�����ѣ�һʱ������飡\n" NOR;
                                apply_damage = 4 * apply_level/100 *  attack_points;
                                target->add_temp("apply/attack", -apply_damage);
                                cor_damage = target->query_cor()/2 ;
                                cor_damage = cor_damage*apply_level/40 ;       
                                cor_damage = (cor_damage < target->query_cor()/2 ) ? cor_damage : target->query_cor()/2; 
                                target->add_temp("apply/courage", -cor_damage);
                        } 
                        else if (apply_level >25) {
                                msg = HIB"$n���ö�Ĥ����ʹ�����߶���Щģ�����壡\n" NOR;
                                apply_damage = 3 * apply_level/100 *  attack_points;
                                target->add_temp("apply/attack", - apply_damage);
                                cor_damage = 3 * target->query_cor()/10 ;
                                cor_damage = cor_damage*apply_level/34 ; 
                                cor_damage = (cor_damage < 3*target->query_cor()/10 ) ? cor_damage : 3* target->query_cor()/10; 
                                target->add_temp("apply/courage", -cor_damage);
                                
                        }
                        else if (apply_level >15) {
                                msg = HIR"$n���ö�Ĥһ���ֽŶ���Щ����ĸо���\n"NOR;
                                apply_damage = 2 * apply_level/100 *  attack_points ;
                                target->add_temp("apply/attack", -apply_damage);
                        }
                        else {
                                msg = YEL"$n�ľ���ˮ��$N��ʨ�Ӻ�$n��������ƽˮ������\n" NOR;                            
                        }
        
                //      COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
                        if (apply_damage || cor_damage)
                        target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
                                           apply_damage, cor_damage :),  apply_level/3 );
                        message_vision(msg, me, target);
        
                }
        }                                
        me->start_busy(2);
        return 1;
} 
void remove_effect(object target, int damage, int cor)
{       
        target->add_temp("apply/attack", damage);
        target->add_temp("apply/courage", cor);                                                                                           
        
        if(!target||!living(target)||target->is_ghost())
                return ;
        tell_object(target, CYN"��������˵�����������ʧ�����񽥽�����������\n"NOR);
}
   
