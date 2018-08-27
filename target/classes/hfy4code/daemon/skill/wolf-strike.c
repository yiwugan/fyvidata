 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "���ǰ���ȭ");
        set("usage/unarmed", 1);
        set("effective_level", 120);
        set("learn_bonus", 10);
        set("black_white_ness", -10);
        set("skill_class", "wolf");
        set("parry_msg", ({
        "$n��ɫ������������$N����$N�е��޷����С� \n",
                "$n����һ�����ַ�ץ$N������$N��æ�˲��Ա��� \n",
                "$n˫ȭ����ӳ���������ң��ȵ�$N�������ˡ� \n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n��ɫ������������$N����$N�е��޷����С� \n",
        "$n����һ�����ַ�ץ$N������$N��æ�˲��Ա��� \n",
        "$n˫ȭ����ӳ���������ң��ȵ�$N�������ˡ� \n",
        }) );
        
        action = ({
        ([      "action":               
"$N����$n�������ߣ�ͻȻ�����϶������ͻ�$n��$l�� ",
                "dodge":                110,
                "parry":                110,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ɨ������;����һ����˫�ֺ�£ץ��$n��$l�� ",
                "dodge":                130,
                "parry":                130,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������Х����ȻһԾ���𣬺��⹥��$n��$l�� ",
                "dodge":                150,
                "parry":                150,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nб��һת�����Ƴ�צ���$n���ţ���������б��$n��$l�� ",
                "dodge":                170,
                "parry":                170,
                "damage":                70,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
        if((int)me->query_skill("wolf-force", 1) < 10){
            return notify_fail("��������ķ�����㣬�޷������ǰ���ȭ��\n");
        }
        if (me->query("combat_exp")<2000000 && me->query_skill("wolf-strike",1)>150){
                tell_object(me,"���ʵս����̫��,�޷���һ���������ǰ���ȭ��\n");
                return 0;
        }
        if (me->query("combat_exp")<3000000 && me->query_skill("wolf-strike",1)>160){
                tell_object(me,"���ʵս����̫��,�޷���һ���������ǰ���ȭ��\n");
                return 0;
        }
        if (me->query("combat_exp")<4500000 && me->query_skill("wolf-strike",1)>170){
                tell_object(me,"���ʵս����̫��,�޷���һ���������ǰ���ȭ��\n");
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        
        if( (int)me->query("force") < 5 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
   }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        return 1;
}    
