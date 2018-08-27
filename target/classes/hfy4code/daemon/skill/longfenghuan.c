 // longfenghuan.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "����˫��");
        set("usage/hammer", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 200);
        set("practice_bonus", -5);
        set("black_white_ness", 0);
        set("skill_class", "assassin");
        set("parry_msg",  ({
        "���$n�����е�$v����$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        }) );
        
        action = ({
        ([      "action":               
"$N���Ž𼦶���������չ������˫��������ʽ���������硹������$w����$n�ĵ��",
                "force":               500,
                "dodge":                500,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������������¡¡������һ�С��������ˡ�����$n$l��",
                "force":               600,
                "dodge":                600,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���һ�ӣ�ʹ������˫���еġ����ɷ��衹����$n$l��",
                "force":               500,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��������졹��$w�����ŷ���ײ��$n$l��",
                "force":               800,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 50 ){
                return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 300 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "blade")
    if(victim->query_skill_mapped("blade") == "bat-blade" )
    if(me->query_skill("hammer") > victim->query_skill("blade")) {
    switch(random(3)) {
        case 0:
                message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                break;
        case 1:
                message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                break;
        case 2:
                message_vision(HIR "\n�򵶴���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                break;
                }
    return random(me->query_skill("hammer")) * 4;
    }
    return 0; 
} 
int practice_skill(object me)
{
        if (me->query_skill("longfenghuan",1) > 100)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");       
        if ((int)me->query("force") < 20) {
                return notify_fail("�������������ϰ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}   

void skill_improved(object me)
{
    int s;
    s = me->query_skill("longfenghuan",1);
    if (s== 150 && me->query("class")=="assassin") {
       tell_object(me,HIW "�������˫�����˽�����һ����Ծ��\n"NOR);
       } 
    if (s== 180 && me->query("class")=="assassin") {
       tell_object(me,HIW "�������˫�����˽�����һ����Ծ��\n"NOR);
       } 
    if (s== 210 && me->query("class")=="assassin") {
       tell_object(me,HIW "��ϲ�㣬�������˫���Ѿ��Ƿ��켫�ˣ�\n"NOR);
       }
    if (s== 200 && me->query("class")=="assassin") {
       tell_object(me,HIW "���Ȼ���ã�������Լ��ټ���������ȥ�Ļ���\n"NOR);
       tell_object(me,HIW "���ܹ��������Ե�����˫���ľ��裡\n"NOR);
       } 
}      
