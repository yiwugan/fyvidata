 // bai-quan.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "�׼�ȭ��");
        set("learn_bonus",              50);
        set("practice_bonus",   10);
        set("effective_level",  70);
        set("usage/unarmed",    1);
        set("skill_class",              "shenshui");
        
        set("parry_msg",                ({
                                                "$nһ�С�������������ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
                                                "$n��ȭ��ϣ���ȭһ�С����ɳ²֡����Ƶ�$N����������\n",
                                                "$n����Ϊ����һ�С�����Ϊ�������ͻ�$N��$w������\n",
                                                "$nһ�С�����ѿǡ�������һ��$N��$w���֣���ƫ��$N��$w��\n",
                                                        })
        );
        set("unarmed_parry_msg",({
                                                "$nһ�С�������������Ƶ�$N��;���С�\n",
                                                "$n����������һ�С����׳�н������$N֮�ؾȡ�\n",
                                                "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
                                                "$n˫ȭ�����ʹ��һ�С�һ��˫�񡹣�$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
                                                        })
        );
                                           
        action = ({
                        ([      "action":               "$Nʹһ�С����ɹ��¡�����׼$n��$l��������һȭ",
                                "dodge":                -40,
                                "parry":                40,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����ȭͷ��һ�С���ѩ��÷������$n��$l�к���ȥ",
                                "dodge":                -30,
                                "parry":                30,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N������Σ���ȭ���������Ρ���$n��$l����",
                                "dodge":                -30,
                                "parry":                30,
                           "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����һ������ȭ��������ȭʹ������ɽ����������$n$l",
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
                        && victim->query_skill_mapped("unarmed") == "ill-quan"
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
