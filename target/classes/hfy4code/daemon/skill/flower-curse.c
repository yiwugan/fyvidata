 inherit SKILL;
void setup() {
        set("name", "云梦五花锦");
        set("usage/herb", 1);
        set("learn_bonus", 30);
        set("practice_bonus", -5);
        set("skill_class", "knight");
        set("black_white_ness", -50);
} 
int valid_learn(object me)
{
        if((int)me->query_skill("force", 1) < 100) {
                return notify_fail("你的内功心法火候不足，无法练非冤布毒术。\n");
        }
        return 1;
}  
