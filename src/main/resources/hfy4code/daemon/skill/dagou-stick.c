 // silencer@fy4.com
//�򹷰������а˾���
//��Lvl 60  pfm
//����normal attack
//����Lvl 180 auto
//����Lvl 20  pfm
//����Lvl 100 pfm
//����Lvl 80  pfm
//�⡢Lvl 140 auto
//ת  Lvl 160 auto
//�����޹� Lvl 120 
inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name", "�򹷰���");
        set("usage/staff", 1);
        set("usage/parry", 1);
        set("learn_bonus", -200);
        set("practice_bonus", -5);
        set("practice_limit",150);
        set("skill_class", "beggar");   
        set("effective_level", 210);
        set("parry_msg", ({
        "$nʹ�����������־���$n����һ�������͵�ϸ�٣�ճ��$N��$w�ϡ�\n",
        "$n���ܲ�����һ�С�˫�����项������$vֱȡ$N��˫Ŀ��\n",
        "$n$v����������$w������˳������ǣ����\n",
        "$n$v���أ�ʹ�������־�����ס$w����˦����\n",
                })
        );
        set("unarmed_parry_msg", ({
        "$n���$v��һ�С��������족����ס��$N�Ĺ��ơ�\n",
        "$n���ܲ�����һ�С�˫�����项������$vֱȡ$N��˫Ŀ��\n",
        "$n�ӳ�$v����ص���$N�����š�\n",
        })      
        );      
        action = ({
([      "action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
        "dodge": 10,
        "parry": 70,
        "damage": 90,
        "damage_type": "����"
]),
([      "action": "$N����$w���һζ���ٿȻ�й�ֱ��������$nǰ�ء��Ϲ�Ѩ��",
        "dodge": 20,
        "parry": 100,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$Nһ�С����־������ӱ����Լ�Ϊ֧��$w������£������쳣",
        "dodge": 20,
        "parry": 100,
        "damage": 320,
        "damage_type": "����"
]),
([      "action": "$Nһ����Х��Ʈ�����������$w���𣬻��������Ӱ����$n����ɨȥ",
        "dodge": 20,
        "parry": 50,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$Nʹ���򹷰����С�մ����������Ĩ�����衱��㷨��������Ҳ�����в���$n��Ҫ��",
        "dodge": 20,
        "parry": 270,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$N����$w��һ�С�����ͷ������$nͷ����ȥ�����ֺ���������Ѹ��",
        "dodge": 20,
        "parry": 110,
        "damage": 120,
        "damage_type": "����"
]),
([      "action": "$Nʹ�����������졹��$w����������$n��ȥ",
        "dodge": 120,
        "parry": 70,
        "damage": 180,
        "damage_type": "����"
]),
([      "action": "$Nʹ�������Ŵ򹷡�������$w������һ�ű�Ӱ���͵�$n���ĸ���ҪѨ",
        "dodge": 120,
        "parry": 300,
        "damage": 150,
        "damage_type": "����"
]),
        });
} 
int valid_learn(object me)
{
    if(!::valid_learn(me)) {
        return 0;
    }
    if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 ) {
        return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if( (int)me->query("kee") < 10 ) 
                return notify_fail("����������������Ź�������������Ϣ��Ϣ�ɡ�\n");
        
        if(!::practice_skill(me)) return 0;
        me->add("force",-5);
        return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob,weapon;
        int myexp,urexp;
            
        myexp=me->query("combat_exp");
        urexp=victim->query("combat_exp")*victim->query("cps")/20;
        weapon=me->query_temp("weapon"); 
        if (!victim->is_busy())
        if (random(myexp+urexp)>urexp && me->query_skill("dagou-stick",1)>=180
                &&!me->query_temp("dagou/pfm") && me->query("class")=="beggar"
                && me->query_skill_mapped("force") == "huntunforce"){
                if (victim->query_busy()<2) victim->start_busy(2);
                message_vision(HIW "\n$Nʹ��[���־�]������"+weapon->name()+HIW"����һ�������͵�ϸ�٣���ס��$n��\n"NOR,me,victim);
         }   
           
         if(random(damage_bonus) < 250 ) return 0;
         if(ob=victim->query_temp("weapon"))
         if(ob->query("skill_type") == "whip")
         if(victim->query_skill_mapped("whip") == "thunderwhip")
                if(me->query_skill("staff") > victim->query_skill("whip")) {
                switch(random(3)) {
                    case 0:
                            message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                            break;
                    case 1:
                            message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                            break;
                    case 2:
                            message_vision(HIR "\n����޷���ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                            break;
                            }
            return random(me->query_skill("staff")) * 3;
         }
         return 0;
}  
mixed parry_ob(object victim, object me)        {       
        
        int skill, my_exp, your_exp;
        string msg;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        skill = me->query_skill("dagou-stick",1);
        
        if (!me->query_temp("dagou/feng") && me->query_skill("dagou-stick",1)>=140
                && me->query("class")=="beggar") {
                msg=CYN"\n$N"+CYN"ʹ���򹷰����еġ����־��������������Ӱ����ʱ���Լ���ǰ����֮�ؾ�����ס��\n"NOR;
                message_vision(msg,me);
                me->set_temp("dagou/feng",1);
                me->add_temp("apply/parry",skill/5);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5:), 10);
                return;
        } 
        if (victim->query("race")=="Ұ��") return 0; 
   if (4*random(my_exp)>your_exp && me->query_skill("dagou-stick",1)>=160
                && me->query("class")=="beggar") {
                me->set_temp("counter_action",1);
                me->set_temp("counter_msg",HIY"$Nʹ���򹷰�����ת�־��������а������������\n"NOR);
                return 0;
        } 
}         
void remove_effect(object me, int amount)
{
        me->add_temp("apply/parry", -amount);
        me->delete_temp("dagou/feng");
        tell_object(me, "��ġ����־�����ת��ϡ�\n");
}    
