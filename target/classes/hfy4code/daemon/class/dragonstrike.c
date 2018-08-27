 // TIE@FY3
inherit SKILL;
#include <ansi.h>  
void setup() {
        set("name", "����ʮ����");
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        set("practice_damage", 20);
//      set("effective_level", 130);
        set("learn_bonus", -20);
        set("practice_bonus", -150);
        set("practice_limit",140);
        set("black_white_ness", 0);
        set("skill_class", "beggar"); 
        set("parry_msg", ({
        "$n˫��΢�֣�ʹ��һ�С�������β������ž����һ����$N��$w������\n",
        "$n��һת��һ�С������������$N����$w���֡�\n",
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n����������һ�С��𾪰������ĳ����ƣ��Ƶ�$N�����Ա���\n",
        "$nʩչ����������β�������赭д�Ļ�����$N�Ĺ��ơ�\n",
        }) );   
        action = ({
([      "action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l",
        "dodge": 30,
        "parry": 10,
        "force": 400,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l",
        "dodge": 15,
        "parry": 20,
        "force": 800,
        "damage_type": "����"
]),
([      "action": "$N����һ�С����������Ѹ���ޱȵ�����$n��$l",
        "dodge": 10,
        "parry": 10,
        "force": 720,
   "damage_type": "����"
]),
([      "action": "$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l",
        "dodge": 15,
        "parry": 10,
        "force": 900,
        "damage_type": "����"
]),
([      "action": "$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l",
        "dodge": 10,
        "parry": 10,
        "force": 500,
        "damage_type": "����"
]),
([      "action": "$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l",
        "dodge": 10,
        "parry": 20,
        "force": 500,
        "damage_type": "����"
]),
([      "action": "$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
        "dodge": 0,
        "parry": 10,
        "force": 500,
        "damage_type": "����"
]),
([      "action": "$N���һ����˫��ʹ�����𾪰��������һ�а����$n",
        "dodge": 25,
        "parry": 10,
        "force": 700,
        "damage_type": "����"
]),
([      "action": "$Nʹ������Ծ��Ԩ������$n��$l��������",
        "dodge": 20,
        "parry": 20,
        "force": 300,
        "damage_type": "����"
]),
([      "action": "$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l",
        "dodge": 10,
   "parry": 20,
        "force": 460,
        "damage_type": "����"
]),
([      "action": "$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����",
        "dodge": 20,
        "parry": 30,
        "force": 900,
        "damage_type": "����"
]),
([      "action": "$N˫������ʹ����ʱ����������$n��������",
        "dodge": 20,
        "parry": 20,
        "force": 870,
        "damage_type": "����"
]),
([      "action": "$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l",
        "dodge": 15,
        "parry": 20,
        "force": 220,
        "damage_type": "����"
]),
([      "action": "$Nʹ�����������ڡ���˫�������������$n��$l",
        "dodge": 25,
        "parry": 10,
        "force": 350,
        "damage_type": "����"
]),
([      "action": "$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l",
        "dodge": 20,
        "parry": 40,
        "force": 630,
        "damage_type": "����"
]),
([      "action": "$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ",
        "dodge": 25,
        "parry": 1,
        "force": 420,
        "damage_type": "����"
]),
([ "action": "$Nʹ��������ެ����˫���������ϻ���$n��$l",
        "dodge": 15,
        "parry": 40,
        "force": 600,
        "damage_type": "����"
]),
([      "action": "$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l",
        "dodge": 10,
        "parry": 40,
        "force": 620,
        "damage_type": "����"
]),
}); 
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������̫�����޷�������ʮ���ơ�\n");
        return 1;
} 
int practice_skill(object me)
{
        if ((int)me->query("force") < 20) {
                return notify_fail("�����������������ʮ���ơ�\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 500 ) return 0;
        badint = victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth")*2;
        if (victim->query_skill_mapped("iron-cloth") == "jin-gang"
           ||victim->query_skill_mapped("iron-cloth") == "spring-water"
                ||victim->query_skill_mapped("iron-cloth") == "henglian"
                ||victim->query_skill_mapped("iron-cloth") == "yijinjing"
                ||victim->query_skill_mapped("iron-cloth") == "xisui"
                ) {
                if(badint) {
                        victim->receive_wound("kee",badint);
                        switch(random(3)) {
                                case 0: return "$N��ɽ��ţ����������һ�����죬�����ǹ����������\n";
                                case 1: return "$N�������£�$n��$l������������һ�����죡\n";
                                case 2: return "ֻ����$n��$l��������һ�� ������\n";
                                }
                }
        }
}  
int effective_level()
{
        object me;
        int skill,n;
        
        skill=this_player()->query_skill("dragonstrike",1);
        if (skill<=170) return 130;
        if (skill>=190) return 170;
        
        n=(skill-170)/5*10+130;
        return n;
} 
int learn_bonus() {
        
        int skill;
        skill = this_player()->query_skill("dragonstrike",1);
        if (skill<=170) return -20;
                else return -400;
}      
