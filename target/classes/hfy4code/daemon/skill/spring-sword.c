 // spring-sword.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "���꽣��");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("practice_damage", 40);
        set("effective_level", 120);
        set("learn_bonus", 10);
        set("practice_bonus", -100);
        set("skill_class",              "new");
        set("black_white_ness", 20);
        set("parry_msg", ({
        "$nʹ��һ�С�����ͼ���𡹣������е�$v����$N����ָ��\n",
                "$n���̤ǰһ����һ�С����紵б���������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
                "$n���е�$vһ�������һƬ������һ�С�����Ϧ����������$N��ȫ��\n",
                "$n΢��һ�������е�$v����һ��Բ����һ�С����߲�֪�ء�����$N��ȫ��Χס��\n",
        }) ); 
        set("unarmed_parry_msg", ({
                "$nʹ��һ�С�����ͼ���𡹣������е�$v����$N����ָ��\n",
                "$n���̤ǰһ����һ�С����紵б���������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
                "$n���е�$vһ�������һƬ������һ�С�����Ϧ����������$N��ȫ��\n",
                "$n΢��һ�������е�$v����һ��Բ����һ�С����߲�֪�ء�����$N��ȫ��Χס��\n",
        }) );
        
        action = ({
                ([      "action":               "$Nʹһ�С����������������$w��ƮƮ����$n��$lնȥ��",
                        "damage":               100,
                        "dodge":                70,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�������磬$w����һ�С�Զɽ���˳ա����¶�������$n��$l",
                        "damage":               40,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����һת��һ�С��ɻ������㡹$w���ⲻ����ն��$n��$l",
                        "damage":               70,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�趯$w��һ�С���Ҷ����Ц��Ѹ�����׵�����$n��$l",
                        "damage_type":  "����"
           ]),
                ([      "action":               "$N����$wһ�Σ�һ�С�ٻӰ����������$n��$lбб�̳�һ��",
                        "damage":               20,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�ὣ���磬�������һ�С�«ѩ����Ӱ��ֱ��$n$l",
                        "damage":               60,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N�Ʋ�����ʹһ�С��ʵ������¡������������$n��$l",
                        "damage":               180,
                        "damage_type":  "����"
                ]),
        });
}      
int practice_skill(object me)
{
        return notify_fail("���꽣��ֻ����ѧ�ġ�\n");
}  

int effective_level()
{
        object me=this_player();
        
        if (me->query_temp("SUPERER") )return 500;
        else {return 120;}
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 100 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "blade")
    if((victim->query_skill_mapped("blade") == "springrain-blade" )||(victim->query_skill_mapped("blade") == "duanmen-blade" )||(victim->query_skill_mapped("blade") == "tang-blade" ))
    if(me->query_skill("sword")*3 > victim->query_skill("blade")*2) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n�򵶽���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("sword")) * 5;
    }
    return 0;
}  