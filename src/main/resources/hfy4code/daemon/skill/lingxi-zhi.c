 inherit SKILL;
//original design by mimicat
#include <ansi.h>
int check_skill(object victim) ;  
void setup() {
        set("name",             "灵犀指");
        set("effective_level",  200);
        set("learn_bonus",      -800);
        set("practice_bonus",   -100);
        set("black_white_ness", 0);
        set("skill_class",      "task_npc");
        set("usage/unarmed",    1);
        
        set("parry_msg",                        ({
        "$n右手在$N的手腕上轻轻一拂，$N只觉一麻，便再也使不出力道来。\n",
                "$n左手在$N的手腕上轻轻一拂，$N只觉一麻，便再也使不出力道来。\n"
        })      );
        set("unarmed_parry_msg",                ({
         "$n右手在$N的手腕上轻轻一拂，$N只觉一麻，便再也使不出力道来。\n",
                "$n左手在$N的手腕上轻轻一拂，$N只觉一麻，便再也使不出力道来。\n"
        })      );
        action = ({
([      "action" : "$N左指挥出，一式「昨夜长风」，削向$n的掌缘",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "昨夜长风",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N全身之力聚于一指，一式「天似无情」，指向$n的胸前",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "天似无情",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左掌贴于神道穴，右手一式「情根深种」，向$n的$l划过",
        "force" : 180,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "情根深种",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双目怒视，一式「情在天涯」，双指拂向$n的额、颈、肩、臂、胸、背",
        "force" : 220,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "情在天涯",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式「独饮情伤」，左掌掌心向外，右指蓄势点向$n的$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "独饮情伤",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N右手伸出，十指叉开，一式「无诉别情」，小指拂向$n的太渊穴",
        "force" : 330,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "无诉别情",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双迸出无数道劲气，一式「情意绵绵」射向$n的全身",
        "force" : 400,
        "dodge" : 25,
        "damage": 120,
        "lvl" : 80,
        "skill_name" : "情意绵绵",
        "damage_type" : "瘀伤"
]),
}); 
} 
int valid_learn(object me)
{  
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练灵犀指法必须空手。\n");
        return 1;
}   
mixed parry_ob(object victim,object me)
{
        int myexp,hisexp,mylvl,extra, n;
        int alr_busy_time;
        object weapon;
        string msg;
        
        
        if (victim->query("race")=="野兽") return 0;
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
                        msg=HIY"$n"+HIY"忽然伸出食中两指，将$N"+HIY"的兵刃夹住！！\n"NOR;
                else 
                        msg=HIY"$n"+HIY"忽然伸出食中两指，将$N"+HIY"的出招夹住！！\n"NOR;
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
                        return HIW"结果$N被$n的反击攻了个手忙脚乱。\n"NOR;
                }
        }
        
        if (random(3*myexp+hisexp)>hisexp && !userp(me))
        {
                alr_busy_time=victim->query_busy();
                if(!alr_busy_time) victim->start_busy(2);
                return HIW"结果$N被$n的反击攻了一个手忙脚乱。\n"NOR;
        }  
}  
int practice_skill(object me)
{
        return notify_fail("灵犀指法只能学的。\n");
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
