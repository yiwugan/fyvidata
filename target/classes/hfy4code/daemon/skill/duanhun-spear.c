 //TIE@FY3
inherit SKILL;
void setup() {
        set("name", "�ϻ�ǹ");
        set("usage/spear", 1);
        set("usage/parry", 1);
        set("skill_class", "shaolin");
        set("learn_bonus", -300);
        set("practice_bonus", 0);
        set("practice_limit",160);
//      set("effective_level", 150);
        set("black_white_ness", 20);
        set("parry_msg", ({
        "$nʹ��һ�С��������ơ������е�$v������$N��$w��\n",
        "$nʹ��������˵�Ρ�����$N��$w�������⡣\n",
        "$nʹ��һ�С�̤�����ġ������е�$v����������գ�������$N��$w��\n",
        "$n���е�$vһ����һ�С�������;������$N��$w�������ȥ��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬һ�С���黴��С���ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��Ƹ����ࡹ����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С������С���$vֱ��$N��˫�֡�\n",
        "$n�����е�$vһ����һ�С����Ŀճۡ����ȵ�$N�������ˡ�\n",
        }) );
        action = ({
                ([      "action":               
                        "$Nʹһ�С�������Ρ�������$wһ������������ǹͷ��ֱ��$n��$l",
                        "dodge":                520,
                        "parry":                300,
                        "force" :               100,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                        "$Nʹ���ϻ�ǹ�еġ�ִ��Ϊ�桹������$w�ζ��������ǹ��ͻȻ��Ӱ�з���һǹ������$n��$l",
                        "dodge":                520,
                        "parry":                300,
                        "force":               200,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                   "$Nһ�С���Գ��Ρ�����ǰ�ʹܣ�����$w����һǹ��ֱ��$n��$l",
                        "dodge":                530,
                        "parry":                200,
                        "force":               50,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                        "$N����$wһʽ������֪�Ρ�������$wǹͷ�Ҷ�������ǵ�ɱ����ǹǹ����$n��$l",
                        "force":                90,
                        "dodge":                230,
                        "parry":                400,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                        "$N��$w��㣬��ؽ�������һ�С������ۡ�����$n��$l",
                        "dodge":                200,
                        "parry":                300,
                        "force":               300,
                        "damage_type":  "����"
                ]),
                ([      "action":               
                        "$N����$wһ�ݣ�ǹ������°���ת����һ�С�һ��ع⡹���ֶ�׼$n$lһǹ��ȥ",
                        "dodge":                260,
                        "parry":                330,
                        "force":               100,
                        "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
    object ob;
        
        if( (int)me->query("max_force") < 100 ){
                return notify_fail("�������������û�а취���ϻ�ǹ��\n");
        }
        if(!::valid_learn(me)) {
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ) {
        return notify_fail("�����������������û�а취��ϰ�ϻ�ǹ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        write("�㰴����ѧ����һ��ϻ�ǹ��\n");
        return 1;
}  
int effective_level()
{
        object me=this_player();
        int skill,n;
        
        if (me) {
                skill=me->query_skill("duanhun-spear",1);
                if (skill<=160) return 150;
                if (skill>=180) return 200;
                
                n=(skill-160)/4*10+150;
                return n;
        }
        return 200;
}       
