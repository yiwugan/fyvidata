 // yinhua-sword.c 樱花剑道
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "樱花剑道");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("effective_level", 260);
        set("black_white_ness", -10);
        set("skill_class", "bat");
        set("parry_msg", ({
        "$n随风轻轻飘落，手中$v平指，缓缓拍向$N脸颊，\n",
                "$n随意挥洒， 轻而易举的架住了$N的$w。\n",
                "$n深吸一口气，手中的$v化作千百剑芒，护住了全身。\n",
                "$n手中的$v急剧抖动，封住了$N的所有攻势。\n",
        }) );   
        action = ({
                ([      "action":               
                "$N手中$w嗡嗡微振，幻成一条白光刺向$n的$l",
                        "dodge":                -200,
                        "parry" :               -200,
                        "damage":               70,
                        "force" :               200,
                        "damage_type":  "刺伤"
                ]),
                ([      "action":               
                "$N纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
                        "dodge":                -200,
                        "parry" :               -200,
                        "damage":               50,
                        "force" :               100,
                        "damage_type":  "刺伤"
                ]),
                ([      "action":               
                "$N纵身轻轻跃起，$w光芒如水，一泻千里，洒向$n的$l",
                        "dodge":                -200,
                        "parry" :               -300,
                        "damage":               150,
                        "force" :               250,
                        "damage_type":  "刺伤"
           ]),
                ([      "action":               
                "$N手中$w斜指苍天，剑芒吞吐，，对准$n的$l斜斜击出",
                        "dodge":                -100,
                        "parry" :               -100,
                        "damage":               50,
                        "force" :               150,
                        "damage_type":  "刺伤"
                ]),
                ([      "action":               
                "$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，刺向$n的$l",
                        "dodge":                -250,
                        "parry" :               -250,
                        "damage":               90,
                        "force" :               220,
                        "damage_type":  "刺伤"
                ]),
                ([      "action":               
                "$N合掌跌坐，$w自怀中跃出，如疾电般射向$n的$l",
                        "dodge":                -20,
                        "damage":               50,
                        "damage_type":  "刺伤"
                ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
        if( (int)me->query("max_force") < 100 ){
                return notify_fail("你的内力不够，没有办法练樱花剑道。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ){
                return notify_fail("你的内力或气不够，没有办法练习樱花剑道。\n");
        }
   if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        write("你按著所学练了一遍樱花剑道。\n");
        return 1;
}  
