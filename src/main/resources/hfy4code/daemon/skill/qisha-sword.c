 // tangsi.c
#include <ansi.h> 
inherit SKILL;
void setup() {
        set("name", "��ɱ����");
        set("usage/sword", 1);
        set("usage/whip", 1);
        set("usage/parry", 1);
        set("skill_class", "tang");
        set("effective_level", 150);
        set("learn_bonus", -50);
        set("practice_bonus", 10);
        set("black_white_ness", 15);
        set("parry_msg", ({
        "$nʹ��һ�С�������᡹�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ�����ϸ�ͬ��������$N��$w�������⡣\n",
        "$nʹ��һ�С���ɱ�����������е�$v�������콣ѩӰ��������$N��$w��\n",
        "$n���е�$vһ����һ�С�ʯ�����񡹣���$N��$w��������ȥ��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬һʽ�����²�������ס��$N�Ĺ��ơ�\n",
        "$n����һ�С����·���������������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С��������š���$vֱ��$N��˫�֡�\n",
        "$n�����е�$v��������������һʽ������������ȵ�$N�������ˡ�\n",
        }) );   
        action = ({
        ([      "action":               
"$Nʹһ�С��������š�������$w��һ�����߰����$n��$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����ɷ�����еġ�ľ��ͨ�������������ն��$n��$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С����������������ζ�Ȼ�������ߣ�����$wն��$n��$l",
                "dodge":                30,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ��Ӣ��������׼$n��$l�̳�һ��",
                "dodge":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С��ϸ���ԫ����׼$n��$lбб�̳�һ��",
                "dodge":                40,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С�����ͬ��������$n��$l",
                "dodge":                20,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С������׺������ֶ�׼$n$lһ����ȥ",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С���ͷ����������һ���⻡����$n��$l",
                "dodge":                30,
                "damage":               50,
                "force":                100,
                "damage_type":  "����"
        ]),
        });
}
