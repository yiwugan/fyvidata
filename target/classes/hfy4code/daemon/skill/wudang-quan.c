 // bai-quan.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "����ȭ");
        set("learn_bonus",              50);
        set("practice_bonus",   10);
        set("effective_level",  150);
        set("usage/unarmed",    1);
        set("skill_class",              "ghost");
        
        set("parry_msg",                ({
                                                "$nһ�С�������������ƽ���ɸ��𴦾����������ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
                                                "$n��ȭ��ϣ���ȭһ�С���������ڷ��̣�����ػ�����Ǭ�����Ƶ�$N����������\n",
                                                "$n����Ϊ����һ�С������Ƴ��գ��嵨��ѩ�������ͻ�$N��$w������\n",
                                                "$nһ�С��޻���ͷ����������������������һ��$N��$w���֣���ƫ��$N��$w��\n",
                                                        })
        );
        set("unarmed_parry_msg",({
                                                "$nһ�С������ѹ��򺮸���������ָ�����ǡ����Ƶ�$N��;���С�\n",
                                                "$n����������һ�С������춨����·����������һ��䡹����$N֮�ؾȡ�\n",
                                                "$n��ȭ���£���ȭ�Ա���һ�С�̾��ʱ������ޱ�Ѫ���ġ�����$N���ڳ��⡣\n",
                                                "$n˫ȭ�����ʹ��һ�С�־���ƽ��ģ����ѩ������$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
                                                        })
        );
                                           
        action = ({
                        ([      "action":               "$Nʹһ�С�������������ƽ���ɸ��𴦾�����������׼$n��$l��������һȭ",
                                "dodge":                -40,
                                "parry":                40,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����ȭͷ��һ�С���������ڷ��̣�����ػ�����Ǭ������$n��$l�к���ȥ",
                                "dodge":                -30,
                                "parry":                30,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N������Σ���ȭ�������ѹ��򺮸���������ָ�����ǡ���$n��$l����",
                                "dodge":                -30,
                                "parry":                30,
                           "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����һ������ȭ��������ȭʹ���������춨����·����������һ��䡹����$n$l",
                                "dodge":                -30,
                                "parry":                30,
                                "damage_type":  "����"
                        ]),
        });
} 
mixed hit_ob(object me, object victim, int damage_bonus) {
        if(random(damage_bonus) < 350) {
                return 0;
        }
        if(!victim->query_temp("weapon") 
                        && victim->query_skill_mapped("unarmed") == "taiji"
                        && me->query_skill("unarmed") > victim->query_skill("unarmed")) {
                switch(random(3)) {
                        case 0:
                                message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                                break;
                        case 1:
                                message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                                break;
                        case 2:
                                message_vision(HIR "\n��ȭ����ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                                break;
                }
                return random(me->query_skill("unarmed")) * 10;
        }
        return 0;
}       
