 // combatd.c
// Copyright (C) 1995 - 2002, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
// Last modification:
//              - 07/02/2001 by Daniel Q. Yu.
//                      * Put in counter_attack etc.
//              - 07/14/2001 by Daniel Q. Yu.
//                      * Fix some counter_attack message problems.
//              - 07/17/2001 by Daniel Q. Yu.
//                      * Add counter_attack messages.
//              - 07/20/2001 by Daniel Q. Yu.
//                      * Change death penalty.
//              - 04/17/2002 by Neon
//                      * Change report_status
//              - 04/26/2002 by silencer
//                      * added magic/spells check in winner/loser
//                      * added function win_lose_check()
//                      * added alternate death penalty for certain areas.
//              - 07/22/2002 by silencer
//                      * fixed damage report in weapon damage, it reported only random(damage).
//              - 10/12/2002 by love
//                      * add items' hit_ob,parry_ob,dodge_ob 
//#pragma optimize
#define LOWER_LIMIT 200000   //�Ӵ�㣬��ֹ������� by xiaolang
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h> 
int give_reward(object who,mapping quest);
mapping get_action(object me, int attack_type); 
string *guard_msg = ({
        CYN "$Nע����$n"NOR+CYN"���ж�����ͼѰ�һ���һ���ɹ���\n" NOR,
        CYN "$N������$n"NOR+CYN"��һ��һ������ʱ׼���������ơ�\n" NOR,
        CYN "$N����Ϊ������Ҫ�ҳ�$n"NOR+CYN"��������\n" NOR,
        CYN "$N�������ƶ��ŽŲ����ȴ�����ѵĳ��з�λ��\n" NOR,
        CYN "$N�۾�գҲ��գ�ض���$n"NOR+CYN"���Ż����֡�\n" NOR,
}); 
string *catch_hunt_msg = ({
   HIW "$N��$n"NOR+HIW"������������ۺ죬���̴���������\n" NOR,
        HIW "$N����$n"NOR+HIW"��ȣ����ɶ������㣡��\n" NOR,
        HIW "$N��$n"NOR+HIW"һ���棬������˵�ʹ���������\n" NOR,
        HIW "$Nһ��Ƴ��$n"NOR+HIW"�����һ�����˹�����\n" NOR,
        HIW "$Nһ����$n"NOR+HIW"�����һ㶣���У����������㣡��\n" NOR,
        HIW "$N�ȵ�����$n"NOR+HIW"�����ǵ��ʻ�û���꣬���У���\n" NOR,
        HIW "$N�ȵ�����$n"NOR+HIW"�����У���\n" NOR,
}); 
string *winner_msg = ({
        CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR,
        CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR,
        CYN "\n$Nʤ�����У�����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
        CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
        CYN "\n$n�������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
        CYN "\n$n����һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
}); 
string *counter_msg = ({
        HIR "$N"HIR"ȫȻ����$n"NOR+HIR"�Ĺ������Կ��ƿ졣\n" NOR,
        HIR "$N"HIR"�����Ա��������������ϡ�\n" NOR,
}); 
object protector;
int attacker_damage = 0;
int victim_damage = 0;
int protector_damage = 0;
string parry_message = "";
string dodge_message = "";
string protect_message = "";
string counter_message = "";
string damage_message = "";
string inflict_message = "";
string result_message = ""; 
void create() {
        seteuid(ROOT_UID);
} 
string damage_msg(int damage, string type) {
        string str; 
        if(damage <= 0) {
                return "���û������κ��˺���\n";
        }
//  write(" damage is "+(string)(damage)+". \n"); 
        switch( type ) {
                case "����":
                case "����":
                        if( damage < 100 ) return "���ֻ������ػ���$n��Ƥ�⡣\n";
                        else if( damage < 200 ) return "�����$n��$l����һ��ϸ����Ѫ�ۡ�\n";
                        else if( damage < 400 ) return "������͡���һ������һ���˿ڣ�\n";
                        else if( damage < 800 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                        else if( damage < 1600 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
                        else return "���ֻ����$nһ���Һ���$n$l������һ������ǵĿ����˿ڣ���\n";
                        break;
                case "����":
                        if( damage < 100 ) return "���ֻ������ش���$n��Ƥ�⡣\n";
                        else if( damage < 200 ) return "�����$n$l�̳�һ�����ڡ�\n";
                        else if( damage < 400 ) return "������ۡ���һ��������$n$l����\n";
                        else if( damage < 800 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
                        else if( damage < 1600 ) return "��������͡���һ����$n$l�ѱ��̳�һ��Ѫ��ģ����Ѫ������\n";
                        else return "���ֻ����$nһ���Һ���$n��$l���Դ���������Ѫ�������أ���\n";
                        break;
                case "����":
                        if( damage < 50 ) return  "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                        else if( damage < 100 ) return "�����$n��$l���һ�����ࡣ\n";
                        else if( damage < 200 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
                        else if( damage < 400 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                        else if( damage < 800 ) return "������项��һ����$n����������\n";
                        else if( damage < 1200 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
                        else if( damage < 1600 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                        else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
                        break;
                case "ץ��":
                        if( damage < 50 ) return "���ֻ�������ץ������ץ����΢���˵㡣\n";
                        else if( damage < 100 ) return "�����$n��$lץ������Ѫ�ۡ�\n";
                        else if( damage < 200 ) return "���һץ���У�$n��$l��ץ����Ѫ�ɽ���\n";
                        else if( damage < 400 ) return "������͡���һ����$l��ץ����ɼ��ǣ���\n";
                        else if( damage < 800 ) return "���һץ���У�$n��$l��ץ��Ѫ���ɣ�����\n";
                        else if( damage < 1200 ) return "�����һ�¡��͡���һ��ץ��$n���κü��£���һ��ˤ����\n";
                        else if( damage < 1600 ) return "���$n����һ����$l��ץ�ý�Ϲ��ۣ���\n";
                        else return "���ֻ����$nһ���Һ���$l��ץ�����Ѫ��������Ѫ�������أ���\n";
                        break;
           case "������":
                        if( damage < 10 ) return "$N�ܵ�$n$z�ķ����ƺ�һ����\n";
                        else if( damage < 20 ) return  "$N��$n��$z�����Ѫ���ڣ���ʧɫ��\n";
                        else if( damage < 40 ) return "$N��$n��$z���վ�����ȣ�ҡҡ�λΡ�\n";
                        else if( damage < 80 ) return "$N��$n��$z���𣬡��١���һ������������\n";
                        else if( damage < 160 ) return "$N��$n��$z����������������ð����顣\n";
                        else if( damage < 240 ) return "$N��$n��$z������һ���ؿ������ܵ�һ���ػ�����������������\n";
                        else if( damage < 320 ) return "$N��$n��$zһ����ǰһ�ڣ���������ɳ�������\n";
                        else return "$N��$n��$zһ����ǰһ�ڣ�������Ѫ������������ߵķ��������ȥ����\n";
                        break;
                default:
                        if(!type) type = "�˺�";
                        if(damage < 50) str =  "���ֻ����ǿ���һ����΢";
                        else if( damage < 100 ) str = "��������΢��";
                        else if( damage < 200 ) str = "������һ��";
                        else if( damage < 400 ) str = "������һ������";
                        else if( damage < 600 ) str = "��������Ϊ���ص�";
                        else if( damage < 800 ) str = "�������൱���ص�";
                        else if( damage < 1200 ) str = "������ʮ�����ص�";
                        else if( damage < 1600 ) str = "�����ɼ������ص�";
                        else str =  "�����ɷǳ����µ�����";
                        return str + type + "��\n";
                }
} 
//dam_type, kee:1 sen:2 gin:3, default =1
string eff_status_msg(int ratio, int dam_type) {
        if( ratio==100 ) return HIG "�������ϲ���˿���˺ۡ�" NOR;
        if( ratio > 95 ) return HIG "�ƺ�ֻ���˵����ˣ������˴��塣" NOR;
        if( ratio > 90 ) {
                if (dam_type == 3)
                        return HIY "������Щή�ң�����������" NOR;
                else if (dam_type == 2)
                        return HIY "�����ƺ�����Щ���ˣ������е㽩Ӳ��" NOR;
                else    return HIY "�������˼���Ƥ���ˡ�" NOR;
        }
        if( ratio > 80 ) return HIY "���˼������ˣ��ƺ��������¡�" NOR;
        if( ratio > 60 ) {
                if (dam_type == 3)
                        return HIY "������飬���ύ����" NOR;
           else if (dam_type == 2)
                        return HIY "�����Ȼ�������о�Ȼ����Ѫ������" NOR;
                else    return HIY "�������˲��ᣬ��������Ѫ��" NOR;
        }
        if( ratio > 40 ) {
                if (dam_type == 3)
                        return HIY "�沿�鴤��ֹ���Ѿ������Լ���" NOR;
                else    return HIR "��Ѫ��ֹ������ɢ�ң��Ѿ���������·�ˡ�" NOR;
        }
        if( ratio > 30 ) return HIR "�˺����ۣ���������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�������ˣ�ֻʣ�����һ�����ˡ�" NOR;
        if( ratio > 10 ) return RED "����ԡѪ����Ҫ���ڵ��ϡ�" NOR;
        if( ratio > 5  ) return RED "ͫ�շŴ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
        return RED "����в�����ʱ�����ܶ�����" NOR;
} 
//dam_type, kee:1 sen:2 gin:3, default =1
string status_msg(int ratio, int dam_type) {
        if( ratio==100 ) return HIG "�������棬�������㣬" NOR;
        if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if( ratio > 90 ) return HIY "������������Щ���ã�" NOR;
        if( ratio > 80 ) {
                if (dam_type == 3)
                        return HIY "�����е㲻�㣬���Թ��ش��ݣ�" NOR;
                else if (dam_type == 2)
                        return HIY "������Щ��㱣�����Ӧ�����磬" NOR;
                else    return HIY "�����е㲻̫��⣬�����������ɣ�" NOR;
        }
        if( ratio > 60 ) {
                if (dam_type == 3)
                        return HIY "�ж���Ȼ�ް����������Ը������ˣ�" NOR;
                else if (dam_type == 2)
                        return HIY "��Ӧ��ʼ�ٻ���˫Ŀ����" NOR;
                else    return HIY "�������꣬��ɫ�Ұף�" NOR;
        }
        if( ratio > 40 ) {
                if (dam_type == 3)
                        return HIR "������ɢ���ƺ���ʹ����ʧȥ֪����" NOR;
                else if (dam_type == 2)
                        return HIR "�۹����룬����������" NOR;
           else    return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˣ�" NOR;
        }
        if( ratio > 30 ) return HIR "ͷ�ؽ��ᣬ��������֧����������ȥ��" NOR;
        if( ratio > 20 ) {
                if (dam_type == 3)
                        return HIR "�����Ѿ���ľ�����ˣ�" NOR;
                else if (dam_type == 2)
                        return HIR "�������Ѿ��겻�����ˣ�" NOR;
                else    return HIR "�������Ѿ����������ˣ�" NOR;
        }
        if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб�������ε���" NOR;
        return RED "�Ѿ���������״̬������ȫʧ��" NOR;
} 
varargs void report_status(object ob, int i) {
        int eff_ratio = 100;
        int ratio = 100;
        int k_stat, g_stat, s_stat;
        int d_type = 1;
        int e_type = 1; 
        k_stat = (int) ob->query("kee") * 100 / (int)ob->query("max_kee");
        s_stat = (int) ob->query("sen") * 100 / (int)ob->query("max_sen");
        g_stat = (int) ob->query("gin") * 100 / (int)ob->query("max_gin"); 
        if (ratio > k_stat ) {
                ratio =  k_stat;
        }
        if (ratio > s_stat ) {
                ratio =  s_stat;
                d_type = 2;
        }
        if (ratio > g_stat ) {
                ratio =  g_stat;
                d_type = 3;
        } 
        k_stat = (int) ob->query("eff_kee") * 100 / (int)ob->query("max_kee");
        s_stat = (int) ob->query("eff_sen") * 100 / (int)ob->query("max_sen");
        g_stat = (int) ob->query("eff_gin") * 100 / (int)ob->query("max_gin"); 
        if (eff_ratio > k_stat ) {
                eff_ratio =  k_stat;
        }
   if (eff_ratio > s_stat ) {
                eff_ratio =  s_stat;
                e_type = 2;
        }
        if (eff_ratio > g_stat ) {
                eff_ratio =  g_stat;
                e_type = 3;
        } 
        message_vision("( $N" + status_msg(ratio, d_type) + eff_status_msg(eff_ratio, e_type) + " )\n", ob); 
}  
// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
int skill_power(object ob, int usage) {
        int status, level, enc, max_enc, result;
        int bonus, exp;
        string skill;
        object weapon;
        string wptype,pski; 
        // Check for the total weight a player is carrying.
        // Skill power will descrease as you carry more things.
        // NPC does not have this restrication.
        if(!userp(ob)) {
                enc = 10;
        } else {
                max_enc = (int)ob->query_max_encumbrance();
                max_enc = max_enc > 0 ? max_enc : 1;
                enc = (max_enc  + max_enc/10 - 1 - (int) ob->query_encumbrance() ) * 10 / max_enc;
        } 
        level = 1;
        switch(usage) {
                case SKILL_USAGE_ATTACK:
                        skill = objectp(weapon = ob->query_temp("weapon")) ? weapon->query("skill_type") : "unarmed";
                        level = ob->query_skill(skill);
                        level += ob->query_temp("apply/attack");
                        level += ob->query_temp("apply/"+skill);//let's have apply/axe,apply/unarmed��������Ч��
                        bonus= ob->query_temp("bonus/attack");
                        break;
                case SKILL_USAGE_DODGE:
                        level = ob->query_skill("dodge");
                   level += ob->query_temp("apply/dodge");
                        level += ob->query_temp("apply/defense");
                        bonus= ob->query_temp("bonus/dodge");
                        break;
                case SKILL_USAGE_PARRY:
                        skill = objectp(weapon = ob->query_temp("weapon")) ? "parry" : "unarmed";
                        if(objectp(weapon))
                        {
                                wptype=weapon->query("skill_type");
                                if(stringp(pski=ob->query_skill_mapped(skill)))
                                if(SKILL_D(pski)->valid_enable(wptype))
                                        level = ob->query_skill(skill);
                                else
                                        level = ob->query_skill(skill,1)/2;
                        }
                        else    {
                                level=ob->query_skill("parry",1)/2;
                                if (ob->query_skill_mapped(skill))
                                        level += ob->query_skill(ob->query_skill_mapped(skill));
                        }
                        level += ob->query_temp("apply/parry");
                        level += ob->query_temp("apply/defense");
                        bonus= ob->query_temp("bonus/parry");
                        break;
                case SKILL_USAGE_MOVE:
                        level = ob->query_skill("move");
                        level += ob->query_temp("apply/move");
                        bonus= ob->query_temp("bonus/move");
                        break;
        }
        if (level > 10000) level = 10000;    //add by xiaolang ��ֹ���
        if (bonus > 10000) bonus = 10000;    // add by xiaolang
        result = level/10*level/10*level/5;
        if(bonus>0)
                result+=bonus/10*bonus/10*bonus/5;
        if((status = ob->query("kee")) > 0 ) {
                if(status<ob->query("max_kee"))
                result = status*100/ob->query("max_kee")*result/100;
        } else {
                result = result /4000;
        }
   exp=(int)(ob->query("combat_exp")/25);
        if(ob->query("sen") > 0 && ob->query("gin") > 0) {
                status=3*ob->query("sen")+ob->query("gin");
                if(status<3*ob->query("max_sen")+ob->query("max_gin"))
                exp = status*100/(3*ob->query("max_sen")+ob->query("max_gin"))*exp/100;
        } else {
                exp = exp /4000;
        }
        result = result + exp;
        result = result * enc / 10;
        return result > 1 ? result : 1;
} 
// Reward the winner.
void fight_reward(object winner, object loser) {
        object owner; 
        if(owner=winner->query("possessed")) {
                winner = owner;
        }
        winner->win_enemy(loser);
} 
// Penalize the loser.
void fight_penalty(object winner, object loser) {
        object owner; 
        if(owner=loser->query("possessed")) {
                loser = owner;
        }
        loser->lose_enemy(winner);
} 
string prepare_final_message(object attacker, object victim,string w_name, string vw_name,mapping action, string result) {
        string output, *limbs, limb; 
        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        output = replace_string(result, "$l", limb );
        if(stringp(vw_name)) {
                output = replace_string(output, "$v", vw_name);
        }
        if(victim->query_skill_mapped("iron-cloth")) {
                output = replace_string(output, "$z",  SKILL_D(victim->query_skill_mapped("iron-cloth"))->name());
        }

        if(stringp(w_name)) {
                output = replace_string(output, "$w", w_name);
        } else if(stringp(action["weapon"])) {
                output = replace_string(output, "$w", action["weapon"] );
        }
        return output;
} 
// attack_damage
// Return the damage an attack can do
int attack_damage(object attacker, mapping action, object victim) {
        int damage, damage_bonus, force_factor, bounce, att_combat_exp;
        string force_skill, attack_skill, martial_skill;
        object attweapon;
        mixed tmp;
        function f; 
        damage_message = "";
        // Weapon damage
        attweapon = attacker->query_temp("weapon");
        damage = (attacker->query_temp("apply/damage"))+ 2;
        damage = (damage + random(damage)) / 2; 
        // Action damage
        if(action["damage"]) {
                damage += action["damage"] * damage / 1000;
        } 
        // Strength damage bonus.
        damage_bonus = attacker->query_str();
        damage_bonus = damage_bonus * damage_bonus / 10;
        // if use weapon, effectiveness only 3/4
        if(attweapon) {
                damage_bonus -= damage_bonus/4;
        } 
        // Let force skill take effect.
        force_factor = attacker->query("force_factor");
        if(force_factor && (force_skill = attacker->query_skill_mapped("force"))) {
                tmp = SKILL_D(force_skill)->hit_ob(attacker, victim, damage_bonus, force_factor);
                if(stringp(tmp) ) {
                        damage_message += tmp;
                } else if(intp(tmp)) {
                        damage_bonus += tmp;
           }
        } 
        // Action force damage
        if(action["force"]) {
                damage_bonus += action["force"] * damage_bonus / 1000;
        } 
        // Attack Skill damage
        if(objectp(attweapon)) {
                attack_skill = attweapon->query("skill_type");
        } else {
                attack_skill = "unarmed";
        } 
        if(martial_skill = attacker->query_skill_mapped(attack_skill) ) {
                tmp = SKILL_D(martial_skill)->hit_ob(attacker, victim, damage_bonus);
                if(stringp(tmp) ) {
                        damage_message += tmp;
                } else if(intp(tmp)) {
                        damage_bonus += tmp;
                }
        } 
        // Let weapon or monster have their special damage.
        if(objectp(attweapon)) {
                tmp = attweapon->hit_ob(attacker, victim, damage_bonus);
                if(stringp(tmp) ) {
                        damage_message += tmp;
                } else if(intp(tmp)) {
                        damage_bonus += tmp;
                }
                if(functionp(f=attweapon->query_temp("hit_ob",1)))
                {
                        tmp=evaluate(f,attacker, victim, damage_bonus);
                        if(stringp(tmp) )
                        {
                                damage_message += tmp;
                        }
                        else if(intp(tmp))
                        {
                                damage_bonus += tmp;
                        }
           } 
        } else {
                tmp = attacker->hit_ob(attacker, victim, damage_bonus);
                if(stringp(tmp) ) {
                        damage_message += tmp;
                } else if(intp(tmp)) {
                        damage_bonus += tmp;
                }
        } 
        // Add damage bonus.
        if(damage_bonus > 0) {
                damage += (damage_bonus + random(damage_bonus))/2;
        } 
        // Let combat exp take effect
        bounce = victim->query("combat_exp");
        att_combat_exp = attacker->query("combat_exp");
        while(random(bounce) > att_combat_exp && damage > 0) {
                damage -= damage / 5;
                bounce/= 2;
        } 
        // See how much damage our flexibility can absorb
        damage = damage - ((int)victim->query_fle())
                        - ((int)victim->query_temp("apply/extra_fle")); 
        if(damage < 0) damage = 0;
        return damage*3;
} 
// inflict_damage
// Inflict damange on the victim.
int inflict_damage(object attacker, object victim, int damage, mapping action) {
        int absorb_vic, bounce, wounded,s_ratio,s_force,eff_ness, total_damage;
        string absorb_skill,s_msg,s_type;
        mapping shield;
        object weapon; 
        inflict_message = "";
        weapon=attacker->query_temp("weapon");
        // how much absort_vic?
        if(random(100)>5)
        {
                if(victim->query_skill("iron-cloth")) {
                   absorb_skill = victim->query_skill_mapped("iron-cloth");
                        if(!absorb_skill) {
                        absorb_skill = "iron-cloth";
                        }
                        if (eff_ness=SKILL_D(absorb_skill)->effect());
                                else eff_ness=100;
                }
                absorb_vic = 2*victim->query_skill("iron-cloth")*eff_ness/100 +
                                victim->query_temp("apply/iron-cloth");
                if(victim->query_skill("iron-cloth")) {
                        absorb_skill = victim->query_skill_mapped("iron-cloth");
                        if(!absorb_skill) {
                        absorb_skill = "iron-cloth";
                        }
                        inflict_message += SKILL_D(absorb_skill)->query_absorb_msg();
                }
        // -> Debug Message
        //      message_vision("$N's attack absorbed by  "+ SKILL_D(absorb_skill)->name()
        //           + "with, eff_ness " + (string) eff_ness +", absorb_vic: "
        //           +  (string) absorb_vic+".\n", this_player())       ;
        // <- Debug message 
        // damage vs absorb_vic
//              message_vision(" before absorption, damage is "+(string)(damage)+". \n",this_player());
                damage -= absorb_vic;
//              message_vision(" after absorption, damage is "+(string)(damage)+". \n",this_player());
        }
        if(damage <= 0) {
                absorb_skill = victim->query_skill_mapped("iron-cloth");
                if(absorb_skill) {
                        bounce = (SKILL_D(absorb_skill)->bounce_ratio()) * (-damage) / 100;
                        if (objectp(weapon)) {
                                if (weapon->query("skill_type")=="throwing")
                                        bounce = bounce/100;
                                if (weapon->query("skill_type")=="whip")
                                        bounce = bounce/10;
                        }
                        absorb_skill = attacker ->query_skill_mapped("iron-cloth");
                        if(absorb_skill) {
                                bounce -= (SKILL_D(absorb_skill)->bounce_ratio()) * attacker->query_skill("iron-cloth") / 100;
                   }
//                      message_vision(" bounce damage is "+(string)(bounce)+". \n",this_player());
                        if(bounce > 0) {
                                attacker->receive_damage("kee", bounce, victim);
                                inflict_message += damage_msg(bounce, "������");
                                total_damage=-bounce;
                        }
                }
        } else {
                if(shield=victim->query_temp("shield_force"))
                { 
                                s_type=shield["type"];
                                s_ratio=shield["ratio"];
                                s_msg=shield["msg"];
                                s_force=victim->query(s_type)*s_ratio/100; 
                                if(stringp(s_type))
                                if(s_force>0)
                                if(damage<s_force)
                                        {
                                                victim->add(s_type,-damage*100/s_ratio);
                                                damage=0;
                                                inflict_message+=s_msg;
                                                return damage;
                                        }
                                        else
                                        {
                                                damage-=s_force;
                                                victim->set(s_type,0);
                                        }
                }
                        victim->receive_damage("kee", damage, attacker); 
        // (9) wizard debug information. --- pure kee damage
                if(wizardp(attacker) && (string)attacker->query("env/combat1")=="verbose" ) {
                        tell_object(attacker, sprintf(HIW "DAMAGE:%d\t\n" NOR, damage));
                }
                if(wizardp(victim) && (string)victim->query("env/combat1")=="verbose" ) {
                        tell_object(victim, sprintf(HIY "DAMAGE STATUS:\tYour Kee Damage:%d\t\n" NOR, damage));
                } 
                total_damage = damage;                   //     that's the real damage 
           if((attacker->is_killing(victim)) || weapon) {
                        damage = random(damage);        // that's the eff_damage
                        if(damage > (int)victim->query_temp("apply/armor") ) {
                                victim->receive_wound("kee",
                                                damage - (int)victim->query_temp("apply/armor"), attacker);
                        }
                }
        }  
//      write(" damage is "+(string)(total_damage)+". \n");
//      Here we should report total damage, since it's possible to do a 10000 kee damage
//      while only 10 eff_damage ....  only the first value is useful for players.
        if(bounce<=0||damage>0)
                inflict_message += damage_msg(total_damage, action["damage_type"]);
//      message_vision(" total damage returned is "+(string)(total_damage)+". \n",this_player());
        return total_damage;
} 
// dodge_attack
// the function that checks if the attack can be dodged.
int dodge_attack(object attacker, int ap, mapping action, object victim) {
        int dp;
        string dodge_skill,attack_skill;
        mixed tmp;
        object att_weapon,boot;
        function f; 
        dodge_message = ""; 
        if(objectp(att_weapon=attacker->query_temp("weapon")))
        {
                attack_skill=attacker->query_skill_mapped(att_weapon->query("skill_type"));
                if(attack_skill)
                if(SKILL_D(attack_skill)->undodgeable())
                        return 0;
        }
        else
        {
                attack_skill=attacker->query_skill_mapped("unarmed");
                if(attack_skill)
                if(SKILL_D(attack_skill)->undodgeable())
                        return 0;
        }
// if(victim->query_busy())
//              return 0;
//      message_vision("try dodge\n",victim);
        // victim has no action point
/*      if(!victim->actionOK()) {
                return 0;
        }
*/   
        // Get base dodge power.
        dp = skill_power(victim, SKILL_USAGE_DODGE); 
        // Take into account of attacker's action.
        if(action["dodge"]) {
                dp -= dp * action["dodge"] / 1000 ;
        } 
        // Take into account of victim is busy or not.
        if(victim->is_busy()) {
                dp /= 5;
        } 
        // Debug message
        if(wizardp(attacker) && (string)attacker->query("env/combat1")=="verbose" ) {
                tell_object(attacker, sprintf(HIW "DP:%d\t" NOR, dp));
        }
        // Debug message ends 
        // minimum dp is 1.
        dp = dp > 0 ? dp : 1; 
        // Did the victim dodge the attack?
        if( random(ap + dp) < dp ) {
                // Get dodge messages.
                dodge_skill = victim->query_skill_mapped("dodge");
                if(!dodge_skill) {
                        dodge_skill = "dodge";
                }
                dodge_message = SKILL_D(dodge_skill)->query_dodge_msg();
                if(stringp(tmp = SKILL_D(dodge_skill)->dodge_ob(attacker, victim))) {
                        dodge_message += tmp;
                }
                //����ȷ����ֻ��Ь�ӿ�����dodge_ob��Ҫ��Ȼ�ͳ������ˡ�
                //love
                //10/12/2002

                if(objectp(boot=victim->query_temp("armor/boots")))
                {
                        if(functionp(f=boot->query_temp("dodge_ob",1)))
                        {
                                tmp=evaluate(f,attacker, victim);
                                if(stringp(tmp) )
                                {
                                        parry_message += tmp;
                                }
                        }
                }
                // Give combat_exp for dodge attack.
                if(ap > dp && (!userp(victim) || !userp(attacker))
                                && random(victim->query("gin")*100/victim->query("max_gin")
                                                + victim->query_int())>50) {
                        victim->add("combat_exp", 1);
                        if (victim->query_skill("dodge",1)<200) victim->improve_skill("dodge", 1);
                }
                return dp;
        } else {
                return 0;
        }
} 
// parry_attack
// the function that checks if the atack can be parried.
int parry_attack(object attacker, int ap, mapping action, object victim) {
        string parry_skill;
        mixed tmp;
        int pp;
        object weapon,armor;
        string wptype,pski;
        function f; 
        parry_message = ""; 
        // victim has no action point
/*      if(!victim->actionOK()) {
                return 0;
        }
*/
        // Get parry skill power.
   pp = skill_power(victim, SKILL_USAGE_PARRY);
//      message_vision("do_parry\n",victim);
        // Attacker's action modifier.
        if(action["parry"]) {
                pp -= pp * action["parry"] / 1000 ;
        } 
        // Attacker has a weapon.
        if(objectp(attacker->query_temp("weapon"))) {
                pp /= 2;
        } 
        // If victim is busy...
        if(victim->is_busy()){
                pp -=pp/5;
        }
        ap=ap/2;
        // minimum pp is 1.
        pp = pp > 0 ? pp : 1;
//      message_vision("try parry\n",victim); 
        // Debug message
        if(wizardp(attacker) && (string)attacker->query("env/combat1")=="verbose" ) {
                tell_object(attacker, sprintf(HIW "PP:%d\t" NOR, pp));
        }
        // Debug message ends  
        victim->set_temp("test_ap",ap);
        victim->set_temp("test_pp",pp);
        // Did victim parry the attack?
        if(random(pp+ap)< pp) {
                // Get parry messages.
                if(weapon=victim->query_temp("weapon")){
                        wptype=weapon->query("skill_type");
                        if(pski=victim->query_skill_mapped("parry"))
                        if(SKILL_D(pski)->valid_enable(wptype))
                                parry_skill = pski; 
                        if( !parry_skill)  parry_skill = "parry";
                } else {
                        parry_skill = victim->query_skill_mapped("unarmed");
                        if(!parry_skill) parry_skill = "unarmed";
                }  
                parry_message = SKILL_D(parry_skill)->query_parry_msg(attacker->query_temp("weapon"));

                if(stringp(tmp = SKILL_D(parry_skill)->parry_ob(attacker,victim))) {
                        parry_message += tmp;
                } 
                // װ�������parry_ob���Ҹ�����Ϊֻ��1�֡�
                // ok���������������������м���һ�£���ô���ԣ�û����
                // love
                // 10/12/2002
                if(objectp(weapon))
                {
                        if(functionp(f=weapon->query_temp("parry_ob",1)))
                        {
                                tmp=evaluate(f,attacker, victim);
                                if(stringp(tmp) )
                                {
                                        parry_message += tmp;
                                }
                        }
                }
                else
                // �ţ��������û��������������һ��fist����ôҲ����������fist���м�
                if(objectp(weapon=victim->query_temp("left_hand")))
                {
                        if(functionp(f=weapon->query_temp("parry_ob",1)))
                        {
                                tmp=evaluate(f,attacker, victim);
                                if(stringp(tmp) )
                                {
                                        parry_message += tmp;
                                }
                        }
                }
                else
                // �����������ǿ�����һЩװ����parry
                // Ŀǰ�Ҹ�����Ϊ���ܵ�װ���ǣ�shield,ring,bracelet,
                // �Ҹ�����Ϊ��Щ��parry_ob�ǲ�������ģ�
                // so 1.weapon,2.secondary_weapon,3.shield,4.bracelet,5.ring,
                // �о����ø�ָ��ȥ�����е��̬�������������㻹�а�
                if(objectp(armor=victim->query_temp("armor/shield")))
                {

                        if(functionp(f=armor->query_temp("parry_ob",1)))
                        {
                                tmp=evaluate(f,attacker, victim);
                                if(stringp(tmp) )
                                {
                                        parry_message += tmp;
                                }
                        }
                }
                else
                if(objectp(armor=victim->query_temp("armor/bracelet")))
                {
                        if(functionp(f=armor->query_temp("parry_ob",1)))
                        {
                                tmp=evaluate(f,attacker, victim);
                                if(stringp(tmp) )
                                {
                                        parry_message += tmp;
                                }
                        }
                }
                else
                if(objectp(armor=victim->query_temp("armor/ring")))
                {
                        if(functionp(f=armor->query_temp("parry_ob",1)))
                        {
                                tmp=evaluate(f,attacker, victim);
                                if(stringp(tmp) )
                                {
                                        parry_message += tmp;
                                }
                        }
                }  
                // Give combat_exp for parry attack.
                if(ap > pp && (!userp(victim) || !userp(attacker))
                                && random(victim->query("gin")*100/victim->query("max_gin")
                                                + victim->query_int())>50) {
                        victim->add("combat_exp", 1);
                        if (victim->query_skill("parry",1)<200) victim->improve_skill("parry", 1);

                }
                return pp;
        } else {
                return 0;
        }
} 
// counter_attack
// the function checks if we can counter the attack.
varargs int counter_attack(object attacker, int ap, mapping action, object victim,int i) {
        mapping counter_action,w_action;
        int counterp, damage, counterResult;
        string counter_skill, dodge_skill, tmp,w_name,vw_name;
        object victim_weapon = victim->query_temp("weapon");
        object attacker_weapon=attacker->query_temp("weapon"); 
        counter_message = "";
        // victim is busy or unconcious, can't counter attack.
        if(victim->is_busy() || victim->query_temp("is_unconcious")) {
                return 0;
        }
        // get victim's counter attack action.
        counter_action = get_action(victim, 0);
        if(!mapp(counter_action)) {
                return 0;
        }
        if(i)
                counter_message+=victim->query_temp("counter_msg")+counter_action["action"]+"��\n";
        else
                counter_message += counter_msg[random(sizeof(counter_msg))]
                                + counter_action["action"] + "��\n"; 
        // Get counter attack power
        counterp = skill_power(victim, SKILL_USAGE_ATTACK); 
        // Did victim counter attack?
        if(random(ap +  counterp) < counterp) {
                // Give combat_exp for counter attack.
                if(ap > counterp && (!userp(victim) || !userp(attacker))
                                && random(victim->query("gin")*100/victim->query("max_gin") + victim->query_int())>50) {
                        victim->add("combat_exp", 1);
                        victim->improve_skill("dodge", 1);
                } 

                // NPC have chance to get exp when fail to hit.
                if(!userp(attacker) && random(attacker->query_int()) > 15) {
                        attacker->add("combat_exp", 1);
                }
                damage = attack_damage(victim, counter_action, attacker);
                counter_message += damage_message;
                damage = inflict_damage(victim, attacker, damage, counter_action);
                counter_message += inflict_message;
                if(damage > 0) {
                        attacker_damage += damage;
                } else {
                        victim_damage += -damage;
                }
                counterResult = damage;
        } else {
                dodge_skill = attacker->query_skill_mapped("dodge");
                if(!dodge_skill) {
                        dodge_skill = "dodge";
                }
                counter_message += SKILL_D(dodge_skill)->query_dodge_msg();
                if(stringp(tmp = SKILL_D(dodge_skill)->dodge_ob(attacker, victim))) {
                        counter_message += tmp;
                }
                counterResult = RESULT_DODGE;
        }
        if(objectp(attacker_weapon))
                vw_name=attacker_weapon->name();
        if(objectp(victim_weapon)) {
                w_name=victim_weapon->name();
                w_action=victim_weapon->query_action();
                if(counter_action["post_action"]) {
                        counter_message += call_other(victim_weapon, counter_action["post_action"], victim, attacker, counterResult);
                }
                else if(w_action["post_action"]&&!random(5))
                        result_message += call_other(victim_weapon, w_action["post_action"], attacker, victim, counterResult);
                else
                        counter_message += victim_weapon->wear_off(victim, attacker, counterResult); 
                //-commented out by neon to get rid of the double wear-off
                //counter_message +=  victim_weapon->wear_off(victim, attacker, counterResult);

        } 
        counter_message = prepare_final_message(victim, attacker,w_name, vw_name,counter_action, counter_message);
        counter_message = replace_string(counter_message, "$N", "$TMP");
        counter_message = replace_string(counter_message, "$n", "$N");
        counter_message = replace_string(counter_message, "$TMP", "$n");
        return counterp;
} 
// do_protect()
// a function that checks to see if there is anything/anyone protects our victim
int do_protect(object attacker, int ap, mapping action, object victim) {
        object *pros;
        string output, parry_skill;
        int pp, i, result; 
        pros = victim->query_temp("protectors");
        i = random(sizeof(pros));
        if(!pros[i]) {
                pros -= ({pros[i]});
                if(!sizeof(pros)) {
                        victim->delete_temp("protectors");
                }
                result = 0;
        // Protector
        } else if((environment(pros[i])  != environment(victim))
                        && (environment(pros[i]) != victim)) {
                result = 0;
        } else if(pros[i]->is_character()) {
                // Can't protect other people, if you are busy.
                if(pros[i]->is_busy()){
                        result = 0;
                } else {
                        // Check if the pros[i] can parry this attack for the victim.
                        result = parry_attack(attacker, ap, action, pros[i]);
                        if(result) {
                                protect_message = parry_message;
                                if(objectp(pros[i]->query_temp("weapon"))) {
                                        protect_message = replace_string(protect_message, "$v", (pros[i]->query_temp("weapon"))->name());
                                }
                        }
                }

        } else {
                result = pros[i]->protection();
                protect_message = pros[i]->protection_msg();
        } 
        if(result) {
                protector = pros[i];
                protect_message = replace_string(protect_message, "$n", pros[i]->name());
        }
        return result;
} 
// get_action(object me)
// Return an action the object can take.
mapping get_action(object me, int attack_type) {
        mapping action; 
        action = me->query("actions");
        if(!mapp(action)) {
                me->reset_action();
                action = me->query("action");
                if(!mapp(action)) {
                        CHANNEL_D->do_sys_channel( "sys",
                                        sprintf("%s(%s): bad action = %O", me->name(1),
                                        me->query("id"), me->query("actions", 1)));
                        return 0;
                }
        }
        return action;
} 
// do_attack()
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
int do_attack(object attacker, object victim, int attack_type, mixed att_msg) {
        mapping action,w_action;
        string result,w_name,vw_name;
        int ap, ranCor, counterpower, actionResult, damage;
        object attacker_weapon;
        object victim_weapon; 
        // initial global variables.
        attacker_damage = 0;
        victim_damage = 0;

        result_message = "";  
        // (1) First see if we are capable of attack
/*      if(attacker->query_temp("is_unconcious")
                        || (attack_type != TYPE_PERFORM && !attacker->actionOK()))
                return 0;
*/
        if(!objectp(attacker) || !living(attacker) ||attacker->is_busy()
                        || !objectp(victim) ) return 1; 
        victim->delete_temp("damaged_during_attack"); 
        // (2) Find out what action the attacker will take.
        action = get_action(attacker, attack_type);
        if(!mapp(action)) {
                return 1;
        } 
        attacker_weapon = attacker->query_temp("weapon");
        victim_weapon= victim->query_temp("weapon"); 
        // (3) Prepare AP for the attacker.
        ap = skill_power(attacker, SKILL_USAGE_ATTACK);  
        // Debug message
        if(wizardp(attacker) && (string)attacker->query("env/combat1")=="verbose" ) {
                tell_object(attacker, sprintf(HIW "\nAP:%d\t" NOR, ap));
        }
        // Debug message ends  
        result_message = "\n" + action["action"] + "��\n";
        if(stringp(att_msg)) {
                result_message = "\n" + att_msg + "\n";
        }
        // (4) if player is enforced, let him/her relase the
        //     force even without hit others
        if(userp(attacker)) {
                if(attacker->query("force") > attacker->query("force_factor")/2) {
                        attacker->add("force", -attacker->query("force_factor")/2);
                } else {
                        attacker->set("force_factor", 0);
                }
        } 
        // (5) Let's see what/who can protect our victim, $N, $n,...all applies
        protect_message = "";
        result = "";

        actionResult = RESULT_UNKNOWN;
        counterpower = 0;
        if(sizeof(victim->query_temp("protectors"))) {
                counterpower = do_protect(attacker, ap, action, victim);
                result_message += protect_message;
                actionResult = counterpower > 0 ? RESULT_PROTECT : RESULT_UNKNOWN;
        } 
        // (6) Find out what is the reaction from the victim.
        if(actionResult == RESULT_UNKNOWN&&attack_type!=TYPE_QUICK)
        { 
                // (6.1) Find out if victim can react.
/*              if(living(victim))
                {
                        if(attack_type == TYPE_PERFORM)
                        {
                                ranCor = random(25 + attacker->query_cor());
                        }
                        else
                        {
                                ranCor = random(victim->query_cor() + 25 + attacker->query_cor());
                        } 
                        // (6.2) victim counter attack.
                        if(ranCor > (attacker->query_cor() + 25)) {
                                if(userp(victim)) {
                                        if(victim->query("force") > victim->query("force_factor")) {
                                                victim->add("force", -victim->query("force_factor"));
                                        } else {
                                                victim->set("force_factor", 0);
                                        }
                                }
                                counterpower = counter_attack(attacker, ap, action, victim);
                                result = counter_message;
                                actionResult = RESULT_COUNTER; 
                        // (6.3) victim try to dodge attack
                } else
                if(ranCor > attacker->query_cor()) */  
                                counterpower = dodge_attack(attacker, ap, action, victim);
                                result = dodge_message;
                                actionResult = counterpower > 0 ? RESULT_DODGE : RESULT_UNKNOWN;

                        if(!counterpower)
                        {
                        // (6.4) victim try to parry attack
                                counterpower = parry_attack(attacker, ap, action, victim);
                                result = parry_message;
                                actionResult = counterpower > 0 ? RESULT_PARRY : RESULT_UNKNOWN;
                        }
                        // (6.5) victim try to counter attack
                        if(!counterpower&&victim->query_cor() > random(attacker->query_cor() + 100)
                                &&attack_type==TYPE_REGULAR)
                        {
                                if(userp(victim))
                                {
                                        if(victim->query("force") > victim->query("force_factor"))
                                        {
                                                victim->add("force", -victim->query("force_factor"));
                                        }
                                 else   {
                                                victim->set("force_factor", 0);
                                        }
                                }
                                counterpower = counter_attack(attacker, ap, action, victim);
                                actionResult = counterpower > 0 ? RESULT_COUNTER : RESULT_UNKNOWN;
                                result= counter_message;
                        }
                        else if(victim->query_temp("counter_action"))
                        {
                                counterpower = counter_attack(attacker, ap, action, victim,1);
                                result+= counter_message;
                                victim->delete_temp("counter_action");
                        } 
        }
        // (7) Attack not blocked, take damage.
        if((actionResult == RESULT_UNKNOWN) || (actionResult == RESULT_COUNTER)) {
                victim->set_temp("damaged_during_attack",1);
                damage = attack_damage(attacker, action, victim);
                result_message += damage_message; 
                damage = inflict_damage(attacker, victim, damage, action);
                result_message += inflict_message;

                if(damage < 0) {
                        attacker_damage += -damage;
                } else {
                        victim_damage += damage;
                        actionResult = victim_damage;
                }
        } 
        result_message += result;
        if(objectp(victim_weapon))
                vw_name=victim_weapon->name();
        if(objectp(attacker_weapon)) {
                w_name=attacker_weapon->name();
                w_action=attacker_weapon->query_action();  
                if(actionResult == RESULT_PROTECT) {
                        if(action["post_action"]) {
                                result_message += call_other(attacker_weapon, action["post_action"], attacker, victim, actionResult);
                        }
                        else if(w_action["post_action"]&&!random(5))
                                result_message += call_other(attacker_weapon, w_action["post_action"], attacker, victim, actionResult); 
                        if (objectp(attacker_weapon)) result_message += attacker_weapon->wear_off(attacker, victim, actionResult);
                        else {
                                attacker_weapon = 0;
                                attacker->delete_temp("weapon");
                        } 
                } else {
                        if(action["post_action"]) {
                                result_message += call_other(attacker_weapon, action["post_action"], attacker, victim, actionResult);
                        }
                        else if(w_action["post_action"]&&!random(5))
                                result_message += call_other(attacker_weapon, w_action["post_action"], attacker, victim, actionResult); 
                        if (objectp(attacker_weapon)) result_message += attacker_weapon->wear_off(attacker, victim, actionResult);
                        else {
                                attacker_weapon = 0;
                                attacker->delete_temp("weapon");
                        }
                }
        } 
        // (7) Give experience
        if(userp(attacker) && !userp(victim) ) {

                if((ap < counterpower)
                                && (random(attacker->query("sen")*100/attacker->query("max_sen")) > 50)
                                && (((int)attacker->query_encumbrance()*100/(int)attacker->query_max_encumbrance()) < 20)
                                && damage > 0) {
                        if(random(attacker->query("potential")) < 50000) {
                                attacker->add("potential", 1);
                        }
                        if(random(attacker->query("combat_exp") < 100000)) {
                                attacker->add("combat_exp", 1);
                        }
                }
        }
        // NPC have chance to get exp when fail to hit.
        if(!userp(attacker) && random(attacker->query_int()) > 15) {
                attacker->add("combat_exp", 1);
        } 
        // (8) Prepare final result and status message, and show it.
        result_message = prepare_final_message(attacker, victim,w_name,vw_name, action, result_message);
        message_vision(result_message, attacker, victim);
        if(victim_damage) {
                report_status(victim, (attacker->is_killing(victim)) || (attacker->query_temp("weapon") ) ? 1 : 0);
                //�ӵ���������damage���Ż��ж�function busy
                if(victim->is_busy())
                        victim->interrupt_me(attacker,"hit");
        }
        if(attacker_damage) {
                report_status(attacker, 0);
        } 
        // (9) wizard debug information.
        if(wizardp(attacker) && (string)attacker->query("env/combat")=="verbose" ) {
                tell_object(attacker, sprintf(GRN "ATTACK STATUS:\tAP: %d\tCP: %d\tVD:%d\tAD:%d\n" NOR,
                                ap/100, counterpower/100, victim_damage, attacker_damage));
        }
        if(wizardp(victim) && (string)victim->query("env/combat")=="verbose" ) {
                tell_object(victim, sprintf(GRN "DEFENSE STATUS:\tAP: %d\tCP: %d\tVD:%d\tAD:%d\n" NOR,
                                ap/100, counterpower/100, victim_damage, attacker_damage));
        }
        //��Ӧ�������ֻ�б����У��Ż��ж�function busy
/*

        if(victim->is_busy()) {
                victim->interrupt_me(victim,attacker,"hit");
        } */
/*      if((!attacker->is_killing(victim->query("id")))
                        && (!victim->is_killing(attacker->query("id")))
                        && (attacker->query("kee")*2 <= attacker->query("max_kee")
                                || attacker->query("eff_gin")*2 <= attacker->query("max_gin")
                                || attacker->query("eff_sen")*2 <= attacker->query("max_sen")
                                )
                        ){
                attacker->remove_enemy(victim);
                victim->remove_enemy(attacker);
                message_vision(winner_msg[random(sizeof(winner_msg))], victim, attacker);
// check to see if anything special need to be done after fight for both win/lose.
                fight_reward(victim, attacker);
                fight_penalty(victim, attacker);
        } */ 
        if((!attacker->is_killing(victim->query("id")))
                        && (!victim->is_killing(attacker->query("id")))
                        && (victim->query("kee")*2 <= victim->query("max_kee")
                                || victim->query("eff_gin")*2 <= victim->query("max_gin")
                                || victim->query("eff_sen")*2 <= victim->query("max_sen")
                                )
                        && damage > 0 ) {
                attacker->remove_enemy(victim);
                victim->remove_enemy(attacker);
                if(victim->query_temp("is_unconcious")){ 
                } else {
                        message_vision(winner_msg[random(sizeof(winner_msg))], attacker, victim);
                }
// check to see if anything special need to be done after fight for both win/lose.
                fight_reward(attacker, victim);
                fight_penalty(attacker, victim);
        }  
} 
// since most spell/magic perform don't call combatd fight(), this function needs to
//be called in perform to check winner/loser. 
void win_lose_check(object attacker, object victim, int damage) { 
                if((!attacker->is_killing(victim->query("id")))

                        && (!victim->is_killing(attacker->query("id")))
                        && (victim->query("kee")*2 <= victim->query("max_kee")
                                || victim->query("gin")*2 <= victim->query("max_gin")
                                || victim->query("sen")*2 <= victim->query("max_sen")
                                )
                        && damage > 0 ) {
                attacker->remove_enemy(victim);
                victim->remove_enemy(attacker);
                if(victim->query_temp("is_unconcious")){ 
                } else {
                        message_vision(winner_msg[random(sizeof(winner_msg))], attacker, victim);
                }
                fight_reward(attacker, victim);
                fight_penalty(attacker, victim);
        }
}  
// fight()
// This is called in the attack() defined in F_ATTACK, which handles fighting
// in the heart_beat() of all livings. Be sure to optimize it carefully.
void fight(object me, object victim) {
        object ob; 
        // Check to see if fight can start.
        if(!living(me)
                        || (environment(me) != environment(victim))
                        || (!me->visible(victim) && userp(me) && (random(150 + (int)me->query_skill("perception")) < 100))) {
                return;
        } 
        // victim fight back.
        victim->fight_ob(me); 
        //  If I am too clumsy to attack.
        if (random(me->query_temp("buff/slow"))>=100) {
                message_vision(YEL"\n$N����һ������һ���ɣ�������˴�õĹ���ʱ����\n"NOR,this_object());
                return;
        } 
        // If victim is unconcious, always take the chance to makeanattack.
        if( victim->query_temp("is_unconcious")) {
                do_attack(me, victim, TYPE_QUICK, 0); 
        // Else, see if we are brave enough to make an aggressive action.
        } else if((int) me->query_cor()*3/2 > random((int) victim->query_cor())||victim->is_busy()) {

                // do normal attack,
                do_attack(me, victim, TYPE_REGULAR, 0);
                // If I have dual-attack skill.
                if (random(me->query_skill("dual-attack",1))>= 100) {
                        message_vision(CYN"\n$N�������಻�ϣ�ǰ��δ�ϣ��������ѻ�����\n"NOR,me);
                        do_attack(me, victim, TYPE_REGULAR, 0);
                }
                // If I am really fast so i can attack again.
                if (random(me->query_temp("buff/haste"))>=100) {
                        message_vision(WHT"\n$N����������ƥ��˲�����ѹ���һ�С�\n"NOR,me);
                        do_attack(me, victim, TYPE_REGULAR, 0);
                }
        // Else, we just start guarding.
        } else {
                message_vision(guard_msg[random(sizeof(guard_msg))], me, victim);
        }
        return;
}  
// auto_fight()
// This function is to start an automatically fight. Currently this is
// used in "aggressive", "vendetta", "hatred", "berserk" fight.
void auto_fight(object me, object obj, string type) {
        int bellicosity, fined;
        object silver, gold, cloth, room,basket,skin,pumpkin;
        int silver1;
        if(!me || !obj || (!userp(me) && !userp(obj)) || me->is_fighting(obj) || me->query_temp("is_unconcious")
                        ||!living(me) || environment(me)!=environment(obj)
                        || environment(me)->query("no_fight")) {
                return;
        } 
        if(type == "berserk") {
                bellicosity = (int)me->query("bellicosity");
                message_vision("$N��һ������������ɨ����$n��\n", me,obj);
                if(((int)me->query("force") + (int)me->query_tol() * 10) >
                                (random(bellicosity) + bellicosity)/2 ) {
                        return;
                }
                if(userp(obj) && (int) obj->query("combat_exp") < LOWER_LIMIT) {
                        return;
                }

                if( bellicosity > (int)me->query("score") && !wizardp(obj) ) {
                        message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
                                        + "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
                        me->kill_ob(obj);
                        obj->kill_ob(me);
                } else {
                        message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
                                        + "��" + RANK_D->query_self_rude(me) +
                                        "�������˴�ܣ����������ְɣ�\n", me, obj);
                        me->fight_ob(obj);
                        obj->fight_ob(me);
                }
        } else if(type == "naked") {
                if(!obj->is_naked()) {
                        return;
                }
               /* if (userp(me) && !obj->is_ghost() && me->query("cps") <= obj->query("per"))
                {
                        message_vision("$N�����۾����ճյ�����$n��\n", me, obj);
                } */
                
//                 old naked code, will fine player 10 silver send player to prison
	if( me->query("id")=="police" || me->query("id")=="fengyun garrison" ){   //add by xiaolang
                message_vision("$N����$n�ȵ���ι��������������˷绯������ʮ����\n", me, obj);
                fined = 0;
                if(silver = present("silver_money",obj)) {
                        if(silver->query_amount() >= 10) {
                                silver->add_amount(-10);
                                fined = 1;
                        }
                }
                if(!fined && gold = present("gold_money",obj)) {
                        gold->add_amount(-1);
                        silver = new("/obj/money/silver");
                        if(silver) {
                                silver->set_amount(90);
                                silver->move(obj);
                        }
                        fined = 1;

        	}
        	silver1 = obj->query("deposit")/100;
        	if(!fined && silver1>=10){
        		obj->add("deposit", -1000);
        		obj->save();
        		fined =1;
        	}
        	
                if(fined) {
                        message_vision(RED"$n��$N����ʮ�����ӣ�\n"NOR, me, obj);
                        cloth = new("/obj/armor/cloth");
                        if(cloth) {
                                cloth->move(obj);
                                cloth->wear();
                                message_vision("$N����$n˵����������·����ϰɡ�\n", me, obj);
                        }
                } else {
                        obj->set("marks/���˷绯", 1);
                        if(objectp(room = find_object("/d/jinan/pyard"))
                                        || objectp(room = load_object("/d/jinan/pyard"))) {
                                cloth = new("/obj/armor/cloth");
                                if(cloth) {
                                        cloth->set("name", "����");
                                        cloth->move(obj);
                                        cloth->wear();
                                        message_vision("$N����$n˵����ûǮ���������������ȥ�����ɡ�\n", me, obj);
                                        message_vision("$N˳�ֵݸ�$nһ��װ���Ժȵ����ӣ��Ͱ�$nѺ���˼�����\n",me,obj);
                                }
                                basket = new("/d/cave/obj/bigbasket");
                                skin = new("/d/guanwai/npc/obj/wineskin");
                                pumpkin = new("/d/death/npc/obj/pumpkin");
                                skin->move(basket);
                                pumpkin->move(basket);
                                basket->move(obj);
                                obj->move(room);
                        }
                }
        }    // add by xiaolang       
        } else {
                if(type=="hatred")
                {
                        message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))],me,obj);
                        me->kill_ob(obj);
                }
                else
                if(type=="vendetta")
                {
                        if(userp(me)&&me->query("combat_exp")<obj->query("combat_exp"))
                                return;
                        message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))],me,obj);
                        me->kill_ob(obj);
                        obj->kill_ob(me);       // since "me" is NPC, it doesn't matter add_killer or just kill_ob;
                }

                else
                {
                        message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))],me,obj);
                        me->kill_ob(obj);
                }
        }
} 
void auto_follow(object follower, object leader) {
        int fexp, lexp;
        fexp = (follower->query("combat_exp") > 0? follower->query("combat_exp") : 0);
        lexp = (leader->query("combat_exp") > 0 ? leader->query("combat_exp") : 0);
        if( random(lexp) > fexp/10 ) {
                follower->set_leader(leader);
        } else {
                follower->set_leader(0);
        }
} 
// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event) {
        switch(event) {
                case "dead":
                        if (ob->query("death_msg")) message_vision(ob->query("death_msg"),ob); //���Լ�һ������ǰ�Ļ���
                        message_vision("\n$N���ˡ�\n\n", ob);
                        break;
                case "unconcious":
                        message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
                        break;
                case "revive":
                        message_vision("\n$N���������۾��������˹�����\n\n", ob);
                        break;
        }
} 
void winner_reward(object killer, object victim) {
        object owner; 
        if(owner=killer->query("possessed")) {
                killer = owner;
        }
        killer->defeated_enemy(victim);

} 
void loser_penalty(object killer, object victim) {
        object owner; 
        if(owner=victim->query("possessed")) {
                victim = owner;
        }
        victim->defeated_by_enemy(killer);
} 
void killer_reward(object killer, object victim) {
        int bls, i;
        string vmark;
        object owner;
        object env;
        object *mem;
        object realkiller;
        mapping quest; 
        // Call the mudlib killer apply.
        realkiller = killer;
        if(owner=killer->query("possessed")) {
                killer = owner;
        }
        killer->killed_enemy(victim);
        if(userp(victim) ) {
                if((int) killer->query("combat_exp") < (int)victim->query("combat_exp")/10 * 9) {
                        killer->set("last_good_kill",(int)killer->query("mud_age"));
                }
                env = environment(victim);
                if((objectp(env)) && !(env->query("no_death_penalty")))
                        killer->add("PKS", 1);
                bls = 10;
        } else {
                killer->add("MKS", 1);
                bls = 1;
        } 
        // NPC got 10 times of bellicosity than user.
        //      killer->add("bellicosity", bls * (userp(killer)? 1: 2));
        // --- to stop exploit, NPC will not gain bellicosity anymore, silencer, 12/23/2001 
        if (userp(killer))
                killer->add("bellicosity",bls); 

        // Now official killing official will also become fei.
        if((!userp(victim)) && stringp(vmark = victim->query("vendetta_mark"))
                        /*&& vmark != killer->query("vendetta_mark")*/) {
                killer->add("vendetta/" + vmark, 1);
        } 
        // Now let's add the quest reward here 
        mem = pointerp(killer->query_team()) ? killer->query_team() : ({ killer });
        if (!userp(victim))
        for(i=0; i<sizeof(mem); i++) {
                if ((mem[i])) {
                        if(mapp(quest = mem[i]->query("quest"))
                                && (string)victim->name() == quest["quest"]
                                && (time() - mem[i]->query("task_time") <= 900)) {
                                QUESTS_D->give_reward(mem[i],killer, quest);
                        }
                }
        } 
        // let's add the hired killer things here
        if(!userp(realkiller) && realkiller->query("hired_killer")
                        && (string)victim->query("id") == (string)realkiller->query("haunttar")) {
                message_vision("$Nһ���֣��Ҳ���ʹ����������ڣ�\n",realkiller);
                destruct(realkiller);
        }
} 
varargs void victim_penalty(object victim, mixed killer,int flag) {
        string msg="Ī����������ˡ�";
        mapping actions;
        object env;
        int combat_exp, combat_pot,combat_exp_old,combat_pot_old;
        int combat_exp_lost,combat_pot_lost;
        string special_death_place,death_msg; 
        if( userp(victim)) {
                env = environment(victim);
                if((objectp(env)) && (env->query("no_death_penalty"))) {
                        victim->set_temp("no_death_penalty",1);
                        victim->clear_all_condition();  //In yaren fight, easilly get posioned.
                        return;
                }
                if(objectp(killer))

                {
                        msg="��"+killer->query("name");
                        actions = killer->query("actions");
                        switch(actions["damage_type"])
                        {
                                case "����":
                                case "����":
                                        msg+="�����ˡ�";
                                        break;
                                case "����":
                                        msg+="�����ˡ�";
                                        break;
                                case "����":
                                        msg+="�����ˡ�";
                                        break;
                                case "ץ��":
                                        msg+="ץ���ˡ�";
                                        break;
                                case "������":
                                        msg+="�����ˡ�";
                                        break;
                                default:                                         msg+="ɱ���ˡ�";
                        }
                }
                else if(stringp(killer))
                        msg = killer;//������Ǹ���һ�����Ա仯��������info�Ļ���
                if(!flag)
                CHANNEL_D->do_sys_channel(
                                "info",sprintf("%s(%s)"+msg, victim->name(1),victim->query("id")));
                // Add/Set/Reduce flags.
                victim->add("KILLED",1);
                victim->clear_all_condition();
                victim->set("bellicosity", 0); 
                // Setup for some dungeons with low death penalty.
                if (objectp(killer))
                if (special_death_place=killer->query("dungeon_npc")) {
                        if (special_death_place=="eren2"
                                && domain_file(file_name(environment(victim)))=="eren2"){

                                if (victim->query("marks/����")) victim->add("combat_exp",-2000);
                                        else victim->add("combat_exp",-4000);
//                              if (victim->query("potential") - victim->query("learned_points")>100)
                                victim->add("potential",-40);
                                return;
                                }
                }  
                // Add/Set/Reduce flags.
                victim->delete("vendetta");
                if( victim->query("thief") )
                        victim->set("thief", (int)victim->query("thief") / 2); 
                // Give the death penalty based on combat experince.
                combat_exp = victim->query("combat_exp");
                combat_exp_old=combat_exp;
                combat_pot = victim->query("potential") - victim->query("learned_points");
                combat_pot_old=victim->query("potential");
                if(combat_pot < 0) {
                        combat_pot = 0;
                } 
                if(combat_exp < 20000) {
                        victim->add("combat_exp", -(int)(combat_exp * 2 / 100)); 
                //} else if(combat_exp < 100000) {
                //      victim->add("combat_exp", -(int)(combat_exp * 2 / 100));
                //      victim->add("potential", -(int)(combat_pot * 25 / 100)); 
                } else if(combat_exp < 200000) {
                        victim->add("combat_exp", -(int)(combat_exp * 2 / 100));
                        victim->add("potential", -(int)(combat_pot * 25 / 100)); 
                } else if(combat_exp < 1000000) {
                        victim->add("combat_exp", -(int)(combat_exp * 2 / 100));
                        victim->add("potential", -(int)(combat_pot * 25 / 100)); 
                } else {
                        victim->add("combat_exp", -(int)(combat_exp * 2 / 100));
                        victim->add("potential", -(int)(combat_pot * 50 / 100)); 
                }
                victim->skill_death_penalty(combat_exp); 
//      Codes below are set for possible revive skills;
                if (combat_exp>1000000) combat_pot_lost = combat_pot*50/100;
                        else if (combat_exp>20000)      combat_pot_lost=combat_pot*25/100;
                        else combat_pot_lost=0;

                combat_exp_lost=combat_exp_old-victim->query("combat_exp");
                if (combat_exp_lost<0) combat_exp_lost=0;
                if (combat_pot_lost<0) combat_pot_lost=0;
                victim->set("death/time",time());
                victim->set("death/exp_lost",combat_exp_lost);
                victim->set("death/pot_lost",combat_pot_lost);
        }
} 
