 inherit SKILL;
void setup() {
        set("name", "�����廨��");
        set("usage/herb", 1);
        set("learn_bonus", 30);
        set("practice_bonus", -5);
        set("skill_class", "knight");
        set("black_white_ness", -50);
} 
int valid_learn(object me)
{
        if((int)me->query_skill("force", 1) < 100) {
                return notify_fail("����ڹ��ķ�����㣬�޷�����ԩ��������\n");
        }
        return 1;
}  
