 // hanshan-sword.c
 
#include <ansi.h> 
 
inherit SKILL; 
void setup() { 
        set("name", "��ɽʮ��ʽ"); 
        set("usage/sword", 1); 
        set("usage/parry", 1); 
        set("effective_level", 220); 
        set("practice_bonus", -50);
        set("practice_limit",100);
        set("learn_bonus", -300);
        set("black_white_ness", 5);
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
        "$n���˷������������죬һ�С�"+NOR WHT"�ޱ�"+NOR"�������е�$v�ݺݿĿ���$N��$w��\n", 
                "$n�ؽ����أ�һ�С�"+NOR RED"���"+NOR"������ס��$N��$w��\n", 
                "$nһ�С�"+NOR MAG"����"+NOR"�������е�$v����ǧ�ٰѣ���ס��ȫ��\n", 
                "$n���е�$v�������£�������$N��$w�������Ρ�\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$nʹ��һ�С�"+NOR YEL"����"+NOR"��������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�\n", 
                "$nһ�����е�$v��ʹ��һ�С�"+NOR CYN"����"+NOR"�������е�$v��ס��ȫ��\n", 
                "$n��$v������һ�̣�$v�����������պ�ֱ��$N��˫�ۡ�\n", 
                "$n�ٽ�������һ�������ӽ���͸�����ƿ���$N��\n", 
        }) );    
        action = ({ 
                ([      "name":                 "Ⱥħ����", 
                        "action":               "$Nʹһ�С�"+HIW"����"+NOR"��������$w�����������$n��$l��������", 
                        "damage":               70, 
                        "parry" :		50, //by xiaolang
                        "dodge":		50, //by xiaolang
                        "force" :               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "name":                 "�������", 
                        "action":               "$N����һת��һ�С�"+HIC"����"+NOR"��$wն��$n��$l", 
                        "damage":               50, 
                        "parry" :		50,  //by xiaolang
                        "dodge":		50,  // by xiaolang
                        "force" :               100, 
                   "damage_type":  "����" 
                ]), 
                ([      "name":                 "�ٹ�ҹ��", 
                        "action":               "$N�趯$w��һ�С�"+HIM"����"+NOR"��Ю�������������$n��$l", 
//                        "parry" :               -50,  
			"parry":		50,     //by xiaolang
                        "dodge":		50,   //by xiaolang
                        "damage":               150, 
                        "force" :               250, 
                        "damage_type":  "����" 
                ]), 
                ([      "name":                 "������·", 
                        "action":               "$N����$wһ����ʹ����"+HIB"����"+NOR"����$n��$l�̳�һ��", 
                        "damage":               50, 
                        "parry" :		50,  //by xiaolang
                        "dodge":		50,  //by xiaolang
                        "force" :               150, 
                        "damage_type":  "����" 
                ]), 
                ([      "name":                 "��Ӱ����", 
                        "action":               "$N����$w���Ⱪ����һ�С�"+HIR"��Ӱ"+NOR"����$n$l��ȥ", 
//                        "dodge":                -30, 
//                        "parry" :               -30, 
			"parry" :		30,//by xiaolang
			"dodge":		30,// by xiaolang
                        "damage":               90, 
                        "force" :               220, 
                        "damage_type":  "����" 
                ]), 
                ([      "name":                 "��ع�", 
                        "action":               "$N����$wֱָ$n$l��һ�С�"+HIY"���"+NOR"���������˽�����ȥ", 
                        "damage":               50, 
                        "parry" :		50,   //by xiaolang
                        "dodge":		50,  // by xiaolang
                        "damage_type":  "����" 
                ]), 
        }); 
} 
 
int valid_learn(object me) 
{ 
        object ob; 
 
        if( (int)me->query_skill("sword",1) < 120 ) {
           return notify_fail("��Ի������������򲻹��\n"); 
        } 
        if(!::valid_learn(me)) { 
                return 0; 
        } 
        return 1; 
} 
 
int practice_skill(object me) 
{ 
        if (me->query_skill("hanshan-sword",1) > 100)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");   
        if((int)me->query("force") < 1000 ) { 
                return notify_fail("�������������û�а취��ϰ��ɽʮ��ʽ��\n"); 
        } 
        if(!::practice_skill(me)) { 
                return 0; 
        } 
        me->add("force", -10); 
        write("�㰴����ѧ����һ�麮ɽʮ��ʽ��\n"); 
        return 1; 
} 
 
   
