 inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name",                     "���溮����");
        set("learn_bonus",              10);
        set("practice_bonus",           0);
        set("black_white_ness",         -10);
        set("effective_level",          150);
        set("usage/unarmed",            1);
        set("skill_class",              "assassin");
        
        set("parry_msg",                        ({
                        "$n����Ϊ����һ�С����Ͻ��͡�����$N����$w���֡�\n",
                        "$n˫�ƽ���ʹ��һ�С����ȴ���������ž����һ����$N��$w����˫��֮�䡣\n",
                        "$n��һת��һ�С���ˮ�ɱ�������$N����$w���֡�\n",
                        "$nʹ�����ס��־���˫��һ������ƫ��$N��$w��\n",
                })
        );
        set("unarmed_parry_msg",        ({
                        "$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
                        "$n����Ϊָ��һ�С��ƻ�ǻ𡹷���$N������ҪѨ��\n",
                        "$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
                })
        );
        
        action = ({
                        ([      "action":               
                        "$Nʹ��һ�С�����ȡ����������һ����������󴩳�����$n��$l",
                                "dodge":                130,
                                "parry":                100,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ��һ�С������ݱ���������������Σ�����Ϊʵ����$n��$l",
                                "dodge":                100,
                                "parry":                230,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ�������ɵ�ɽ��������Ȱ�����$n��ǰ��һ������$n��$l",
                           "dodge":                130,
                                "parry":                210,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N˫��һ�������б��¡���һ�ɼ��������Ĺ�������$n��$l",
                                "dodge":                220,
                                "parry":                230,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����Ǻ��⡹����$n$l",
                                "dodge":                120,
                                "parry":                130,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ�������ǵ�㡹������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                                "dodge":                170,
                                "parry":                110,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N����������һ�С���������졹˫�Ʋ����Ƴ�",
                                "dodge":                170,
                                "parry":                240,
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)){
                return 0;
        }
        if((int)me->query_skill("jingxing", 1)+30 < (int)me->query_skill("flame-strike", 1) ) {
                return notify_fail("��ľ����ķ�����㣬�޷������溮���ơ�\n");
        }
        if((int)me->query("max_force") < 100 ) {
                return notify_fail("�������̫�����޷������溮���ơ�\n");
        }
   return 1;
} 
int practice_skill(object me) {
        if((int)me->query("force") < 5 ) {
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int my_exp, your_exp, damage, lvl, bonus;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        lvl= me->query_skill("flame-strike",1);
        
        damage = lvl;
        bonus = (my_exp-4000000)/500000*damage; 
        if (bonus>3*lvl) bonus=3*lvl;
        if (bonus>0) damage=damage+bonus;        
        if (me->query("class")!="assassin") damage= damage/3;
                victim->receive_wound("kee",damage+random(damage),me);
                if (random(2)==1) return HIR "$N�����˳�һ���ɺ�����棬�ǿ���$n��ȫ��\n" NOR;
                else    return HIW "$N����͸��˿˿����,$n�����ߡ�\n" NOR;
}  
int effective_level()
{
        if(this_player()->query("combat_exp")<5000000)  return 150;
                else if(this_player()->query("combat_exp")<5700000 
                        || this_player()->query("class")!="assassin")   return 160;
                else if(this_player()->query("combat_exp")<6400000 )    return 180;
                else return 200;
}     
