 // mysterrier.c
inherit SKILL;
void setup() {
        set("name", "步玄七诀");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("practice_damage", 20);     
        set("skill_class", "scholar");
        set("effective_level", 200);
        set("learn_bonus", 50);
        set("practice_bonus", 20);
        set("black_white_ness", 20);
        set("dodge_msg", ({
        "$n身影一转，轻易地避开了这一招。\n",
        "$n身法飘忽，左一点，右一顿，早已闪在一旁。\n",
        "但是$n身影一侧，在间不容发之际从容地避开了这一招。\n",
        "$n身形陡然拔高，使$N的攻势尽数落空。\n",
        "$n右足一点，身影向左滑开数尺，避了开去。\n",
        }) );
} 
int valid_learn(object me)
{
    if( me->query_skill_mapped("force") != "mystforce" ) {
        return notify_fail("步玄七诀必须配合步玄心法使用。\n");
        }
    return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("sen") < 20 ){
                return notify_fail("你的气或神不够，不能练步玄七诀。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->receive_damage("sen", 20);
        return 1;
}     
