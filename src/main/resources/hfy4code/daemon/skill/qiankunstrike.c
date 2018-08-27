 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "Ǭ����Ų����");
        set("usage/unarmed", 1);
        set("skill_class", "taoist");
        set("parry_msg", ({
        "$n�����飬ʹ��һ�С�����ӳб��������������һ����$N��$w������\n",
        "$n��һת����ʽƮ��������һ�С����¼�ʱ�С�����$N����$w���֡�\n",
        "$n����������ʽ�����������־����������ӳ��һ�С�������ͬ�ԡ�����ƫ��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n���β������������ڵ��⣬���ȶ�����һ�С����������¡����Ƶ�$N�����Ա���\n",
        "$n����Բת���������Ķ����䣬һ�С�������Ǭ���������赭д�Ļ�����$N�Ĺ��ơ�\n",
        }) );
        
        action = ({
        ([      "action":               
"$Nƽƽ������ʹ��һ�С���ɳ·�����������ư������仯�����ƴ�������$n��$l",
                "dodge":                -100,
                "parry":                100,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�С�ƽ������ơ������ƻ���Ϊʵ����$n��$l",
                "dodge":                -100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������������Х���������죬һ�С�����Х���졹��һ������$n��$l",
                "dodge":                -100,
                "parry":                100,
                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ϣ����ƻ��һ�С��󽭶���ȥ���ƺƵ�������׼$n��$l�����ĳ�",
                "dodge":                -100,
                "parry":                100,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�Ʒ��������������������Ƴ���һ�С����׳��������޼᲻�ߵػ���$n$l",
                "dodge":                -100,
                "parry":                100,
                "force":                240,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ܣ��Ʒ����ᣬһ�С�ϸ��鴺�硹���ӿ��е�ͷ��$n��$l���ƹ���",
                "dodge":                -200,
                "parry":                200,
                "force":                150,
                "damage_type":  "����"
        ]),
        });
}
int practice_skill(object me)
{
    if( (int)me->query("force") < 5 ){
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -5);
    return 1;
}    
