 // TIE@FY3
inherit SKILL;
void setup() {
        set("name", "乾坤无形");
        set("usage/magic", 1);
        set("skill_class", "lishi");
        set("learn_bonus", -10);
        set("practice_bonus", -5);
        set("black_white_ness", 10);
}
/*int valid_learn(object me)
{
        if( (int)me->query_skill("putiforce",1) < 10
        ||      (int)me->query_skill("putiforce",1) <= (int)me->query_skill("qiankunwuxing",1) )
                return notify_fail("你的菩堤心法还不够高深，无法学习乾坤无形。\n");
        return 1;
}*/ 
int practice_skill(object me)
{
        return notify_fail("乾坤无形只能用学的\n");
}  
