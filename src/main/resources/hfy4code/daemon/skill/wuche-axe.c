 // TIE@FY3
inherit SKILL;
void setup(){
        set("name", "�򳹲��縫��");
        set("usage/axe", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 250);
        set("practice_limit",150);
        set("learn_bonus", -1000);
        set("practice_bonus", -5);
        set("skill_class", "shaolin");
        
        set("parry_msg", ({
        "���$nһ�С�������į�����Ӷ�����$v����$N��$w��\n",
        "���$n����$vһ�֣�һ�С���ħ��𡹣�б��$N��$w��\n",
        "���$n����$v�ն���ɣ�һ�С��鲨���������$N��$w��\n",
        "���$n����$v������ת��һ�С�������ۡ�����ɨ$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n���е�$v�趯��ɣ�һ�С�������ҡ������ס��$N�Ĺ��ơ�\n",
        "$n��Ӱ�ζ���һ�С�ǧ̶���ʡ�������$N�����̡�\n",
        "$n����һ����һ�С�������������$N�Ĺ��ơ�\n",
        "$n���е�$v���϶��£�һ�С�ʼ�����ء�������$N��Ҫ����\n",
        }) );   
        action = ({
        ([      "action":               
"$N����$w�տ���Ю�ź���������һ�С�����ÿÿ����ֱȡ$n�ĸ���Ҫ����",
                "dodge":                -150,
                "parry":                -200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$w�����Х��һ�С����ֳ��ա��������$n$l��ȥ��",
                "dodge":                -160,
                "parry":                -210,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������������һ�С�ԨԴ������������㿳��$n$l��",
                "dodge":                -150,
                "parry":                -150,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С����ɳ��ڡ�������$w�趯�����渫�ƣ�����һ���̳�����������$n��$l��",
                "dodge":                -140,
                "parry":                -240,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 ){
            return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("wuche-axe",1)>161)
                return notify_fail("�߼����򳹲��縫��ֻ��ѧ�ġ�\n");
        
        if( (int)me->query("force") < 10 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        return 1;
}      
