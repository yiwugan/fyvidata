 // TIE@FY3
inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name", "�򹷰���");
        set("usage/staff", 1);
        set("usage/parry", 1);
        set("learn_bonus", -200);
        set("practice_bonus", -5);
        set("practice_limit",150);
        set("skill_class", "beggar");   
        set("effective_level", 210);
        set("parry_msg", ({
        "���$n�����е�$v����$N��$w��\n",
        "$n���ܲ�����һ�С�˫�����项������$vֱȡ$N��˫Ŀ��\n",
        "$n�ӳ�$v����ص���$N�����š�\n",
                })
        );
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n���ܲ�����һ�С�˫�����项������$vֱȡ$N��˫Ŀ��\n",
        "$n�ӳ�$v����ص���$N�����š�\n",
                })      
        );      
        action = ({
([      "action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
        "dodge": 10,
        "damage": 90,
        "damage_type": "����"
]),
([      "action": "$N����$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ",
        "dodge": 20,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$N����$w���Ӹ�����ʹһ�С���ݾ��ߡ�����$n��$l",
        "dodge": 30,
        "damage": 200,
        "damage_type": "����"
]),
([      "action": "$Nʩ�����������졹��$w����������$n��ȥ",
        "dodge": 20,
        "damage": 80,
        "damage_type": "����"
]),
([      "action": "$Nʩչ���򹷰����еġ��ذ���������$w��$nҪ����ȥ",
        "dodge": 20,
        "damage": 150,
        "damage_type": "����"
]),
        });
} 
int valid_learn(object me)
{
    if(!::valid_learn(me)) {
        return 0;
    }
    if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 ) {
        return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if( (int)me->query("kee") < 10 ) 
                return notify_fail("����������������Ź�������������Ϣ��Ϣ�ɡ�\n");
        
        if(!::practice_skill(me)) return 0;
        me->add("force",-5);
        return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 250 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "whip")
    if(victim->query_skill_mapped("whip") == "thunderwhip")
        if(me->query_skill("staff") > victim->query_skill("whip")) {
        switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n����޷���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("staff")) * 3;
    }
    return 0;
}
