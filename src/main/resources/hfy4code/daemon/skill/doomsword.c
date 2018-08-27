 // doomsword.c
#include <ansi.h> 
inherit SKILL;
void setup() {
        set("name", "���촵Ѫ����");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("effective_level", 270);
        set("learn_bonus", -500);
        set("practice_bonus", -50);
        set("black_white_ness", -10);
        set("skill_class", "fighter");
        set("parry_msg", ({
            "$n���˷������������죬һ�С������ޱߡ������е�$v�ݺݿĿ���$N��$w��\n",
            "$n�ؽ����أ�һ�С����Ʈ�㡹����ס��$N��$w��\n",
            "$nһ�С�Ⱥħ���衹�����е�$v����ǧ�ٰѣ���ס��ȫ��\n",
            "$n���е�$v�������£�������$N��$w�������Ρ�\n",
        }) ); 
        set("unarmed_parry_msg", ({
            "$nʹ��һ�С�����ħ�ϡ�������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�\n",
            "$nһ�����е�$v��ʹ��һ�С�����ħ�ݡ������е�$v��ס��ȫ��\n",
            "$n��$v������һ�̣�$v�����������պ�ֱ��$N��˫�ۡ�\n",
            "$n�ٽ�������һ�������ӽ���͸�����ƿ���$N��\n",
        }) );
        action = ({
    ([  "name":                 "Ⱥħ����",
     "action":          "$Nʹһ�С����Ƴ�ᶡ�������$w�����������$n��$l��������",
     "dodge":           200,
     "parry" :          200,
     "damage":          270,
     "force" :          200,
     "damage_type":     "����"
        ]),
    ([  "name":                 "�������",
     "action":          "$N����һת��һ�С���������$wն��$n��$l",
     "dodge":                200,
     "parry" :               200,
     "damage":               350,
     "force" :               100,
     "damage_type":     "����"
   ]),
    ([  "name":                 "�ٹ�ҹ��",
     "action":          "$N�趯$w��һ�С��׺���ա�Ю�������������$n��$l",
     "dodge":                200,
     "parry" :               300,
     "damage":               350,
     "force" :               250,
     "damage_type":     "����"
        ]),
    ([  "name":                 "������·",
     "action":          "$N����$wһ����ʹ����������ȡ���$n��$l�̳�һ��",
     "dodge":                100,
     "parry" :               100,
     "damage":               250,
     "force" :               150,
     "damage_type":     "����"
        ]),
    ([  "name":                 "��Ӱ����",
     "action":          "$N����$w���Ⱪ����һ�С���Ӱ��������$n$l��ȥ",
     "dodge":                250,
     "parry" :               250,
     "damage":               290,
     "force" :               220,
     "damage_type":     "����"
        ]),
    ([  "name":                 "��ع�",
     "action":          "$N����$wֱָ$n$l��һ�С���ع����������˽�����ȥ",
     "dodge":           200,
     "parry" :          100,
     "damage":          150,
     "damage_type":     "����"
        ]),
        });
}  
int practice_skill(object me)
{
        return notify_fail("���촵Ѫ����ֻ��ѧ�ġ�\n");
} 

int effective_level()
{
        object me=this_player();
        int skill,n;
        //n=(skill-200)/5*10+60;
        skill=me->query_skill("doomsword",1);
        if (skill < 160) return 270;
        if (skill > 160) return 300;
        
        
        
        
        
        
        
}  

mixed hit_ob(object me, object victim, int damage_bonus)
{
           object ob;
        if( random(damage_bonus) < 100 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "sword")
        if(victim->query_skill_mapped("sword") == "feixian-sword")
                if(me->query_skill("sword") > victim->query_skill("sword"))
                {
                    switch(random(3)) {
                    case 0:
                        message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                        break;
                    case 1:
                        message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                        break;
                    case 2:
                        message_vision(HIR "\n�򽣷���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                        break;
                    }
                return random(me->query_skill("sword")) * 4;
                }
    return 0;
}  
int valid_learn(object me)
{
        object ob;
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if ((int)me->query("max_force") < 500) {
                return notify_fail("�������������\n");
        }
        return 1;
}    
  