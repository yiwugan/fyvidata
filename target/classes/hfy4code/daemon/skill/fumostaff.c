 // fumostaff.c
inherit SKILL;
void setup() {
        set("name", "Τ�ӷ�ħ�ȷ�");
        set("usage/staff", 1);
        set("usage/parry", 1);
        set("learn_bonus", 10);
        set("practice_bonus", -5);
        set("black_white_ness", 0);
        set("skill_class", "shaolin");
        set("parry_msg", ({
        "���$n�����е�$v����$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        }) );
        action = ({
        ([      "action":               
"$Nʹһ�С��������������$w�趯��ɣ�ɨ��$n���̣�",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w��һ�С���Ŀ������������$wֻ�����أ�����$n$l��",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������$w��ʹ�������Ӻ�ա�������$w���ն��£�����$n$l��",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��ຣ�Ⱥ�����$w�󿪴�ϣ�ײ��$n$l��",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        });
} 
int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 35 ) {
                return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 10) {
                return notify_fail("�������������ϰ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
}   
