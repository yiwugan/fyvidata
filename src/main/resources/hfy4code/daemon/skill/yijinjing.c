 //mimicat@fy4
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "易筋经");
        set("bounce_ratio",             35); 
        set("learn_bonus",              -900);
        set("black_white_ness",         20);
        set("effective_level",          200);
        set("usage/force",              1);
        set("usage/iron-cloth",         1);
        set("usage/unarmed",            1);
        set("skill_class",                      "shaolin");
        
                
        
        set("absorb_msg",                       ({
                        "眼看$N招式迅急，$n反而向前迎了一步，一圈气墙应念而生将$N挡开。\n",
                        "$n双手合十，瞑目静气，一波内劲透体而出将$N挡了回去。\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "眼看$N招式迅急，$n反而向前迎了一步，一圈气墙应念而生将$N挡开。\n",
                        "$n双手合十，瞑目静气，一波内劲透体而出将$N挡了回去。\n",
                        })
        ); 
        action = ({
                        ([      "action":
                        "$N单掌一按，平和的掌力如春风涨绿，击向$n$l",
                                "parry":                500,
                                "force":                300,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":
                        "$N展袖一挥，便似有一股力道化成一堵无形高墙压向$n",
                                "parry":                200,
                                "force":                140,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":
                   "$N一掌轻轻拍落，看似寻常，却不知为何挡无可挡，避无可避",
                                "parry":                500,
                                "dodge":                1000,
                                "force":                360,
                                "damage_type":  "瘀伤"
                        ]),
        });
} 
int valid_learn(object me) {
        if((string)me->query("class") != "shaolin" ) {
                return notify_fail("易筋经是只有少林高僧才能练的武功。\n");
        }       
        if( (int)me->query_skill("zen",1) < (int)me->query_skill("yijinjing",1))
                return notify_fail("你的禅道修为不够，无法领悟更高深的易筋经。\n");
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("max_force") < 350) {
                return notify_fail("你的内力不够！\n");
        }
        return 1;
} 
int practice_skill(object me)
{
	     if (me->query("once_xman")==1) return 0;
        else {return notify_fail("易筋经只能通过学习来提高。\n");}
                
}     

int effective_level()
{
        object me=this_player();
        
        if (me->query("once_xman")==1) return 330;
        
        if (me->query_temp("SUPERER")) return 500;
        
        else {return 200;}
        
        
                
} 