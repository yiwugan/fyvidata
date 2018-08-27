 // springrain-sword
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "���굶��");
        set("usage/blade", 1);
        set("usage/parry", 1);
        set("effective_level", 230);
        set("learn_bonus",      -500);
        set("practice_bonus",   -100);
        set("black_white_ness", 10);
        set("skill_class", "new");
        set("parry_msg", ({
        "$n�������裬һʽ"HIG"������������ŪӰ��"NOR"�ó����쵶�⣬�·�����ˮ�㽫$N������ʽ
�������Ρ�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n����һ�䣬��Ȼ��̾һ��"HIC"������ɴ���׷�䡹"NOR"��$N���𲻿����£����ɵس��ˡ�\n",
        }) );   
        action = ({
                ([      "action":               "$N��������"HIG"���������ϣ��磭�����ꡪ����"NOR"��$w�����������ϵĴ��꣬�ӳ���һ������ϸ������$n��",
                        "force":                70,
                        "dodge":                30,
                        "parry":                30,
                        "damage" :              50,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�ٷ����������֮��"HIC"����ҹ���磭��̣�����"NOR"���·���������$w���ǵ�����$n��$l��",
                        "force":                90,
                        "dodge":                50,
                        "parry":                40,
                        "damage" :              100,
                        "damage_type":  "����"
                ]),
                ([      "action":               HIR"�������仨���죭�����꡹"NOR"�ĵͺ��У�$N��$w������ʮ�䵶��������һƬѤ����Ѫ��ӿ��$n��",
                        "force":                60,
                        "dodge":                50,
                        "parry":                40,
                        "damage" :              200,
                        "damage_type":  "����"
           ]),
                ([      "action":               "$N˫������Զ����һʽ"HIY"��������ʶ���࣭�飭����"NOR"�����β���˼�������һת��$w˳�ƻ�����һ���������»���",
                        "force":                80,
                        "dodge":                20,
                        "parry":                30,
                        "damage" :              150,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
	if(!::valid_learn(me)) {
                return 0;
        }
        if (!me->query("free_rain/ending"))
                return notify_fail("����ͷδ��Ӧ�������书��\n");
         return 1;
} 
int practice_skill(object me)
{
        return notify_fail("���굶��ֻ����ѧ�ġ�\n");
}    
