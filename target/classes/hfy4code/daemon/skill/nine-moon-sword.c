 // nine-moon-sword.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "������������");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("skill_class", "shenshui");
        set("effective_level", 120);
        set("learn_bonus", 0);
        set("practice_bonus", 10);
        set("black_white_ness", -10);
        set("parry_msg", ({
        "$nʹ�������������С������𡹣���$N���е�$w��ƫ�˳�ȥ��\n",
                "$n̤��λ�������ţ����е�$v����һ�ã���ס��$N���е�$w��\n",
                "$n��$N����һ�������е�$v˳��$N��$w���£�����$N��$w����ָ��\n",
                "$n���е�$vһ����һ�С��Ŷ��������$v�ó�������Ӱ����ס��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n��͸���⣬һ�С�����̹ǡ���ǿ���Ľ���ֱȡ$N���ʺ�\n",
                "$n����һ����$v��һ��������ֱ��$N������\n",
                "$n�ҽź�̤һ����$v�����֣�������$N�鰴��һ�ɾ���ʹ$Ņ�����֡�\n",
                "$nת��$vͻȻ��Ҹ�´̳���һ�С�ɳ�س�Ы��������$N������$N��æ�����Ա���\n",
        }) );   
        action = ({
                ([      "name":                 "���겻ɢ",
                        "action":               "$Nʹһ�С����겻ɢ��������$w���Ⱪ������$n��$l��ȥ",
                        "dodge":                50,
                         "parry":                240,
                        "force":                170,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "����ɭɭ",
                        "action":               "$N������ת��һ�С�����ɭɭ������$n��$l",
                        "dodge":                70,
                         "parry":                180,
                        "force":                200,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "���Ƶ���",
                   "action":               "$N�趯$w��һ�С����Ƶ���Ю�������������$n��$l",
                        "dodge":                40,
                         "parry":                150,
                        "damage":               90,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "���ܵظ�",
                        "action":               "$N����$w����һ�������������ܵظ�����$n��$l�̳�����",
                        "dodge":                40,
                         "parry":                160,
                        "damage":               40,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��������",
                        "action":               "$N����$w���Ⱪ����һ�С��������ǡ���$n$l��ȥ",
                        "dodge":                60,
                         "parry":                150,
                        "damage":               120,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��������",
                        "action":               "$N����$w����һ���⻡��ֱָ$n$l��һ�С��������¡���������������ȥ",
                        "dodge":                60,
                         "parry":                140,
                        "damage":               150,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{ 
        if( (int)me->query("max_force") < 50 ){
                return notify_fail("�������������û�а취����������������\n");
        }
        if( (string)me->query_skill_mapped("force")!= "nine-moon-force"){
        return notify_fail("������������������Ͼ����ľ���������\n");
        }
        if (me->query_skill("nine-moon-sword",1)>= 2*me->query_skill("nine-moon-force",1)){
                        return notify_fail("��ľ����ľ���򲻹���\n");
        }               
   if(!::valid_learn(me)){
                return 0;
        }
        if (me->query("combat_exp")<1000000 && me->query_skill("nine-moon-sword",1)>150){
                tell_object(me,"���ʵս����̫��,�޷���һ�����Ծ�������������\n");
                return 0;
        }
        if (me->query("combat_exp")<1500000 && me->query_skill("nine-moon-sword",1)>160){
                tell_object(me,"���ʵս����̫��,�޷���һ�����Ծ�������������\n");
                return 0;
        }
        if (me->query("combat_exp")<2000000 && me->query_skill("nine-moon-sword",1)>170){
                tell_object(me,"���ʵս����̫��,�޷���һ�����Ծ�������������\n");
                return 0;
        }
        if (me->query("combat_exp")<2500000 && me->query_skill("nine-moon-sword",1)>180){
                tell_object(me,"���ʵս����̫��,�޷���һ�����Ծ�������������\n");
                return 0;
        }       
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ){
                return notify_fail("�������������û�а취��ϰ������������\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        write("�㰴����ѧ����һ���������������\n");
        return 1;
} 
mixed parry_ob(object victim,object me)
{
        int mylvl,extra ;
        string msg;
        mylvl=me->query_skill("nine-moon-force",1);
        if (extra=me->query_temp("nine-moon-force_poison"))
        {
           victim->receive_wound("kee",extra/3,me);
                victim->receive_damage("kee",extra/3*2,me);
                if (!victim->query_temp("weapon"))      return MAG"$Nֻ�����ִ�����һ������������׶�Ķ�����\n"NOR;
                        else return MAG"$Nֻ��һ�㵭���������ӱ��������Ӷ������̹ǵĺ�������������ת�����顣\n"NOR;
                
                return msg;
        }
}
