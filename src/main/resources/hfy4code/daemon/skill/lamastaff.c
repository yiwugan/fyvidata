 // lamastaff.c
inherit SKILL; 
void setup() {
        set("name",                     "�����ȷ�");
        set("learn_bonus",              -100);
        set("practice_bonus",           -5);
        set("black_white_ness",         -10);
        set("effective_level",          190);
        set("usage/staff",                      1);
        set("usage/parry",                      1);
        set("practice_damage",          30);
        set("skill_class",                      "lama");       
        set("parry_msg",                        ({
                        "$n������ţ����е�$v�����������������������ס��$N�Ĺ��ơ�\n",
                        })
        ); 
        set("unarmed_parry_msg",        ({
                        "$n������ţ����е�$v�����������������������ס��$N�Ĺ��ơ�\n",
                        })
        );
        action = ({
                        ([      "action":               
                                        "$N������ţ�����$w���������������������ɨ��$n���̣�",
                                "damage":               30,
                                "dodge":                40,
                                "parry":                40,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N������ţ�����$w�����������������������ֱ����$n$l��",
                                "damage":               60,
                                "dodge":                30,
                                "parry":                60,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":           
										"$N������ţ�����$w�����������������������������$n$l��",
                                "damage":               50,
                                "dodge":                50,
                                "parry":                70,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N������ţ�����$w�������������������������ײ��$n$l��",
                                "damage":               30,
                                "dodge":                30,
                                "parry":                50,
                                "post_action":  "bash_weapon",
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
		if( (int)me->query_skill("lamaism",1) <= (int)me->query_skill("lamastaff",1)/2) {
                return notify_fail("������ڷ���Ϊ�������޷����������������ȷ���\n");
        }
        return 1;
        
        if((int)me->query("str") + (int)me->query("max_force") / 10 < 35) {
                return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
}  
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 20) {
                return notify_fail("������������������ȷ���\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}
