 // mantian-huayu.c
#include <ansi.h>
inherit SKILL; 
void setup(){ 
        set("name", "���컨��"); 
        set("usage/throwing", 1); 
        set("skill_class", "tang"); 
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
        ([      "action":                
"$N�����������������ָ���$w˲�䲻����Ӱ��ȴ�ֺ�Ȼ����һ�Ƕ�����Ϯ��$n��$l", 
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
    if( (int)me->query_skill("dujing-force") < 100 ){ 
        return notify_fail("��Ķ����ķ�������û�а취�������컨�ꡣ\n"); 
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
        write("�㰴����ѧ����һ�����컨�ꡣ\n"); 
    return 1; 
} 
mixed hit_ob(object me,object victim)
{
	int dam;
	dam = me->query("max_sen");
	if (me->query_temp("SUPERER")) {
                victim->receive_wound("gin", dam/2 +  random(dam/5), me);
				return (HIR"����ɢ����һ�����㣬��Ȼ�����������涾�׶��죡\n"NOR);
	}
	else if( random(me->query_skill("dujing-force", 1)) > 200 ) {
                victim->receive_damage("sen", dam/10 +  random(dam/20), me);
				return (HIB"������һ���ȳ�����Ȼ�����˾綾��\n"NOR);
	}
	else
       return (""); 
}   
