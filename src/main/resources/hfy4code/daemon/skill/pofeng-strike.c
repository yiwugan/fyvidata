 // pofeng-strike.c
inherit SKILL;
void setup() {
        set("name", "�÷���");
        set("usage/unarmed", 1);
        set("learn_bonus", 10);
        set("practice_bonus", -10);
        set("black_white_ness", -20);
        set("effective_level", 170);
        set("skill_class", "yinshi");
        set("parry_msg", ({
        "$n����Ϊ����һ�С�������¡�����$N����$w���֡�\n",
        "$n��һת��һ�С��綯���ҡ�����$N����$w���֡�\n",
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n����Ϊָ��һ�С����ŭХ������$N������ҪѨ��\n",
        "$nʩչ�������ŭ�𡹣����赭д�Ļ�����$N�Ĺ��ơ�\n",
        }) );
        
        action = ({
        ([      "action":               
"$Nʹ��һ�С����ÿ�硹�����ƴ����´�������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С����ͻϮ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                170,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ���÷��Ʒ����綯��ͥ�����εض���$n��ǰ��һ������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ�������꽻�ӡ�����׼$n��$l�ĳ�һ����Ӱ",
                "dodge":                10,
                "parry":                30,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����ɨҶ������$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "����"
        ]),
        });
} 
int practice_skill(object me)
{
    if( (int)me->query("force") < 5 ){
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
    me->add("force", -5);
    return 1;
}      
