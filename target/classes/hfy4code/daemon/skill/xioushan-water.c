 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without 
// the written permission from authors. 
inherit SKILL; 
void setup(){ 
        set("name", "��ɽ��ˮ��"); 
        set("usage/unarmed", 1); 
        set("usage/parry", 1);   
        set("effective_level", 190); 
        set("practice_bonus", -5); 
        set("skill_class", "quanli"); 
         
        set("parry_msg", ({ 
                "$n���ˮ�˽�$N�Ƶ����˼�����\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$n����һ��ˮ������$N��\n", 
        }) ); 
        action = ({ 
                ([      "action":               "$N����ˮ��Ϯ��$n��$l", 
                        "force":                400, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$Nһ��[ˮ������]���Ƿ�����$n��$l", 
                        "damage":               200, 
                        "force":                300, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N����ˮ�еĺ�֭�����ۺ�ɢ���ƻ���$n��$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N���ˮ��ɢ��$n��$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
           ([      "action":               "$N����ȫ��Ĺ�����˫�ִ����ˮ����$n", 
                        "force":                200, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
        }); 
} 
int valid_learn(object me) 
{ 
        if( (int)me->query_skill("wuchenforce", 1) < 120 ){ 
            return notify_fail("����ڹ��ķ�����㣬�޷�����ɽ��ˮ����\n"); 
        } 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
        return 1; 
}  
