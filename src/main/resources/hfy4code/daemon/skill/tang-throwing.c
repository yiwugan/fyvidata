 // tang-throwing.c
inherit SKILL; 
void setup(){ 
        set("name", "���Ű���"); 
        set("usage/throwing", 1); 
        set("skill_class", "tangmen"); 
        set("effective_level", 180); 
        set("practice_bonus", -5); 
         
        action = ({ 
        ([      "action":                
"$N˫��һ�Σ����е�$w��һ�����߰����$n��$l", 
                "dodge":                -20, 
                "damage":               30, 
                "post_action":  "throw_weapon", 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N����һ����$w�����̶����ƿ���ֱ��$n��$l", 
                "dodge":                -40, 
                "damage":               30, 
                "post_action":  "throw_weapon", 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N��ָ΢����$wбб�ķ���$n��$l", 
                "dodge":                -40, 
                
                "post_action":  "throw_weapon", 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N�������⣬����һ˦�����е�$w����һ����������$n��$l", 
                "dodge":                20, 
                "post_action":  "throw_weapon", 
                "damage":               40, 
                "damage_type":  "����" 
        ]), 
        }); 
} 
int valid_learn(object me) 
{ 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
    if( (int)me->query("max_force") < 50 ){ 
        return notify_fail("�������������û�а취�����Ű�����\n"); 
        } 
    return 1; 
} 
 
int practice_skill(object me) 
{ 
 
        if((int)me->query("force") < 3 ){ 
                return notify_fail("�����������������û�а취��ϰ������\n"); 
    } 
    if(!::practice_skill(me)){ 
        return 0; 
    } 
    me->add("force", -3); 
        write("�㰴����ѧ����һ�����Ű�����\n"); 
    return 1; 
} 
 
