 //sfy@fy4
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "玄心奥妙决");
        set("bounce_ratio",             25); 
        set("learn_bonus",              -800);
        set("black_white_ness",         20);
        set("effective_level",          195);
        set("usage/force",              1);
        set("usage/iron-cloth",         1);
		set("usage/spells",				1);
        set("skill_class",                      "mei");
        set("absorb_msg",                       ({
                        "$n暗运神功，全身光芒暴涨，将$N的攻击消于无形。\n",
                        "$n玄心妙悟间，光芒应念而生，将$N挡了回去。\n",
                        "$N的招式甫及身体，却被$n的奇术弹了回去。\n",
                        })
        );
}
int valid_learn(object me) {
        if(me->query("class") != "mei" || me->query("gender")!="女性") {
                return notify_fail("玄心奥妙决只有松谷庵的女尼才能修练。\n");
        }       
        
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
        return notify_fail("玄心奥妙决只能通过学习来提高。\n");
                
}     
void skill_improved(object me)
{
    int s;
    s = me->query_skill("xuanxinjue", 1);
       if (s== 150 && me->query("class")=="mei") {
   
       me->set("once_menpai/mei",1);
       } 
}  