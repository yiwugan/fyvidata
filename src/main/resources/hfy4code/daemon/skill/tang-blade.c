 // tang-blade.c
 
inherit SKILL; 
void setup(){ 
        set("name", "���������"); 
        set("usage/blade", 1); 
        set("usage/parry", 1); 
        set("effective_level", 200); 
        set("practice_damage", 40); 
        set("learn_bonus", -100); 
        set("practice_bonus", -50); 
        set("black_white_ness", 30); 
        set("skill_class", "tangmen"); 
        set("parry_msg", ({ 
        "$nʹ��һ�С�����һ�����������е�$v����$N����ָ��\n", 
                "$n���̤ǰһ����һ�С����໨�꡹�����е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n", 
                "$n���е�$vһ�������һƬ������һ�С��������ġ�������$N��ȫ��\n", 
                "$n΢��һ�������е�$v����һ���⻡��һ�С��Ի����ѡ�����$N��ȫ��Χס��\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
                "$nʹ��һ�С��������񡹣������е�$v����$N��\n", 
                "$n���̤ǰ̤��һ�С�һ�����¡������е�$v����$N֮�ؾȡ�\n", 
                "$n���е�$vһ����һ�С�ɽ��ˮԶ��������$N��\n", 
                "$n���е�$v����һ�С�����һʫ������$N��ȫ��Χס��\n", 
        }) ); 
 
        action = ({ 
                ([      "action":                
                "$Nʹһ�С���꼸�֡�������$w���Ƶ���$n��$lնȥ��", 
                        "damage":               70, 
                        "dodge":                70, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":                
                "$N�䵶���£�$w����һ�С������ʻ������¶�������$n��$l", 
                        "damage":               40, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":                
           "$N����һת��һ�С�����ƬƬƮ����$w�糯¶��˸��ն��$n��$l", 
                        "damage":               20, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":                
                "$N�趯$w��һ�С�ȥ�տ�ࡹ��$n��$lбб����һ��", 
                        "damage_type":  "����" 
                ]), 
                ([      "action":                
                "$N����$wһ�Σ�һ�С�����������Ѹ�����׵�����$n��$l", 
                        "damage":               70, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":                
                "$N�����������զչ��һ�С�������ֱ��$n$l", 
                        "damage":               30, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":                
                "$N�Ʋ�����ʹһ�С��λ����塹����ն��$n��$l", 
                        "damage":               50, 
                        "damage_type":  "����" 
                ]), 
        }); 
} 
int valid_learn(object me) 
{ 
    if((int)me->query("max_force") < 50 ){ 
            return notify_fail("�������������û�а취�����������\n"); 
    } 
	if(me->query_skill("tangforce",1)*2<me->query_skill("tang-blade",1)){
			return notify_fail("������е���⻹������\n");
    }
    if((string)me->query_skill_mapped("force")!= "tangforce"){ 
            return notify_fail("�������������������в�������\n");  
        } 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
    return 1; 
} 
 
 
  
int practice_skill(object me)
{
       return notify_fail("�������������ֻ����ѧ�ġ�\n");
}        