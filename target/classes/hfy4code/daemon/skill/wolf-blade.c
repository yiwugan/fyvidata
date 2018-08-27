 // wolf-blade.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "������Ѫ��");
        set("usage/blade", 1);
        set("usage/parry", 1); 
        set("effective_level", 220);
        set("learn_bonus", -200);
        set("black_white_ness", -100);
        set("skill_class", "wolf");
         
        set("parry_msg", ({
        "$nһ����Ц�����β�ͣ���������е�$v��ƫ����������$N��$w���棬���$N�ֱ۷��飡\n",
        "$n���һ�����߾ٵ�$vͻȻ������£�$Nֻ��һ��������Լ�ӭ���������æ���С�\n",
        "$N�ۿ��Լ���$w��������$n����ȴ���ֶԷ���$v��֪��ʲôʱ���Ѿ������Լ����ʺ���æ�����Ա���\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nһ����Ц�����β�ͣ���������е�$v��ƫ����������$N��$w���棬���$N�ֱ۷��飡\n",
        "$n���һ�����߾ٵ�$vͻȻ������£�$Nֻ��һ��������Լ�ӭ���������æ���С�\n",
        "$N�ۿ��Լ���$w��������$n����ȴ���ֶԷ���$v��֪��ʲôʱ���Ѿ������Լ����ʺ���æ�����Ա���\n",
        }) );
        action = ({
        ([      "action":               "$N���ο��籼���е�Ұ�ǣ����е�$w����һ��ɱ��������$n��$l��",
                "damage":               80,
                "dodge":                100,
                "parry":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��Хһ�������е�$w����һ��Ѫ��ζֱ��$n��$l��",
                "dodge":                100,
                "parry":                80,
                "damage":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������ʳ��Ұ�ǣ�����׼ȷ��Ѹ�����׺ݣ�$nֻ�����Լ�������$N�ĵ����Χ�С�",
                "damage":               150,
                "dodge":                100,
                "parry":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��Ծ����˫����ס$w����������$n��$l��",
        				"damage":               150,
                "dodge":                140,
                "parry":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������ϣ����е�$w�����ĵ�������Ⱥ��һ�㣬�·�Ҫ��$n˺����Ƭ!",
                "damage":               180,
                "dodge":                150,
                "parry":                150,
                "damage_type":  "����"
        ]), 
        });
}         
int practice_skill(object me)
{
    if((int)me->query("force") < 10 ){
        return notify_fail("�����������������û�а취��ϰ������Ѫ����\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -10);
    write("�㰴����ѧ����һ��������Ѫ����\n");
    return 1;
}   