 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without 
// the written permission from authors. 
inherit SKILL; 
void setup(){ 
        set("name", "Ϣ������"); 
        set("usage/blade", 1); 
        set("usage/parry", 1); 
//        set("practice_damage", 40); 
        set("effective_level", 200); 
        set("learn_bonus", 200);
        set("black_white_ness", 200);
        set("practice_bonus", 200); 
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
                "$n�����ؽ����е�$v������ǰ��ǿ�ҵĵ��罫$N�Ƶ����˼�����\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$n���е�$v�����ػӳ������Ҳ����ĵ������$N��\n", 
        }) );    
        action = ({ 
                ([      "action":               "$N���е�$wһ�Σ�һ��[�ĵ�]����$n��$l", 
						"dodge":				10,
						"parry":				10,
						"force":                100, 
                        "damage":               800, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N���е�$w���裬Ϯ����$n��$l", 
						"dodge":				30,
						"parry":				30,
                        "damage":               1000, 
                        "force":                150, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N��$wն�����ƣ����ۺ�ɢ�ؿ���$n��$l", 
						"dodge":				50,
						"parry":				50,
                        "force":                70, 
                        "damage":               1500, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N�ζ����е�$w������������֣�����$n��$l", 
						"dodge":				70,
						"parry":				70,
                        "force":                100, 
                        "damage":               2000, 
                        "damage_type":  "����" 
                ]), 
           ([      "action":               "$N���������е�$w����������$n", 
						"dodge":				10,
						"parry":				10,
                        "force":                100, 
                        "damage":               1000, 
                        "damage_type":  "����" 
                ]), 
        }); 
} 
int valid_learn(object me){ 
        if( (int)me->query_skill("force", 1) < 100 ) { 
            return notify_fail("����ڹ��ķ�����㣬�޷���Ϣ��������\n"); 
        } 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
        return 1; 
} 

int practice_skill(object me)
{
        object weapon; 
        if( (int)me->query("kee") < 40 ) {
                return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
		}
        me->receive_damage("kee", 40);
        return 1;
}  

