 // flying-dragon.c
inherit SKILL;
void setup() {
        set("name", "����̽����");
        set("usage/unarmed", 1);
        set("effective_level", 140);
        set("skill_class", "yinshi");
        set("parry_msg", ({
        "$n˫�ּ�ץ$N������$N���е�$w�������ֶ�����\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�����ָ�������㣬ָ��ֱ��$N�������Ѩ��\n",
        }) );
        
        action = ({
        ([      "action":               
"$N˫��һ�ӣ�һ�С��������졹���ֻ���$n$l",
                "dodge":                30,
                "parry":                30,
                "force":                80,
                "damage_type":  "����",
        ]),
        ([      "action":               
"$N��Ӱ���죬ʹһ�С�����ͻ�֡���ת��������$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
        ]),
        ([      "action":               
"$N���κ�Ȼƽ�ذ���˫��ɢ��������Ӱ��һ�С�������β����$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "force":                140,
                "damage_type":  "����",
        ]),
        ([      "action":               
"ֻ��$N˫��һ�ڣ�˳������һ�С������㾦����$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        });
}
int practice_skill(object me)
{
    if( (int)me->query("force") < 10 ) {
        return notify_fail("������������ˡ�\n");
    }        
    if(!::practice_skill(me)) {
        return 0;
    }
    me->add("force", -10); 
    return 1;
}   
