 inherit SKILL;
//original design by mimicat
#include <ansi.h>
int check_skill(object victim) ;  
void setup() {
        set("name",             "��Ϭָ");
        set("effective_level",  200);
        set("learn_bonus",      -800);
        set("practice_bonus",   -100);
        set("black_white_ness", 0);
        set("skill_class",      "task_npc");
        set("usage/unarmed",    1);
        
        set("parry_msg",                        ({
        "$n������$N������������һ����$Nֻ��һ�飬����Ҳʹ������������\n",
                "$n������$N������������һ����$Nֻ��һ�飬����Ҳʹ������������\n"
        })      );
        set("unarmed_parry_msg",                ({
         "$n������$N������������һ����$Nֻ��һ�飬����Ҳʹ������������\n",
                "$n������$N������������һ����$Nֻ��һ�飬����Ҳʹ������������\n"
        })      );
        action = ({
([      "action" : "$N��ָ�ӳ���һʽ����ҹ���硹������$n����Ե",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "��ҹ����",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��֮������һָ��һʽ���������项��ָ��$n����ǰ",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�����������Ѩ������һʽ��������֡�����$n��$l����",
        "force" : 180,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀŭ�ӣ�һʽ���������ġ���˫ָ����$n�Ķ�����硢�ۡ��ء���",
        "force" : 220,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���������ˡ��������������⣬��ָ���Ƶ���$n��$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N���������ʮָ�濪��һʽ�����߱��项��Сָ����$n��̫ԨѨ",
        "force" : 330,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "���߱���",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ų�������������һʽ���������ࡹ����$n��ȫ��",
        "force" : 400,
        "dodge" : 25,
        "damage": 120,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
}); 
} 
int valid_learn(object me)
{  
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����Ϭָ��������֡�\n");
        return 1;
}   
mixed parry_ob(object victim,object me)
{
        int myexp,hisexp,mylvl,extra, n;
        int alr_busy_time;
        object weapon;
        string msg;
        
        
        if (victim->query("race")=="Ұ��") return 0;
        if (victim->is_busy()) return 0;
        
        if (!check_skill(victim)) return 0; 
        myexp=me->query("combat_exp");
        hisexp=victim->query("combat_exp");
        myexp/=10000;
        hisexp/=10000;
        mylvl=me->query_skill("lingxi-zhi",1);
        hisexp*=180;
        myexp*=mylvl;
        if (me->query_temp("xinyoulingxi")||!userp(me))
        {
                if (victim->query_temp("weapon"))
                        msg=HIY"$n"+HIY"��Ȼ���ʳ����ָ����$N"+HIY"�ı��м�ס����\n"NOR;
                else 
                        msg=HIY"$n"+HIY"��Ȼ���ʳ����ָ����$N"+HIY"�ĳ��м�ס����\n"NOR;
                extra=mylvl/50;
                alr_busy_time=victim->query_busy();
                if(alr_busy_time<extra) victim->start_busy(extra);
                return msg;
        } 
        if (random(myexp+hisexp)>hisexp 
                && me->query_skill("lingxi-zhi",1)>100 && userp(me))
        {
                if (!random(2)) {
                        alr_busy_time=victim->query_busy();
                   if(!alr_busy_time) victim->start_busy(1);
                        return HIW"���$N��$n�ķ������˸���æ���ҡ�\n"NOR;
                }
        }
        
        if (random(3*myexp+hisexp)>hisexp && !userp(me))
        {
                alr_busy_time=victim->query_busy();
                if(!alr_busy_time) victim->start_busy(2);
                return HIW"���$N��$n�ķ�������һ����æ���ҡ�\n"NOR;
        }  
}  
int practice_skill(object me)
{
        return notify_fail("��Ϭָ��ֻ��ѧ�ġ�\n");
}  
int check_skill(object victim) {
        
        object weapon;
        
/*      if (weapon=victim->query_temp("weapon"))
        if (weapon->query("skill_type")=="sword" && victim->query_skill("taiji-sword",1)>100 && victim->query_skill("sword",1)>150
                && victim->query_skill_mapped("sword")=="taiji-sword")
                return 0;
        
        if (!weapon=victim->query_temp("weapon"))
        if (victim->query_skill("unarmed",1)>100 && victim->query_skill("eagle-claw",1)>100      
                && victim->query_skill_mapped("unarmed")=="eagle-claw")
                return 0;
                
        if (!weapon=victim->query_temp("weapon"))
        if (victim->query_skill("unarmed",1)>100 && victim->query_skill("qidaoforce",1)>100      
                && victim->query_skill_mapped("unarmed")=="qidaoforce")
                return 0;                 
        if (!weapon=victim->query_temp("weapon"))
        if (victim->query_skill("unarmed",1)>100 && victim->query_skill("dragonstrike",1)>100    
                && victim->query_skill_mapped("unarmed")=="dragonstrike")
                return 0;
        
        if (!weapon=victim->query_temp("weapon"))
   if (victim->query_skill("unarmed",1)>100 && victim->query_skill("zhaixin-claw",1)>100        
                && victim->query_skill_mapped("unarmed")=="zhaixin-claw")
                return 0;        
        if (weapon=victim->query_temp("weapon"))
        if (weapon->query("skill_type")=="dagger" && victim->query_skill("dagger",1)>100 
                && victim->query_skill("xinyue-dagger",1)>100
                && victim->query_skill_mapped("dagger")=="xinyue-dagger")
                return 0;*/ 
        if (weapon=victim->query_temp("weapon"))
        if (weapon->query("skill_type")=="blade" && victim->query_skill("blade",1)>100 
                && victim->query_skill("shenji-blade",1)>100
                && victim->query_skill_mapped("blade")=="shenji-blade")
                return 0; 
/*      if (!weapon=victim->query_temp("weapon"))
        if (victim->query_skill("unarmed",1)>100 && victim->query_skill("pofeng-strike",1)>100   
                && victim->query_skill_mapped("unarmed")=="pofeng-strike")
                return 0; 
        if (!weapon=victim->query_temp("weapon"))
        if (victim->query_skill("unarmed",1)>100 && victim->query_skill("tigerstrike",1)>100     
                && victim->query_skill_mapped("unarmed")=="tigerstrike")
                return 0;*/ 
        return 1;
} 
                
int effective_level()
{
        if(this_player()) {
                if(this_player()->query_skill("lingxi-zhi",1)<160)
                        return 150;
                else return 200;
        }
        return 200;     
}    
