 // yinhua-sword.c ӣ������
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "ӣ������");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("effective_level", 260);
        set("black_white_ness", -10);
        set("skill_class", "bat");
        set("parry_msg", ({
        "$n�������Ʈ�䣬����$vƽָ����������$N���գ�\n",
                "$n��������� ����׾ٵļ�ס��$N��$w��\n",
                "$n����һ���������е�$v����ǧ�ٽ�â����ס��ȫ��\n",
                "$n���е�$v���綶������ס��$N�����й��ơ�\n",
        }) );   
        action = ({
                ([      "action":               
                "$N����$w����΢�񣬻ó�һ���׹����$n��$l",
                        "dodge":                -200,
                        "parry" :               -200,
                        "damage":               70,
                        "force" :               200,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$N����Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
                        "dodge":                -200,
                        "parry" :               -200,
                        "damage":               50,
                        "force" :               100,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$N��������Ծ��$w��â��ˮ��һкǧ�����$n��$l",
                        "dodge":                -200,
                        "parry" :               -300,
                        "damage":               150,
                        "force" :               250,
                        "damage_type":  "����"
           ]),
                ([      "action":               
                "$N����$wбָ���죬��â���£�����׼$n��$lбб����",
                        "dodge":                -100,
                        "parry" :               -100,
                        "damage":               50,
                        "force" :               150,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$N��ָ�����㣬����$w�Ƴ�����ѩ����â������$n��$l",
                        "dodge":                -250,
                        "parry" :               -250,
                        "damage":               90,
                        "force" :               220,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$N���Ƶ�����$w�Ի���Ծ�����缲�������$n��$l",
                        "dodge":                -20,
                        "damage":               50,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
        if( (int)me->query("max_force") < 100 ){
                return notify_fail("�������������û�а취��ӣ��������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ){
                return notify_fail("�����������������û�а취��ϰӣ��������\n");
        }
   if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        write("�㰴����ѧ����һ��ӣ��������\n");
        return 1;
}  
