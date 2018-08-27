 // celestial.c
inherit SKILL; 
void setup() {
        set("name",                             "天邪神功");
        set("black_white_ness",         -50);
        set("usage/force",                      1);
        set("effective_level",  500);
        set("skill_class",                      "new");
}  
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("bellicosity") < (int)me->query_skill("celestial") * 50) {
                return notify_fail("你的杀气不够，无法领悟更高深的天邪神功。\n");
        }
        return 1;
}    
