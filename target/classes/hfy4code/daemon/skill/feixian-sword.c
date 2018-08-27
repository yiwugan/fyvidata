 // feixian-sword.c
#include <ansi.h> 
inherit SKILL;
void setup() {
        set("name", "���ɽ���");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("skill_class", "baiyun");
        set("effective_level", 150);
        set("learn_bonus", -50);
        set("practice_bonus", 10);
        set("black_white_ness", 15);
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
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����ɽ����еġ���ɽ������������ն��$n��$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������С������ζ�Ȼ�������ߣ�����$wն��$n��$l",
                "dodge":                30,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ�����ն�������׼$n��$l�̳�һ��",
                "dodge":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С����к�ء���׼$n��$lбб�̳�һ��",
                "dodge":                40,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С�һ������������$n��$l",
                "dodge":                20,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С��������������ֶ�׼$n$lһ����ȥ",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С������ܲ�������һ���⻡����$n��$l",
                "dodge":                30,
                "damage":               50,
                "force":                100,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 50 ) {
            return notify_fail("�������������û�а취�����ɽ�����\n");
        }
    if( (string)me->query_skill_mapped("force")!= "painting") {
            return notify_fail("���ɽ���������ϣۻ����ݲ�����ϰ��\n");
        }
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 3) {
        return notify_fail("�������������û�а취��ϰ���ɽ�����\n");
    }
    if(!::practice_skill(me)) {
        return 0;
    }
    me->add("force", -3);
    write("�㰴����ѧ����һ����ɽ�����\n");
    return 1;
}  
mixed hit_ob(object me, object victim)
{       
        int level_bonus, extra;
        object weapon;
        if (me->query_skill_mapped("force") != "painting")
                return ("");
        level_bonus = me->query_skill("chess", 1);
        
        if (extra =(int) me->query_temp("apply/painting") && random(8)) {
                extra += extra * ((int) me->query("combat_exp")/800000) 
                                + 20 * (int)victim->query("resistance/kee")
                                + (int)victim->query_skill("iron-cloth")/20;
                victim->receive_wound("kee", extra/2 +  random(extra), me);
                message_vision(CYN"$N��ʽ�ö����飬�Ƶ����ǹ��뻭���������������â����$n��\n"NOR, me, victim);
                COMBAT_D->report_status(victim);
                
        }
        if ((int) me->query("force_factor") + random(level_bonus) >
 (int) victim->query("force_factor") )
        {
           if ( random(5)&& !victim->is_busy()){
                        victim->start_busy(1+ random(5));  
            return (WHT "$N�Ľ���һ�����յģ۹���ƪ���Ȼ����գ����Ʊ���޷���\n$n����ʱ������æ���ң�\n" NOR);
                }
        }
        return ("");
                
}     
