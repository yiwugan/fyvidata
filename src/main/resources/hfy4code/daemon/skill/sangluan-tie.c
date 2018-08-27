 // Copyright (C) 1995, by Sinny Shi. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "ɥ����");
        set("usage/unarmed", 1);
        set("effective_level", 120);
        set("practice_bonus", -10);
        set("black_white_ness", 10);
        set("skill_class", "baiyun");
        set("parry_msg", ({
        "$n������ɣ�˲Ϣ֮�䡸�����w��, �κ��κΡ�������$N��֪���롣 \n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n������ɣ�˲Ϣ֮�䡸�����w��, �κ��κΡ�������$N��֪���롣 \n",
        }) );   
        action = ({
        ([      "action":               
"$N��Хһ��������Ʈ�ݣ�ָ���絶����$n���ݺ�֮�䡸��֮���ס�����д������ͰΣ�
׿����Ⱥ��",
                "dodge":                -10,
                "parry":                10,
                "damage":               110,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���δ󿪴��أ�����Ĺ����ݱ����һ���ǳɣ�һ��һ�����Ǳ��ߣ���籩�������$n��",
                "dodge":                -30,
                "parry":                30,
                "damage":               140,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N���ⶶ�䣬���ֳٻ����أ�����ǧ��֮������$n��$l��д�����ǡ�׷Ω���������֡�",
                "dodge":                -50,
                "parry":                50,
                "damage":               160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����֮����$n��$l���¡���Ľ�ݾ���ʹ���ĸΡ����֣�����Ҳ���أ��Ƴ��֮������
��Ҳ�վ��������֮�ѡ� ",
                "dodge":                -70,
                "parry":                70,
                "damage":               180,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
    if((int)me->query_skill("chessism", 1) < 20){
        return notify_fail("����ĵ���Ϊ�������ĸ����겻����ϰ��ɥ��������\n");
    }
    return 1;
}  
int practice_skill(object me)
{
        if( (int)me->query("force") < 25 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -15);
        return 1;
}    
