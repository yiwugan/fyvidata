 // TIE@FY3
inherit SKILL;
void setup(){
        set("name", "�������");
        set("usage/fork", 1);
        set("usage/axe", 1);
        set("usage/staff", 1);
        set("usage/spear", 1);
        set("usage/hammer", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 150);
        set("practice_limit",150);
        set("learn_bonus", -1000);
        set("practice_bonus", -5);
        set("skill_class", "new");
        
        set("parry_msg", ({
        "���$nһ�С�һ���ǳɡ����Ӷ�����$v����$N��$w��\n",
        "���$n����$vһ�֣�һ�С�����ɽ�ӡ���б��$N��$w��\n",
        "���$n����$v�ն���ɣ�һ�С�ǧ��׷�硹������$N��$w��\n",
        "���$n����$v������ת��һ�С����񳯷����ɨ$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n���е�$v�趯��ɣ�һ�С�ͭǽ���ڡ�����ס��$N�Ĺ��ơ�\n",
        "$n��Ӱ�ζ���һ�С������Ҷ��������$N�����̡�\n",
        "$n����һ����һ�С������ٶ��������$N�Ĺ��ơ�\n",
        "$n���е�$v���϶��£�һ�С���ͷ�ǰ���������$N��Ҫ����\n",
        }) );   
        action = ({
        ([      "action":               
"$N����$w�տ���Ю�ź���������һ�С���̻Ի͡���ֱȡ$n�ĸ���Ҫ����",
                "dodge":                -550,
                "parry":                -1500,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$w������Х��һ�С�����������������$n$lɨȥ��",
                "dodge":                -360,
                "parry":                -1010,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������������һ�С�������Ŀ�������������$n$l��",
                "dodge":                -350,
                "parry":                -550,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С�����ѿǡ�������$w�趯���������ƣ�����һ���̳�����������$n��$l��",
                "dodge":                -1040,
                "parry":                -540,
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
        if( me->query_skill("sword")>1 || me->query_skill("blade") >1|| me->query_skill("dagger") > 1 ){
            return notify_fail("��������ƺ��봫ͳ�������еȱ����÷���ͬ����һʱ֮�䲻֪�Ӻ�ѧ��\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("jingang-tieguai",1)>100)
                return notify_fail("�߼��Ľ������ֻ��ѧ�ġ�\n");
        
        if( (int)me->query("force") < 10 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        return 1;
}      
int effective_level()
{
        object me=this_player();
        int skill,n;
         skill=me->query_skill("jingang-tieguai",1);
        if (skill > 199) return 300;
        if (skill < 200) return 150;
        
                
}  
