 // qingpingsword.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "��ƽ����");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("skill_class", "shenshui");
        set("effective_level", 220);
        set("learn_bonus", 10);
        set("practice_bonus", -5);
        set("black_white_ness", 5);
        set("parry_msg", ({
        "$nʹ��һ�С�������졹�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
        "$nʹ��һ�С�������ѩ�������е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ����һ�С����ش��ס�����$N��$w��������ȥ��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��������ա�����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С�������졹��$vֱ��$N��˫�֡�\n",
        "$n�����е�$v���������������ȵ�$N�������ˡ�\n",
        }) );
        action = ({
        ([      "action":               
"$Nʹһ�С����·ת��������$w��һ�����߰����$n��$l",
                "dodge":                20,
                "damage":               80,
                "force":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����ƽ�����еġ���ɽ������������ն��$n��$l",
                "dodge":                20,
                "damage":               120,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������С������ζ�Ȼ�������ߣ�����$wն��$n��$l",
                "dodge":                30,
                "damage":               80,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ�����ն�������׼$n��$l�̳�һ��",
                "dodge":                40,
                "damage":               70,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С����к�ء���׼$n��$lбб�̳�һ��",
                "dodge":                40,
                "damage":               100,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С�ͯ����·������$n��$l",
                "dodge":                20,
                "damage":               150,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С��������������ֶ�׼$n$lһ����ȥ",
                "dodge":                20,
                "damage":               110,
                "force":                180,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С��չ���硹����һ���⻡ն��$n��$l",
                "dodge":                30,
                "damage":               80,
                "force":                110,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{ 
    if( (int)me->query("max_force") < 50 ){
        return notify_fail("�������������û�а취����ƽ������\n");
        }
    if(me->query_skill("qingpingforce",1)+40<me->query_skill("qingpingsword",1)){
        return notify_fail("�����ƽ�ڹ��������\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 10 ){
        return notify_fail("�����������������û�а취��ϰ��ƽ������\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -10);
    write("�㰴����ѧ����һ����ƽ������\n");
    return 1;
} 
mixed parry_ob(object victim,object me)
{
        int mylvl,extra ;
        string msg;
        mylvl=me->query_skill("nine-moon-force",1);
        if (extra=me->query_temp("nine-moon-force_poison"))
        {
                victim->receive_wound("kee",extra/3,me);
                victim->add("kee",-extra/3);
                if (!victim->query_temp("weapon"))      return MAG"$Nֻ�����ִ�����һ������������׶�Ķ�����\n"NOR;
                        else return MAG"$Nֻ��һ�㵭���������ӱ��������Ӷ������̹ǵĺ�������������ת�����顣\n"NOR;
                
           return msg;
        }
} 
