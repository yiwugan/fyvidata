 // modified by mimicat@fy4
#include <ansi.h>        
inherit SKILL;
void setup(){
        set("name", "ѩӰ����");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("effective_level", 170);
        set("learn_bonus", 30);
//      set("black_white_ness", 0);
//      set("practice_bonus", 0);
        set("skill_class", "taoist");
        
        set("parry_msg", ({
        "$n�������ϣ��ԡ�����һ���㡱����$N��$w��\n",
        "���$n�����е�$v����$N��$w��\n",
        "$n����һ����$v�����ƶϷ塱бɨ������\n",
        "$n���˷������������У��������ˣ�$vֱ�̣�����$N�ҽš�\n",
        "$n�Ҽ��������ʺ羭�족��$v���ã�������$N�Ĺ��ơ�\n",
        "$n�������������Ƕ�ء���ֱ�����µ��ܡ�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ����$v�����ƶϷ塱бɨ������\n",
        "$n���˷������������У��������ˣ�$vֱ�̣�����$N�ҽš�\n",
        "$n�Ҽ��������ʺ羭�족��$v���ã�������$N�Ĺ��ơ�\n",
        "$n�������������Ƕ�ء���ֱ�����µ��ܡ�\n",
        }) );
        action = ({
                ([      "action":               "$Nʹһ�С��ع�õ硹������$w��һ���������$n��$l",
                        "dodge":                20,
                        "damage":               130,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$Nʹ��ѩӰ�����еġ���˪��Ӱ����$w���ӽ������ն��$n��$l",
                        "dodge":                20,
                        "damage":               130,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$Nһ�С�������ѩ��������Ʈ�����ߣ�����$wն��$n��$l",
                   "dodge":                30,
                        "damage":               120,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����$w�й�ֱ����һʽ�����ȳ��硹��׼$n��$l�̳�һ��",
                        "dodge":                40,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����һԾ������$wһ�С�������������׼$n��$lбб�̳�һ��",
                        "dodge":                40,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N��$wƾ��һָ��һ�С���ʯ���̡�����$n��$l",
                        "dodge":                60,
                        "damage":               140,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_force") < 50 ){
                return notify_fail("�������������û�а취��ѩӰ������\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ){
                return notify_fail("�����������������û�а취��ϰѩӰ������\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        write("�㰴����ѧ����һ��ѩӰ������\n");
   return 1;
}  
mixed hit_ob(object me, object victim)
{
        object weapon;
        string result;
        int extra;
         
        weapon=me->query_temp("weapon");
        extra=weapon->query("exorcising");
        if(!extra)
                return ;
        result=HIR"��ֽ�ϵ�Ѫɫ�ƺ��ּ�����һ�֡�����\n";
        if(victim->is_ghost())
        {       victim->set("eff_sen",-100);
                result+=HIR+victim->name()+HIR"�����Ĳҽ���һ������Ϊ�˻ҽ���\n"NOR;
        }
        else if(victim->is_zombie())
        {
                victim->set("eff_sen",-100);
                result+=HIR+victim->name()+HIR"�����Ĳҽ���һ������Ϊ��һ̲Ѫˮ��\n"NOR;
        }
        else
        {
                victim->receive_wound("sen",extra,me);
                victim->add("sen",-extra);
                result+=HIY+victim->name()+HIY"���������׻�����Ϊ֮�ᡣ\n"NOR;
        }
        return result;
}
                
int undodgeable()
{
        return this_player()->query("no_dodge_snow");
}  
