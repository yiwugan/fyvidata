 // snowwhip.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "��ѩ�޷�");
        set("usage/whip", 1);
        set("usage/parry", 1);
        set("effective_level", 150);
        set("learn_bonus", 20);
        set("practice_bonus", 10);
        set("black_white_ness", 20);
        set("parry_msg", ({
        "$n���е�$vһ������������һ��ҧ��$N����ۡ�\n",
                "$nһ�����е�$v��ʹ�����۱޳�ǹ���Ĺ��򣬱���ֱ��$N�Ļ��ڡ�\n",
                "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
                "$nʹ��һ�С���ѩ���������Ƶ�$N�˳����⡣\n",
                
        }) );
        set("unarmed_parry_msg", ({
        "$n���е�$vһ������������һ��ҧ��$N����ۡ�\n",
        "$nһ�����е�$v��ʹ�����۱޳�ǹ���Ĺ��򣬱���ֱ��$N�Ļ��ڡ�\n",
        "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
        "$nʹ��һ�С���ѩ���������Ƶ�$N�˳����⡣\n",
        }) );
        action = ({
                ([      "name":                 "��������",
                        "action":               
                        "$Nʹһ�С��������⡹������$w���ñ�ֱ��$n��$l��������",
                        "dodge":                -10,
                        "damage":               30,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "�����ѩ",
                        "action":               
                        "$N����һת��һ�С������ѩ��$w�ó������Ӱ������ʵʵ��Ϯ��$n��$l",
                        "dodge":                -50,
                        "damage":               20,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "ѩ������",
                   "action":               
                        "$N����$w��һ�С�ѩ�����桹����ӰƮ�������ص���$n��$l",
                        "dodge":                -40,
                        "damage":               25,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��ѩ����",
                        "action":               
                        "$N����$wһ����һ�С���ѩ���ߡ���һ������ĽǶ���$n���̾�ȥ",
                        "dodge":                -40,
                        "damage":               30,
                        "damage_type":  "����"
                ]),
                ([
                        "name":                 "�����ѩ",
                        "action":               
                        "$N����һ����ʹ�С������ѩ��������$wһ�޽���һ�޲�ͣ�س���$n��$l",
                        "dodge":                -50,
                        "damage":               100,
                        "damage_type":   "����"
                ]),
                ([      "name":                 "��ѩ����",
                        "action":               
                        "$Nһ�С���ѩ���ӡ�����$w���һƬ��Ӱɨ��$nȫ��",
                        "dodge":                -60,
                        "damage":               150,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_force") < 150 ){
                return notify_fail("�������������û�а취����ѩ�޷�, ����Щ���������ɡ�\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ){
                return notify_fail("�������������û�а취��ϰ��ѩ�޷���\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        write("�㰴����ѧ����һ�麮ѩ�޷���\n");
        return 1;
}    
