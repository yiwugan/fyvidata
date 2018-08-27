 // doomstrike.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "��������");
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        set("learn_bonus", -300);
        set("practice_bonus", -15);
        set("black_white_ness", -10);
        set("effective_level",160);
        set("skill_class", "fighter");
        
        set("parry_msg", ({
                "$n����Ϊ����һ�С���Ѫ��ָ��������$N����$w���֡�\n",
                "$n˫�ƽ���ʹ��һ�С�ͯ�Ӱ��١�����ž����һ����$N��$w����˫��֮�䡣\n",
                "$n��һת��һ�С���������������$N����$w���֡�\n",
                "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
                 "$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
                "$n����Ϊָ��һ�С���ָ˫�ɡ�����$N������ҪѨ��\n",
                "$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
        }) );   
        
         
        action = ({
        ([      "action":               
"$Nʹ��һ�С�������ʽ�������ƴ�������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С�������ʽ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������Ʒ���С����ʽ��������Ȱ�����$n��ǰ��һ������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ����ѩ����ʽ������׼$n��$l�����ĳ�����",
                "dodge":                10,
                "parry":                30,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��������ķ�������$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����������Ƕϡ�������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                "dodge":                70,
                "parry":                10,
                "force":                180,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����������һ�С����������졹˫�Ʋ����Ƴ�",
                "dodge":                270,
                "parry":                340,
                "force":                420,
                "damage_type":  "����"
        ]),
        });
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
           return 0;
        }
        if( (int)me->query_skill("doomforce", 1) < 20 ) {
                        return notify_fail("��Ĵ�Ѫ�񹦻���㣬�޷����������ơ�\n");
        }
        if( (int)me->query("max_force") < 100 ) {
                return notify_fail("�������̫�����޷����������ơ�\n");
        }
        return 1;
}  

mixed hit_ob(object me, object victim, int damage_bonus) {
        if(random(damage_bonus) < 50) {
                return 0;
        }
        if(!victim->query_temp("weapon") 
                        && victim->query_skill_mapped("unarmed") == "taiji"
                        && me->query_skill("unarmed") > victim->query_skill("unarmed")) {
                switch(random(3)) {
                        case 0:
                                message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                                break;
                        case 1:
                                message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                                break;
                        case 2:
                                message_vision(HIR "\n��ȭ����ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                                break;
                }
                return random(me->query_skill("unarmed")) * 10;
        }
        return 0;
}   