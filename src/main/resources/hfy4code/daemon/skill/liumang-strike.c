 // ice liumang-strike.c 
inherit SKILL; 
void setup() { 
        set("name", "��å��ȭ"); 
        set("usage/unarmed", 1); 
        set("effective_level", 100);
        set("practice_limit",200);
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
        "$nһʽ���һ�׶����˫�������»���ȭ�����棬����$N��$w��\n", 
                "$n�ڿշ���һʽ���˷��꡹��˫��˫�������������$N��$w��\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
                "$n���ⶪ��������һ�С���ˮ���ۡ���˫ȭ������$N֮�ؾȡ�\n", 
                "$nһ�С�������ѩ����ȫȻ����$N�Ĺ�����˫��ֱ��$N��ȥ���Ƶ�$N�����Ա���\n", 
        }) ); 
 
        action = ({ 
        ([      "action":                
"$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l��", 
                "damage":               60, 
                "dodge":                40, 
                "parry":                50, 
 
                "damage_type":  "����" 
        ]),  
        ([      "action":                
"$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l��", 
                "damage":               10, 
                "dodge":                80, 
                "parry":                100, 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N�������������֣�һ�С�������������ץ��$n��$l��", 
                "damage":               70, 
                "dodge":                90, 
                "parry":                70, 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N˫��Ю��һ���ȳ�֮������$n��$l��", 
                "damage":               50, 
                "dodge":                50, 
                "parry":                100, 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N������ɽ��һʽ�����������˫ȭ���ƶ���������$n��$l��", 
                "damage":               30, 
                "dodge":                20, 
                "parry":                70, 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N�������أ�����������һʽ��ľ�ѳ��ۡ���������$n�Ƴ���", 
                "damage":               40, 
                "dodge":                80, 
                "parry":                50,                                

                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N�������飬����������ޣ�һʽ��ˮ�����¡�����$n�޿ɶ���", 
                "damage":               20, 
                "dodge":                80, 
                "parry":                60, 
 
                "damage_type":  "����" 
        ]), 
        }); 
} 
int valid_learn(object me) 
{ 
        if(!::valid_learn(me)) { 
                return 0; 
        } 
    if ((int)me->query_skill("wuchenforce", 1) < 50){ 
                return notify_fail("����޳��ķ���򲻹����޷�����å��ȭ��\n"); 
        }        
    if((int)me->query("str") + (int)me->query("max_force") / 100 < 35 ) { 
        return notify_fail("���������������Ҳ�����һ����������ǿ������\n"); 
        } 
    return 1; 
} 

        
