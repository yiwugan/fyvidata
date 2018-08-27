 // tenderzhi.c
inherit SKILL;
#include <ansi.h>
void setup(){
        set("name", "���ָ");
        set("usage/unarmed", 1);
        set("effective_level", 200);
        set("learn_bonus", -100);
        set("practice_bonus", -5);
        set("black_white_ness", 40);
        set("skill_class", "mei");
        
        set("parry_msg", ({
        "$n��ָ΢��$N$w�ļ�ˣ�$N���е�$w�������ֶ�����\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n�����ָ�������㣬ָ��ֱ��$N�������Ѩ��\n",
        }) );   
        action = ({
        ([      "action":               
"$N����һ�ӣ�һ�С���¥���¡����ֵ���$n$l",
                "dodge":                30,
                "parry":                30,
                "force":                80,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"$Nʹһ�С�ѩ����÷������Ӱ��ǰ���ᣬͻȻһת��������$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"$N���Զ٣�����һ��ʹ������ͤ��������$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "force":                140,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"ֻ��$N����һ�ڣ���Ȼ�������ߣ�����˳������һ�С��ҷ��˵�����$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        });
}
int valid_learn(object me)
{
    if((string)me->query("gender") != "Ů��") {
        return notify_fail("���ָ��ֻ��Ů�Ӳ��������书��\n");
    }
    if((int)me->query("max_force") < 250 ){
        return notify_fail("�������������\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
        if(!::practice_skill(me)){
                return 0;
        }
        if (me->query_skill("tenderzhi",1)>180)
                return notify_fail("���ָ��Ϊ��£������ϵ��Լ������о����С�\n");
        
    if((int)me->query("force") < 10 ) {
        return notify_fail("������������ˡ�\n");
        }
    me->add("force", -10);
    return 1;
}

int effective_level()
{
        object me=this_player();
        int skill,n;
         skill=me->query_skill("tenderzhi",1);
        if (skill > 199) return 299;
        if (skill < 200) return 200;
        
                
}  

  
mixed hit_ob(object me, object victim, int damage_bonus)
{
           object my_weapon;
        int badint;
//      my_weapon=me->query_temp("weapon");
        if(damage_bonus < 300 ) return 0;
        if(victim->query_skill_mapped("iron-cloth") == "yijinjing") {
                badint = 3*victim->query_skill("iron-cloth")+random(victim->query_skill("iron-cloth"));
                if(badint) {
                        victim->receive_wound("gin",badint);
                        switch(random(2)) {
                                case 0: return HIW"$Nָ�����˿˿����,������$n�Ļ����񹦣�\n"NOR;
                                case 1: return HIW"$nֻ����ͷһ��,$N������ָ����͸����� ������\n"NOR;
                        }
                }
        }
        return 0;
}   
