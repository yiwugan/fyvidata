 // jin-gang.c
inherit SKILL;
void setup() {
        set("name", "金刚不坏功");
        set("usage/iron-cloth", 1);
        set("effective_level", 200);
        set("bounce_ratio", 35);
        set("learn_bonus", -10);
        set("practice_bonus", -5);
        set("black_white_ness", 20);
        set("skill_class", "lama");
        set("absorb_msg", ({
        "$n双臂一震，金刚不坏功力决堤似的澎湃而出。\n",
        "$n施展出金刚不坏功中的「弹」字诀，一股弹力传入$N的体内。\n",
        "$n使出一招「苦海无涯」，凝虚为实，浑身硬如金刚。\n",
        "$n施展出金刚不坏功，对抗$N的一击之力。\n",
        }) );
}  
int valid_learn(object me)
{
        if( (int)me->query_skill("lamaism",1) <= (int)me->query_skill("jin-gang",1)) {
                return notify_fail("你的密宗佛法修为不够，无法领悟更高深的金刚不坏功。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("jin-gang",1) > 49)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");
        return ::practice_skill(me);
        
        
}    
