 // alchemy.c
inherit SKILL; 
void setup() {
        set("name", "炼丹术");
        set("effective_level", 150);
        set("learn_bonus", -10);
        set("practice_bonus", -5);
        set("black_white_ness", 0);
        set("usage/magic", 1);
        set("skill_class", "taoist");
} 
int valid_learn(object me)
{
        if( (int)me->query_skill("taoism",1) < 10
        ||      (int)me->query_skill("taoism",1) <= (int)me->query_skill("alchemy",1) )
                return notify_fail("你的天师正道修为还不够高深，无法学习炼丹术。\n");
        return 1;
} 
int practice_skill(object me)
{
        
        if ((int)me->query("atman") < 10) {
                return notify_fail("你的内力不够练炼丹术。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("atman", -5);
        return 1;
}  
