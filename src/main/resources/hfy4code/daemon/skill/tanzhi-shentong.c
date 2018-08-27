 // tanzhi-shentong.c
inherit SKILL;
#include <ansi.h>
mapping* throwing_action;
void setup(){ 
        
        set("name", "��ָ��ͨ");
//      set("usage/unarmed", 1); --- for uniqueness/balance of huashan skill, by silencer
        set("usage/throwing", 1);
        set("usage/parry", 1); //this is taken care of in enable.c
        set("effective_level", 200);
        set("learn_bonus", -250);
        set("practice_bonus", -10);
//      set("practice_limit",165);
        set("black_white_ness", 5);
        set("skill_class", "huashan");
        
        set("parry_msg", ({
        "$n����ָ������һ��ָ�����$N����Ѩ��$N��æ�������С�\n",
                "$n�����ᵯ��ɭɭָ�����$N˫Ŀ��$N�����������۾���\n",
                "$nǳЦ���У�����ʳָ�ᵯ��һ�ư�������$N����Ѩ��$N���������������ˡ�\n", 
        }) );
        set("unarmed_parry_msg", ({
                "$n����ָ������һ��ָ�����$N����Ѩ��$N��æ�������С�\n",
                "$n�����ᵯ��ɭɭָ�����$N˫Ŀ��$N�����������۾���\n",
                "$nǳЦ���У�����ʳָ�ᵯ��һ�ư�������$N����Ѩ��$N���������������ˡ�\n", 
        }) );   
        action = ({
        ([      "action":               
"$Nʳָ΢�������ᵯ����һ��ϸϸ����������$n��$l",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "����",
                "weapon":               "ָ��",
        ]),
        ([      "action":               
"$N��ָ������ָ���絶������$n��$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "ָ��",
        ]),
        ([      "action":               
"$N����бչ��Сָ΢��б��$n��$l����̬����ɷ���",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "����",
                "weapon":               "ָ��",
        ]),
        ([      "action":               
"$N����ָ���͡��ص�����ָ�������������$n��$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "ָ��",
        ]),
        ([      "action":               
"$N����������������ָ����������Ĵָ��������$n��$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "ָ��",
        ]),     
        }); 
        throwing_action = ({
        ([      "action":               
"$Nʳָ΢�������ᵯ����$w���������$n��$l�� ",
                "dodge":                30,
                "parry":                30,
                "force":                280,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":               
"$N��ָ������ָ���絶��$w�ھ����з���$n��$l�� ",
                "dodge":                30,
                "parry":                30,
                "force":                290,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":               
"$N����бչ��Сָ΢�̽�$w����б��$n��$l����̬����ɷ�� ",
                "dodge":                30,
                "parry":                30,
                "force":                340,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":               
"$N����ָ���͡��ص�����$w�����������$n��$l�� ",
                "dodge":                30,
                "parry":                30,
                "force":                290,
                "damage_type":  "����",
                "weapon":               "����",
        ]),
        ([      "action":               
"$N����������������ָ����������Ĵָ��������$w����$n��$l�� ",
                "dodge":                100,
                "parry":                100,
                "force":                290,
                "damage_type":  "����",
                "weapon":               "����",
        ]),     
        });
}  
mapping query_action(object me, object weapon)
{
        if(this_player()->query_temp("weapon"))
                return throwing_action[random(sizeof(throwing_action))];
        else return action[random(sizeof(action))];
}
int valid_learn(object me)
{
/*  if((string)me->query("gender") != "Ů��") {
        return notify_fail("��ָ��ͨ��ֻ��Ů�Ӳ��������书��\n");
    }*/
    if((int)me->query("max_force") < 250 ){
        return notify_fail("�������������\n");
        }
    return 1;
} 
int practice_skill(object me)
{
        if(!::practice_skill(me)){
                return 0;
        }
    if((int)me->query("force") < 10 ) {
        return notify_fail("������������ˡ�\n");
        }
    me->add("force", -10);
    return 1;
}
  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 150 ) return 0;
    if( victim->query_temp("weapon")==0) {
        if(victim->query_skill_mapped("unarmed") == "dragonstrike" 
                && me->query_skill("tanzhi-shentong",1)+50 > victim->query_skill("dragonstrike",1)) {
        switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N�������ָ����$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
        return random(me->query_skill("throwing")) * 2;
        }
    }
    return 0;
}
