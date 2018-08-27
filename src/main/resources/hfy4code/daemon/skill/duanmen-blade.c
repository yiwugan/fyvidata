#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "五虎断门刀");
        set("usage/blade", 1);
        set("usage/parry", 1);
        set("effective_level", 250);
        set("practice_bonus", -5);
        set("black_white_ness", -20);
        set("skill_class", "new");
        set("parry_msg", ({
        "$n大喝一声，手中$v凌空劈出，强烈的刀风逼得$N连退数步。\n",
        "$n手中的$v在空中幻出无数刀影，$N看不清虚实，只好退后三步，转攻为守。\n",
        "$n紧闭双眼，$v如有灵性般直往$N拿$w的手臂砍去，吓得$N不住倒退。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n手中的$v大开大阖，刀风把$N的招式尽数封住。\n",
        "$n随手一刀，竟恰好把$N进招的路线封死，令其知难而退。\n",
        }) );   
        action = ({
                ([      "action":               
                "$N手中的$w一招「刀绝」，刀锋化作一道光华劈向$n的$l",
                        "parry":                260,
                        "damage":               200,
                        "damage_type":  "劈伤"
                ]),
                ([      "action":               
                "$N使出一招「情绝」，$w如附骨之蛆般缠紧$n的$l",
                	"parry":                380,
                        "damage":               100,
                        "damage_type":  "割伤"
                ]),
                ([      "action":               
                "$N踏步向前，一招「人绝」，$w直斩向$n的$l",
                        "parry":                160,
                        "damage":               210,
                        "damage_type":  "砍伤"
                ]),
                ([      "action":               
               "$N晃动手中的$w，一招「命绝」，刀锋在空中敛而合一，直往$n的要害割去",
                        "parry":                280,
                        "damage":               620,
                        "damage_type":  "割伤"
                ]),
        });
}

int practice_skill(object me)
{
        if (me->query_skill("duanmen-blade",1) > 100)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");       
        if ((int)me->query("force") < 20) {
                return notify_fail("你的内力不够练习。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}   
