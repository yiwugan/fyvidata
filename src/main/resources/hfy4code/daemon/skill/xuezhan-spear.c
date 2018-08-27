 // xuezhan-spear.c
inherit SKILL;
void setup(){
        set("name", "Ѫսǹ��");
        set("usage/spear", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 280);
        set("learn_bonus", -600);
        set("practice_bonus", -30);
        set("practice_limit",140);
        set("black_white_ness", 0);
        set("skill_class", "fugui");
        
        set("parry_msg", ({
                "$nǹ��һ�䣬ʹ�������Ƿ�ʻ��$vֱ��$N,�Ƶ�$N����������\n",
                "$nǹ��ƽƽ������һ�С���ܽ�����������$N�޷����֣����ƶ�ʱ����������\n",
                "$n���е�$v����һƬǹ����һʽ��ŭ�����Ρ��ִ�$N�����е�����������\n",
                "$nһ����Х�����λ��������������������е�$v����$N��ǰ�ء�\n",
        "$n����ǹ�ߣ�$v������������,����$N��$w��\n",
        "$n˫�����ߣ�ǹʽ�ɡ�ӭ�����������е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",        
        }) ); 
        set("unarmed_parry_msg", ({
                "$nǹ��һ�䣬ʹ�������Ƿ�ʻ��$vֱ��$N,�Ƶ�$N����������\n",
                "$nǹ��ƽƽ������һ�С���ܽ�����������$N�޷����֣����ƶ�ʱ����������\n",
                "$n���е�$v����һƬǹ����һʽ��ŭ�����Ρ��ִ�$N�����е�����������\n",
                "$nһ����Х�����λ��������������������е�$v����$N��ǰ�ء�\n",
        "$n����ǹ�ߣ�$v������������,����$N��\n",
        "$n˫�����ߣ�ǹʽ�ɡ�ӭ�����������е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",       
        }) );   
        action = ({
        ([      "action":               
"$N����$w������������Ϻ��£�����һ�С�Ѫ����ã����ǹ�淺��һƬ���⣬����$n��$l!",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "force":                100,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ������������ʹ��һ�С����Ѫϴ�������ν����繭����$wΪ������$nһ���������������$n��",
                "damage":               60,
                "dodge":                70,
                "parry":                30,
                "force":                50,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����������ȴ��$n���֮�ʣ�ʹ��һ�С�Ѫ�����������ǹ����������������$n$l��",
                "damage":               60,
                "dodge":                30,
                "parry":                60,
                "force":                75,                
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ע$w����򵥵��ĺỮ��ȥ��һ��ƽ���ġ��������ڡ�����$N���о�����˹������",
                "damage":               40,
                "dodge":                60,
                "parry":                40,
                "force":                75,           
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ�Σ�ת����ߣ�ͻȻһ�ǡ���ٲ�������Ҹ�´̳���$n����ʱ��ǹ�������߰�̵�$n��ǰ��",
                "damage":               60,
                "dodge":                30,
                "parry":                60,
                "force":                50,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�߾٣���������һʽ�������ֻء�����ֱ�����£�$n������������¯����֪���롣",
                "damage":               60,
                "dodge":                30,
                "parry":                60,
                "force":                150,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 40 ){
            return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if( (int)me->query("force") < 20 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -20);
        return 1;
}   
