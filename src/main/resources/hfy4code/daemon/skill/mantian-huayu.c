 // mantian-huayu.c
#include <ansi.h>
inherit SKILL; 
void setup(){ 
        set("name", "满天花雨"); 
        set("usage/throwing", 1); 
        set("skill_class", "tang"); 
        set("effective_level", 180); 
        set("practice_bonus", -5); 
         
        action = ({ 
        ([      "action":                
"$N双手一晃，手中的$w如一条银蛇般飞向$n的$l", 
                "dodge":                -20, 
                "damage":               30, 
                "post_action":  "throw_weapon", 
                "damage_type":  "刺伤" 
        ]), 
        ([      "action":                
"$N右手一抖，$w发出刺耳的破空声直射$n的$l", 
                "dodge":                -40, 
                "damage":               30, 
                "post_action":  "throw_weapon", 
                "damage_type":  "刺伤" 
        ]), 
        ([      "action":                
"$N手指微动，$w斜斜的飞向$n的$l", 
                "dodge":                -40, 
                
                "post_action":  "throw_weapon", 
                "damage_type":  "刺伤" 
        ]), 
        ([      "action":                
"$N力发肩肘，右手一甩，手中的$w化作一道弧光射向$n的$l", 
                "dodge":                20, 
                "post_action":  "throw_weapon", 
                "damage":               40, 
                "damage_type":  "刺伤" 
        ]), 
        ([      "action":                
"$N力由心生，左手上扬，指间的$w瞬间不见踪影，却又忽然从另一角度折射袭至$n的$l", 
                "dodge":                20, 
                "post_action":  "throw_weapon", 
                "damage":               40, 
                "damage_type":  "刺伤" 
        ]), 
        }); 
} 
int valid_learn(object me) 
{ 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
    if( (int)me->query_skill("dujing-force") < 100 ){ 
        return notify_fail("你的毒经心法不够，没有办法修练满天花雨。\n"); 
        } 
    return 1; 
} 
 
int practice_skill(object me) 
{ 
 
        if((int)me->query("force") < 3 ){ 
                return notify_fail("你的内力或气不够，没有办法练习暗器。\n"); 
    } 
    if(!::practice_skill(me)){ 
        return 0; 
    } 
    me->add("force", -3); 
        write("你按著所学练了一遍满天花雨。\n"); 
    return 1; 
} 
mixed hit_ob(object me,object victim)
{
	int dam;
	dam = me->query("max_sen");
	if (me->query_temp("SUPERER")) {
                victim->receive_wound("gin", dam/2 +  random(dam/5), me);
				return (HIR"暗器散发出一阵甜香，骇然是泡了天下奇毒鹤顶红！\n"NOR);
	}
	else if( random(me->query_skill("dujing-force", 1)) > 200 ) {
                victim->receive_damage("sen", dam/10 +  random(dam/20), me);
				return (HIB"暗器上一阵腥臭，显然是下了剧毒。\n"NOR);
	}
	else
       return (""); 
}   
