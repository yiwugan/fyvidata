 // changquan.c
inherit SKILL; 
void setup() {
        set("name",                                     "���ֳ�ȭ");
        set("effective_level",          60);
        set("practice_limit",250);
        set("usage/unarmed",            1);
        set("skill_class",                      "official");
        set("parry_msg",                        ({
                        "$n����Ϊ����һ�С�����Ϊ�������ͻ�$N��$w������\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
                        })
        );
        action = ({
                        ([      "action":               "$Nʹһ�С��ڻ����ġ�����׼$n��$l��������һȭ",
                                "force":                80,
                                "parry":                60,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����ȭͷ��һ�С�̩ɽѹ��������$n��$l�к���ȥ",
                                "force":                60,
                                "parry":                30,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N������Σ���ȭ���й�ֱ��������$n��$l����",
                                "force":                60,
                                "parry":                30,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����һ������ȭ��������ȭʹ�����Ϻ��Ƴ�������$n$l",
                                "force":                60,
                                "parry":                80,
                                "damage_type":  "����"
                        ]),
        });
} 

int effective_level()
{
        object me=this_player();
        int skill,n;
        //n=(skill-200)/5*10+60;
        skill=me->query_skill("changquan",1);
        if (skill < 200) return 60;
        if (skill >= 300) return 220;
        if (skill >=280) return 200;
        if (skill >=260) return 180;
        if (skill >=240) return 150;
        if (skill >=220) return 120;
        if (skill >=200) return 90;
        if ((me->query("once_xman"))==1 )return 300;
        
        
        
        
        
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 100 ) return 0;
        badint = victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth")*2;
        if (victim->query_skill_mapped("iron-cloth") == "xuanxinjue"
         
                ) {
                if(badint) {
                        victim->receive_wound("kee",badint);
                        switch(random(3)) {
                                case 0: return "$N���һ����ȫ����������$n��ǽ������˫����ȥ��\n";
                                case 1: return "$N�������������������������뷢��$n��$l������������һ�����죡\n";
                                case 2: return "ֻ����$n��$l��������һ�� ������\n";
                                }
                }
        }
}  