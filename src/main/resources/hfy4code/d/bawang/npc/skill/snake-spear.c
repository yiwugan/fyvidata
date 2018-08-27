 //@maomaomao
inherit SKILL; 
mapping *action = ({ 
        ([      "action":                
"$Nʹһ�С���ʹ�����á�������$wһ��������������ͷ��ֱ��$n��$l", 
                "dodge":                620, 
                "parry":                500, 
                "force" :               100, 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$Nʹ���ϻ�ǹ�еġ�����΢���ӡ�������$w��ͣ����������$n��$l", 
                "dodge":                620, 
                "parry":                600, 
                "force":               200, 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$Nһ�С����粻��ʶ��������$w��šһǹ������$n��$l", 
                "dodge":                630, 
                "parry":                400, 
                "force":               50, 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N����$wһʽ��������������������$w���϶��£��ͻ�$n��$l", 
                "force":                90, 
                "dodge":                230, 
                "parry":                400, 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N����š��������$w��㣬һ�С�������˿������$n��$l", 
                "dodge":                200, 
                "parry":                300, 
                "force":               300, 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N����$w���Ī�⣬һ�С��þɰ�Ϊ�����ֶ�׼$n$lһǹ��ȥ", 
                "dodge":                260, 
                "parry":                330, 
                "force":               100, 
                "damage_type":  "����" 
        ]), 
}); 
 
int valid_learn(object me) 
{ 
        object ob; 
 
        if( (int)me->query("max_force") < 100 ) 
                return notify_fail("�������������û�а취���ߴ̡�\n"); 
 
        if( !(ob = me->query_temp("weapon")) 
        ||      (string)ob->query("skill_type") != "spear" ) 
                return notify_fail("���������һ��ǹ������ǹ����\n"); 
 
        return 1; 
} 
 
int valid_enable(string usage) 
{ 
        return usage=="spear" || usage=="parry"; 
} 
 
mapping query_action(object me, object weapon) 
{ 
        return action[random(sizeof(action))]; 
} 
 
int practice_skill(object me) 
{ 
        if( (int)me->query("kee") < 30 
        ||      (int)me->query("force") < 3 ) 
                return  
notify_fail("�����������������û�а취��ϰ�ߴ̡�\n"); 
        me->receive_damage("kee", 30); 
        me->add("force", -3); 
        write("�㰴����ѧ����һ���ߴ̡�\n"); 
        return 1; 
} 
 
string perform_action_file(string action) 
{ 
        return CLASS_D("bw") + "/snake-spear/" + action; 
} 
  
int effective_level() { return 10;} 
 
string *parry_msg = ({ 
        "$nʹ��һ�С�������ãã�������е�$v������$N��$w��\n", 
        "$nʹ��������������������$N��$w�������⡣\n", 
        "$nʹ��һ�С���ɽȪˮ�ǡ������е�$v����������ˮ��������$N��$w��\n", 
         
}); 
 
string *unarmed_parry_msg = ({ 
        "$n�����е�$v����ܲ�͸�磬һ�С���黴��С���ס��$N�Ĺ��ơ�\n", 
        "$nʹ��һ�С������С���$vֱ��$N��˫�֡�\n", 
        "$n�����е�$vһ����һ�С����Ŀճۡ����ȵ�$N�������ˡ�\n", 
}); 
 
string query_parry_msg(object weapon) 
{ 
        if( weapon ) 
                return parry_msg[random(sizeof(parry_msg))]; 
        else 
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))]; 
} 
 
int learn_bonus() 
{ 
        return -10; 
} 
int practice_bonus() 
{ 
        return -10; 
} 
int black_white_ness() 
{ 
        return 20; 
} 
        
