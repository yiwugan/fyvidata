 //feidao.c
inherit SKILL; 
void setup() {
        set("name", "�ɵ�����");
        set("usage/throwing", 1);
        set("skill_class", "traveller");
        set("effective_level", 150);
        set("learn_bonus", -1000);
        set("practice_bonus", -500);
        set("black_white_ness", 15);
        action = ({
        ([      "action":               
"$N˫��һ�Σ����е�$w��һ�����߰����$n��$l",
                "dodge":                -20,
                "damage":               30,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ����$w�����̶����ƿ���ֱ��$n��$l",
                "dodge":                -40,
                "damage":               30,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ָ΢����$wбб�ķ���$n��$l",
                "dodge":                -40,
                "post_action":  "throw_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������⣬����һ˦�����е�$w����һ����������$n��$l",
                "dodge":                20,
                "post_action":  "throw_weapon",
                "damage":               40,
                "damage_type":  "����"
        ]),
        });
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 500 ) {
                return notify_fail("�������������û�а취���ɵ�������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 500 ) {
        return notify_fail("�������������û�а취��ϰ�ɵ�������\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -30);
    write("�㰴����ѧ����һ��ɵ�������\n");
    return 1;
}    
