#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "�ٵ�");
        set("usage/magic", 1); 
        set("learn_bonus", -50);
        set("practice_bonus", -1000);
        set("black_white_ness", 120);
        set("effective_level", 180);
        set("skill_class", "baiyun");
        /*
        set("parry_msg", ({
        "$n����Ĵָʳָ����������ӣ������������۱��̣�֮����һ��������$N�ȿ���\n",
        "$n��������黮�����������������������������֮����$N�����е����񺳶���\n",
        "$n����ר���������ḧ���粦���ң����ഫ����������֮����$NһʱãȻ��֪���ԡ�\n", 
        }) );
        set("unarmed_parry_msg", ({
        "$n����Ĵָʳָ����������ӣ������������۱��̣�֮����һ��������$N�ȿ���\n",
        "$n��������黮��������������������������ǣ�֮����$N�����е����񺳶���\n",
        "$n����ר���������ḧ���粦���ң����ഫ����������֮����$NһʱãȻ��֪���ԡ�\n", 
        }) );
        action = ({
        ([      "action":               "$N��ָ���������󼲷����������̣�����۱����֮����Ϯ��$n��$l",
                "dodge":                180,
                "parry":                20,
                "damage":               70,
                "damage_type":          "����",
                "weapon":               "ָ��",
        ]),
        ([      "action":               "$N�������ã��۱�ǣ���������Χ����ĵ�¡¡����ʮ�����Χ��$n",
                "dodge":                140,
                "parry":                90,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������������ֺ��������������̣�֮�����ޱ�˿�꣬����Ʈ��$n��$l",
                "dodge":                120,
                "parry":                120,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����ֱ�ģ��������������ɢ�������������ģ����̣�֮���У�����$n��$l",
                "dodge":                160,
                "parry":                20,
                "damage":               10,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫����Ȼ�»���������������۱����֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                100,
                "damage_type":  "����"
        ]),
        });
*/
}   
/*
mixed parry_ob(object victim, object me)
{       int busy_time;
        int skill;
        int my_exp, your_exp;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        
        skill=me->query_skill("chess",1);
        
        if (random(skill) + skill/3 > 100 && me->is_busy()) {
                message_vision(HIG"$N�����һ��������ͨ���ĵ��ģ۵���ƪ��������Ŀ��������Ȼ����������\n"NOR, me);       
                me->stop_busy();
        }
        
        return 0;
}        
*/   
