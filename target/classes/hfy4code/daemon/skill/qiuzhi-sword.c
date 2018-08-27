 // qiuzhi-sword.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "�֦��ʽ");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("practice_limit",120);
        set("skill_class", "mei");
        set("effective_level", 220);
        set("learn_bonus", -500);
        set("practice_bonus", 10);
        set("black_white_ness", 20);
        set("unarmed_parry_msg",({
                "$n����$vһȦ��һ�С���÷����պ÷�ס$N�Ĺ��ơ�\n",
                "$nһ�С�է��÷�ࡱ���е�$v����$N�ؾ�֮����\n", 
                "$n���е�$vһ�������һƬ������һ�С�÷�ֻ��䡱��$Nȫ��Χס��\n",
                                        })      
        );
        action = ({
        ([      "action":               
"$N����$wһȦ��Ȼ����Ȼ����$n��$l�����ǡ��֦��ʽ���еġ���÷���",
                "dodge":                140,
				"parry":                140,
                "damage":               240,
                "force":                240,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ��������$wͻ��һ̽������ȴ��б�Ӷ��ϣ�����һ֦÷��էȻ�����
����$n��$l�����Ǿ�ѧ����÷���桱",
                "dodge":                142,
				"parry":                142,
                "damage":               250,
                "force":                250,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ɿ�ıȳ���ʽ��ȴ���֦�����е�����ɱ�֣�ֻ��$N������٣�һ��֮�£�
˫������һ��һѹ������$w����$n�����ǡ�է��÷�ࡱ����ʽ��",
                "dodge":                130,
				"parry":                130,
                "damage":               230,
                "force":                230,
                "damage_type":  "����"
        ]),
        ([      "action":               
"���ƽ�����$N$w͸��������һ�����糤�߳���������$n$l�����ǡ��֦��������
�����ѧ��÷ռ�ȴ���",
                "dodge":                137,
				"parry":                137,
                "damage":               340,
                "force":                340,
                "damage_type":  "����"
        ]), 
               
        });
}
int valid_learn(object me)
{
    if((int)me->query("max_force") < 200 ) {
            return notify_fail("�������������û�а취���֦��ʽ��\n");
        }
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
}   


void skill_improved(object me)
{
    int s;
    s = me->query_skill("qiuzhi-sword", 1);
    if (s== 100) {
       tell_object(me,HIW "����֦��ʽ�����µ��˽⣡\n"NOR);
       } 
    if (s== 150 && me->query("class")=="mei") {
       tell_object(me,HIW "���ڶ��֦��ʽ�������˽⣬��ģۺ�÷��ݴﵽ���µľ��磡\n"NOR);
       me->set("once_menpai/mei",1);
       } 
}      
        
mixed hit_ob(object me,object victim)
{
	int dam;
	dam = me->query("max_sen");
	if (me->query_temp("hanmeiluo")) {
                victim->receive_wound("sen", dam/5 +  random(dam/10), me);
				return (HIY"���⻪��ɢ��ҫĿ�Ľ����Ѵ�����$n"HIY"Ҫ����\n"NOR);
	}
	else if( random(me->query_skill("qiuzhi-sword", 1)) > 30 ) {
                victim->receive_damage("sen", dam/10 +  random(dam/20), me);
				return (HIY"ҫĿ�Ľ���̵�$n"HIY"�������۾���\n"NOR);
	}
	else
       return (""); 
}      
