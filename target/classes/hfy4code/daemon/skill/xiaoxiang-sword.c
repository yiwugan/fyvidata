//���㽣����ʧ���Ѿã��������������崦ϰ�ã���仯����֮�࣬���佣���ѳ����ҡ�ximen@sxfy
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "���㽣��");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("skill_class", "tieflag");
        set("effective_level", 250);
        set("level",           2);
        set("learn_bonus", 20);
        set("practice_bonus", 10);
        set("black_white_ness", -10);
        
        set("parry_msg", ({
        "$n������ת��һ�С������޷졹��$v����һƬ��Ӱ����$nȫ��\n",
        "$nһ����Ц������$v�û��������ǵ��$N�Ĺ��ƻ�Ϊ���Ρ�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n������ת��һ�С������޷졹��$v����һƬ��Ӱ����$nȫ��\n",
        "$nһ����Ц������$v�û��������ǵ��$N�Ĺ��ƻ�Ϊ���Ρ�\n",
        }) );   
        action = ({
        ([      "action":
"$Nʹ��һ�С�ѩ�亮÷�������е�$w���������������$n��$l����",
                "dodge":                70,
                "parry":		50,
                "damage":               70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С���÷���ޡ���$w��Ϊһ�������$n���������ҪѨ",
                "dodge":                80,
                "parry":		60,
                "damage":               80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�������������$w�ڿ��л���һ���⻷������$n��$l",
                "dodge":                90,
                "parry":		80,
                "damage":               90,
                "damage_type":  "ն��"
        ]),
        ([      "action":
"$N���һ����һ�С��ͷ��һ���������$w�����㷱�ǣ���$n��Χ�γ���һ����Ļ",
                "dodge":                80,
                "parry":		80,
                "damage":		100,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���ֽ�ָ��ɣ������е�$wһ�С�ԧ��˫�ɡ�б��$n��$l",
                "dodge":                60,
                "parry":		120,
                "damage":		120,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���ƺ����ǰ��������$w����ӷ���ȴ��һ�С��ļ��紺��",
                "dodge":                90,
                "parry":		80,
                "damage":               110,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ�С�������Ʈ����$w����ػ�������Բ������$n��$l��ȥ",
                "dodge":                100,
                "parry":		100,
                "damage":               120,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 10 )
            return notify_fail("��������������޷�ѧϰ���㽣����\n");
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 10 ) {
       return notify_fail("��������������޷�ѧϰ���㽣����\n");
    }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -10);
    write("�㰴����ѧ����һ�����㽣����\n");
    return 1;
}