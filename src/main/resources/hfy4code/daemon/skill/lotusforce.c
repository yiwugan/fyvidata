 // lotusforce.c
inherit SKILL;
void setup() {
        set("name", "莲华心法");
        set("usage/force", 1);
        set("skill_class", "bonze");    
        set("effective_level", 130);
        set("learn_bonus", -30);
        set("practice_bonus", -15);
        set("black_white_ness", 60);
} 
int valid_learn(object me)
{
if((int)me->query_skill("buddhism") < (int)me->query_skill("lotusforce")){
                return notify_fail("你的大乘佛法修为不够，无法领会更高深的莲华心法。\n");
        }
        return 1;
}      
