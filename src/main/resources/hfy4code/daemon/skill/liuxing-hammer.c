 // liuxing-hammer.c
inherit SKILL;
void setup() {
        set("name", "��ת���Ǵ���");
        set("usage/hammer", 1);
        set("usage/parry", 1);
//      set("effective_level", 150);
        set("learn_bonus", -500);
        set("practice_bonus", -5);
        set("black_white_ness", 10);
        set("skill_class", "shaolin");
        set("parry_msg", ({
        "$n����һ����һ�У۲�����������е�$v�͵�����$N��$w��\n",
                "$n����΢�٣����е�$vһ�У�ָ�������ݷ���$N�ıؾ�֮����\n",
                "$n���е�$v�������ϼ��ӣ�һ�У۷��鱾�ԣݿĿ���$N���е�$w\n",
        }) ); 
        set("unarmed_parry_msg", ({
                "$nһ�У�������ת�ݣ����е�$v��ƫ�����$N��̫����Ѩ��\n",
                "$n���е�$v�����ң�һ�У�������ƣݷ�ס��$N�Ĺ��ơ�\n",
                "$n�����������һ�У۽������֣����е�$v����$N�ĺ��ԣ��Ƶ�$N��;���С�\n",
        }) );   
        action = ({
        ([      "action":               
"$N����$w�ն���ɣ��������಻�ϣ�һ�У�������Ϣ�ݣ��������$n��к��ȥ��",
                "force":               70,
                "dodge":                100,
                "parry":                100,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ɣ���Ӱ�������֣�һ�У��������֣ݣ����е�$wȴ�絽$n����ǰ��",
                "damage":               70,
                "dodge":                20,
                "parry":                60,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�趯��һ�У��׶������Ю�������ײ��֮��������$n��$l��", 
                "damage":               70,
                "force" :               200,
                "dodge":                100,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���е�$wһת��һ�У��������Уݴ�����˷�����$n��$l",
                "damage":               40,
                "force" :               200,
                "dodge":                10,
                "parry":                40,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ�����е�$w��һ�У��ҷ���գݴ�Ӱ������裬����ʵʵ�Ļ���$n��$l",
                "force":               100,
                "damage" :              50,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 35 ){
                return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 10) {
                return notify_fail("�������������ϰ��\n");
        }
   if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
}  
int effective_level()
{
        object me=this_player();
        int skill,n;
        if (me) {
                skill=me->query_skill("liuxing-hammer",1);
                if (skill<=150) return 150;
                if (skill>=170) return 200;
                
                n=(skill-150)/4*10+150;
                return n;
        }
        return 200;
}
