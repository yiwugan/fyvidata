 // modified by mimicat@fy4
// qidaoforce.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "棋道");
        set("usage/force", 1);  
        set("skill_class", "legend");
        set("effective_level", 150);
        set("learn_bonus", -50);
        set("practice_bonus", -50);
        set("black_white_ness", 30);
        set("parry_msg",  ({
        "$n运起真气，挡住了$N的攻势。\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n运起真气，挡住了$N的攻势。\n",
        }) );
        action = ({
        ([      "action":
"$N使出一招「镇神头」，左手聚出一团真气，从上而下，击向$n的$l",
                "force":                150,
                "damage":               200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「大斜」，右手聚出一团真气，斜斜击向$n的$l",
                "force":                150,
                "damage":               250,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「双飞燕」，双手聚出一团真气，左右同时击向$n的$l",
                "force":                300,
                "damage":               300,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「倒垂莲」，全身腾空而起，运起全身的真气击向$n的$l",
                "force":                400,
                "damage":          400,
                "damage_type":  "瘀伤"
        ]),
        });
}
int valid_enable(string usage) 
{ 
        object me;
        
        
        me=this_player();
        if(me->query_skill("qidaoforce",1)>70){
                return usage=="unarmed"||usage=="force"; 
        }
        else
                return usage=="force";
}  
mixed hit_ob(object me,object victim)
{
        int extra, dream;
        string message="";
        extra = me->query_temp("qidaoforce_juqi");
        dream = me->query_skill("six-sense",1)/2 + 400 * victim->query("resistance/kee")/100;   
//      write("dream is "+(string)(dream)+"\n");
//      write("extra is " +(string)(extra)+"\n");
        if( extra > 0) {
                victim->receive_damage("kee",extra/2,me);
                victim->add("kee",-extra/2);
        }
        if( me->query_temp("qidaoforce_diemeng") && me->query_skill("six-sense",1)>=180) {
                victim->receive_damage("kee",dream/2, me);
                victim->add("kee",-dream/2);
        }
        if (extra || me->query_temp("qidaoforce_diemeng"))
        if (me->query("family/master_id")=="master xuerui")
                        message_vision(WHT"\n$N身侧的玉色光芒忽如蝶翼般片片飞向$n，$n"+WHT"只觉经脉中一阵灼痛。\n"NOR,me, victim);
                else 
                        message_vision(HIC"\n$N将内力凝为一线，攻入$n"+HIC"的体内。\n"NOR, me, victim);
        return;
}     
