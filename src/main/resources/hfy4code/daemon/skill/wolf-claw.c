 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "�����ǻ�צ");
        set("usage/unarmed", 1);
        set("effective_level", 150);
        set("practice_bonus", -10);
        set("black_white_ness", -30);
        set("skill_class", "wolf");
        set("parry_msg", ({
        "$n��ָбն$N����ؽڣ�$Nֻ�����С� \n",
        "$n����ץ$N˫Ŀ������������ȵ�$NһԾ�˿��� \n",
        "$nצӰƮ����ס��$N�Ĺ��ơ� \n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n��ָбն$N����ؽڣ�$Nֻ�����С� \n",
        "$n����ץ$N˫Ŀ������������ȵ�$NһԾ�˿��� \n",
        "$nצӰƮ����ס��$N�Ĺ��ơ� \n",
        }) );   
        action = ({
        ([      "action":               
"$N��Ŀע��$n���Գ�һ��������˼�����飬��Ȼ���Ӷ�ǰץ��$n��$l�� ",
                "dodge":                100,
                "parry":                100,
                "damage":                70,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nб��������˫צ����ץ������ȡ$n��$l�� ",
                "dodge":                200,
                "parry":                200,
                "damage":                90,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$NĿ��Ư�Ʋ������ƺ�$n��������ʲô��״����Ȼ��$n���������ץ��$n��$l�� ",
                "dodge":                250,
                "parry":                250,
                "damage":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N������צ������$n��ȫ����������������һ���ķ��۽���������ɱ�֣� ",
                "dodge":                300,
                "parry":                300,
                "damage":                140,
                "damage_type":  "ץ��"
        ]),
        });
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
        if((int)me->query_skill("wolf-strike",1) < 160){
        return notify_fail("������ǰ���ȭ����㣬�޷����Ե����ǻ�צ��\n");
    }
        return 1;
}  
int practice_skill(object me)
{
        return notify_fail("�����ǻ�צֻ����ѧ�ġ�\n");
}  