 // tigerstrike.c
inherit SKILL;
void setup(){
        set("name", "����");
        set("usage/unarmed", 1);
        set("effective_level", 100);
        set("learn_bonus", 100);
        set("practice_bonus", 30);
        set("skill_class", "new"); 
        set("black_white_ness", 0);
        set("parry_msg", ({
        "$n����Ϊ����һ�С����ݡ�����$N����$w���֡�\n",
        "$n˫�ƽ���ʹ��һ�С��ͻ���ɽ������ž����һ����$N��$w����˫��֮�䡣\n",
        "$n��һת��һ�С��ͻ���β������$N����$w���֡�\n",
        "$nʹ����Х���־���˫��һ������ƫ��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�������ǣ�һ�С��ͻ���ɽ������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
        "$n����Ϊָ��һ�С��ͻ���β������$N������ҪѨ��\n",
        "$nʩչ���������������赭д�Ļ�����$N�Ĺ��ơ�\n",
        }) );   
        action = ({
        ([      "action":               
"$Nʹ��һ�С��컢��ʽ�������ƴ�������$n��$l",
                "dodge":                70,
                "parry":                110,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��컢��ʽ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                100,
                "parry":                300,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������С��컢ɨʽ�������ͻ�������$n��ǰ��һ������$n��$l",
                "dodge":                130,
                "parry":                90,
                "force":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ�����컢��ʽ������׼$n��$l�����ĳ�����",
                "dodge":                110,
                "parry":                130,
                "force":                130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��컢�ʽ������$n$l",
                "dodge":                120,
                "parry":                130,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����컢��ʽ��������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                "dodge":                170,
                "parry":                110,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����������һ�С������컢��˫�Ʋ����Ƴ�",
                "dodge":                170,
                "parry":                240,
                "force":                150,
                "damage_type":  "����"
        ]),
        });
} 
int practice_skill(object me)
{
        
    if((int)me->query("force") < 5 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -5);
    return 1;
}   
