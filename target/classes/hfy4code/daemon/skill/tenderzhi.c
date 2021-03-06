 // tenderzhi.c
inherit SKILL;
#include <ansi.h>
void setup(){
        set("name", "柔虹指");
        set("usage/unarmed", 1);
        set("effective_level", 200);
        set("learn_bonus", -100);
        set("practice_bonus", -5);
        set("black_white_ness", 40);
        set("skill_class", "mei");
        
        set("parry_msg", ({
        "$n中指微弹$N$w的尖端，$N手中的$w几乎脱手而出。\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n并起二指，凌空虚点，指风直奔$N的周身大穴。\n",
        }) );   
        action = ({
        ([      "action":               
"$N左手一挥，一招「菊楼采月」右手点向$n$l",
                "dodge":                30,
                "parry":                30,
                "force":                80,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
        ([      "action":               
"$N使一招「雪桥翦梅」，身影忽前忽後，突然一转身左手往$n的$l点去",
                "dodge":                30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "左手食指",
        ]),
        ([      "action":               
"$N身法稍顿，左手一扬使出「柳亭簪花」往$n的$l点去",
                "dodge":                30,
                "parry":                30,
                "force":                140,
                "damage_type":  "刺伤",
                "weapon":               "左手食指",
        ]),
        ([      "action":               
"只见$N纤腰一摆，陡然滑出数尺，右手顺著来势一招「桃坟扑蝶」往$n的$l点去",
                "dodge":                30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
        });
}
int valid_learn(object me)
{
    if((string)me->query("gender") != "女性") {
        return notify_fail("柔虹指是只有女子才能练的武功。\n");
    }
    if((int)me->query("max_force") < 250 ){
        return notify_fail("你的内力不够！\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
        if(!::practice_skill(me)){
                return 0;
        }
        if (me->query_skill("tenderzhi",1)>180)
                return notify_fail("柔虹指极为深奥，再往上得自己慢慢研究才行。\n");
        
    if((int)me->query("force") < 10 ) {
        return notify_fail("你的内力不够了。\n");
        }
    me->add("force", -10);
    return 1;
}

int effective_level()
{
        object me=this_player();
        int skill,n;
         skill=me->query_skill("tenderzhi",1);
        if (skill > 199) return 299;
        if (skill < 200) return 200;
        
                
}  

  
mixed hit_ob(object me, object victim, int damage_bonus)
{
           object my_weapon;
        int badint;
//      my_weapon=me->query_temp("weapon");
        if(damage_bonus < 300 ) return 0;
        if(victim->query_skill_mapped("iron-cloth") == "yijinjing") {
                badint = 3*victim->query_skill("iron-cloth")+random(victim->query_skill("iron-cloth"));
                if(badint) {
                        victim->receive_wound("gin",badint);
                        switch(random(2)) {
                                case 0: return HIW"$N指尖射出丝丝寒气,击破了$n的护体神功！\n"NOR;
                                case 1: return HIW"$n只觉心头一凉,$N的阴寒指力竟透体而入 ．．．\n"NOR;
                        }
                }
        }
        return 0;
}   
